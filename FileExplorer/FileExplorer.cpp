#include "FileExplorer.h"
#include <iostream>
#include"File.h"

FileExplorer::FileExplorer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setUi();
    setConnects();
}

FileExplorer::~FileExplorer()
{}

void FileExplorer::setUi()
{
    try
    {
        for (auto& k : file::getDirectoriesDirectories("C:/dev/ImGui/imgui/backends"))
        {
            std::cout << k << "\n";
        }
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << " :(";
    }
}

void FileExplorer::setConnects()
{
    
}
