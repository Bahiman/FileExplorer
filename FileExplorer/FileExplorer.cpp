#include "FileExplorer.h"
#include <QDesktopServices>
#include <iostream>
#include <set>
#include<future>
#include <QTreeView>
#include<qurl.h>
#include"File.h"
#include"Directory.h"
#include <QTreeView>
#include <Windows.h>
#include <QFileSystemModel>
#include"FileListModel.h"
#include <QDebug>


FileExplorer::FileExplorer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setUi();
    setConnects();
}

FileExplorer::~FileExplorer()
{

}

void FileExplorer::getFiles(const std::filesystem::path& path)
{
    m_nodes.clear();
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        QFileInfo fileInfo(entry.path());
        if (fileInfo.isHidden())
            continue;
        if (entry.is_directory())
        {
			m_nodes.emplace_back(std::make_unique<Directory>(entry));
		}
        else
        {
			m_nodes.emplace_back(std::make_unique<File>(entry));
		}
	}
}

void FileExplorer::updateUi()
{
    model->clear();
    for (const auto& node : m_nodes)
    {
		model->addData(*node);
	}
    // 
    model->dataChanged(QModelIndex(), QModelIndex());
    ui.listView->show();
}

void FileExplorer::setUi()
{
    namespace fs = std::filesystem;
    model = new FileListModel(this);
    for (const auto& entry : fs::directory_iterator("/")) {
        QFileInfo fileInfo(entry.path());
        if (fileInfo.isHidden())
            continue;
        model->addData(FileSystemNode(entry.path()));
    }
    ui.listView->setModel(model);
}

void FileExplorer::setConnects()
{
    connect(ui.listView, &QListView::doubleClicked, this, &FileExplorer::onDoubleClicked);
    connect(ui.pushButton, &QPushButton::clicked, this, &FileExplorer::onBackClicked);
}

void FileExplorer::onBackClicked()
{
    // m/p/z
    m_cur_path = m_cur_path.parent_path();
    getFiles(m_cur_path);
    updateUi();
}

void FileExplorer::onDoubleClicked(const QModelIndex& index)
{
    QVariant itemData = ui.listView->model()->data(index, Qt::DisplayRole);
    auto itemString = '/' + itemData.toString().toStdString();
    m_cur_path = std::move(itemString);
    if (std::filesystem::is_directory(m_cur_path))
    {
		m_nodes.clear();
		getFiles(m_cur_path);
		updateUi();
	}
    else
    {
        QUrl fileUrl = QUrl::fromLocalFile(QString::fromStdString(m_cur_path.string()));
        QDesktopServices::openUrl(fileUrl);
    }
}
