#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent* event);

private slots:
    // override
    //checked parameter is only useful for checkable QAction
    void on_actionNew_Profile_triggered(bool checked = false);
    void on_actionLoad_Profile_triggered(bool checked = false);

private:
    Ui::MainWindow *ui;
    QPixmap bg_pic;
};
#endif // MAINWINDOW_H
