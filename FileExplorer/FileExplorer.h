#pragma once

#include <QtWidgets/QMainWindow>
#include"File.h"
#include"Directory.h"
#include "ui_FileExplorer.h"
#include<qline.h>
#include<qpushbutton.h>
#include "FileListModel.h"



class FileExplorer : public QMainWindow
{
    Q_OBJECT
public:
    FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer();
private:
    Ui::FileExplorerClass ui;
    std::vector<std::unique_ptr<FileSystemNode>> m_nodes;
    FileListModel* model;
    void setSearchbar();
    void setView();
    void getFiles(const std::filesystem::path& path);
    void updateUi();
    void setUi();
    void setConnects();
    void onBackClicked();
    std::filesystem::path m_cur_path;
    void onDoubleClicked(const QModelIndex& index);
};
