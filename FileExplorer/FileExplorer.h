#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FileExplorer.h"
#include<algorithm/is_palindrome.hpp>

class FileExplorer : public QMainWindow
{
    Q_OBJECT

public:
    FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer();
private:
    bool a = boost::algorithm::is_palindrome("Bahram");
    Ui::FileExplorerClass ui;
    void setUi();
    void setConnects();
};
