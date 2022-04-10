#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //pre-load the bg_pic in the constructor
    bg_pic = QPixmap(":/cover/res/cover_pic.jpg");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), bg_pic);
}

void MainWindow::on_actionNew_Profile_triggered(bool checked)
{
    // TODO: react to add a new profile for users
}

void MainWindow::on_actionLoad_Profile_triggered(bool checked)
{
    // TODO: react to load profile for users
}

