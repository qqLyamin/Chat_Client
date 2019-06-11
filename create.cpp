#include "create.h"
#include "ui_create.h"

Create_chat::Create_chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_chat)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);//память чистится после закрытия
    connect(ui->CreateChatButton, &QPushButton::clicked, this, &Create_chat::chatname_and_password_creating);
    connect(ui->BackButton, &QPushButton::clicked, this, &Create_chat::back);
}

Create_chat::~Create_chat()
{
    delete ui;
}

void Create_chat::chatname_and_password_creating()
{
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::about(this, "error", "input your options");
    }
    else
    {
        emit create_chatroom(ui->lineEdit->text(), ui->lineEdit_2->text());
    }
}

//void Create_chat::create_chatroom()
//{
//    std::thread th([this](){my_chatroom = new Chatroom(this);
//    my_chatroom->setModal(true);
//    my_chatroom->show();
//    /*my_chatroom->listen()*/;});
//    th.detach();
//}
