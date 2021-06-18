#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* 设置位置与大小 */
    this->setGeometry(0, 0, 800, 480);

    /* 实例化及设置位置与大小，下同 */
    fWidget = new QWidget(this);
    fWidget->setGeometry(250, 100, 300, 200);

    userLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();

    formLayout = new QFormLayout();

    /* 添加行 */
    formLayout->addRow("用户名：", userLineEdit);
    formLayout->addRow("密码    ：", passwordLineEdit);

    /* 设置水平垂直间距 */
    formLayout->setSpacing(10);

    /* 设置布局外框的宽度 */
    formLayout->setMargin(20);

    /* 将formLayout布局到fWidget */
    fWidget->setLayout(formLayout);

    keyboad = new QQuickWidget(this);
    keyboad->setResizeMode(QQuickWidget::SizeRootObjectToView);
    keyboad->setSource(QUrl("qrc:/keyboard.qml"));
    keyboad->setFixedSize(this->width(), this->height() / 2 + 77);
    keyboad->move(0, this->height()- keyboad->height());

    this->setInputMethodHints(inputMethodHints() | Qt::InputMethodHint::ImhDigitsOnly);
    this->setAttribute(Qt::WA_InputMethodEnabled, true);
}

MainWindow::~MainWindow()
{
}

