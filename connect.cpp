#include "connect.h"
#include "ui_connect.h"

connect2_chat::connect2_chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connect2_chat)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);//память чистится после закрытия
    connect(ui->ConnectChatButton, &QPushButton::clicked, this, &connect2_chat::chatname_and_password);
    connect(ui->BackButton, &QPushButton::clicked, this, &connect2_chat::back);
}

connect2_chat::~connect2_chat()
{
    delete ui;
}

void connect2_chat::chatname_and_password()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::about(this, "error", "input your options");
    }
    else
    {
        emit connect_2chatroom(ui->lineEdit->text(), ui->lineEdit_2->text());
    }
}
