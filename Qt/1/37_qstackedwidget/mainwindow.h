#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* widget小部件 */
    QWidget *widget;
    /* 水平布局 */
    QHBoxLayout *hBoxLayout;
    /* 列表视图 */
    QListWidget *listWidget;
    /* 堆栈窗口部件 */
    QStackedWidget *stackedWidget;
    /* 3个标签 */
    QLabel *label[3];

};
#endif // MAINWINDOW_H
