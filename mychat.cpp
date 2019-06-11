#include "mychat.h"
#include "ui_mychat.h"

myChat::myChat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myChat)
{
    si_su = Q_NULLPTR;
    cre_con = Q_NULLPTR;
    create_chat = Q_NULLPTR;
    connect_chat = Q_NULLPTR;
    chatroom = Q_NULLPTR;

    ui->setupUi(this);
    client = new Client();
    connect(this, &myChat::connect_to_server, client, &Client::ConnectToServer);
    connect(client, &Client::go_toServer, client, &Client::Confirm);
    connect(client, &Client::resendMessage, client, &Client::SendMessage);
    emit connect_to_server();

    connect(client, &Client::ConfirmAccepted, this, &myChat::confirm_accepted);
    connect(client, &Client::ConfirmDenied, this, &myChat::confirm_denied);

    connect(client, &Client::Accept_chat_connecting, this, &myChat::connect_chat_accepted);
    connect(client, &Client::Deni_chat_connecting, this, &myChat::connect_chat_denied);

    connect(client, &Client::CreateAccepted, this, &myChat::create_chat_accepted);
    connect(client, &Client::CreateDenied, this, &myChat::create_chat_denied);
    open_sisu_dialog();
}

myChat::~myChat()
{
    delete ui;
}

void myChat::open_sisu_dialog()
{
    si_su = new signin_signup(this);
    si_su->setAttribute(Qt::WA_DeleteOnClose);

    connect(client, &Client::imconnected_to_sisu, si_su, &signin_signup::im_connected);
    connect(si_su, &signin_signup::confirm_entrance, client, &Client::Connect);
    connect(si_su, &signin_signup::new_user, client, &Client::Registre_new_client);
    connect(si_su, &signin_signup::reg_form_closed, client, &Client::reg_form_was_closed);
    si_su->exec();
}

void myChat::open_crecon_dialog()
{
    cre_con = new create_connect(this);
    cre_con->setAttribute(Qt::WA_DeleteOnClose);
    connect(cre_con, &create_connect::host, this, &myChat::host_chat);
    connect(cre_con, &create_connect::guest, this, &myChat::guest_chat);
    cre_con->exec();
}

void myChat::open_createchat_dialog()
{
    create_chat = new Create_chat(this);
    connect(create_chat, &Create_chat::back, this, &myChat::hostback);
    create_chat->setAttribute(Qt::WA_DeleteOnClose);
    create_chat->exec();
}

void myChat::open_connectchat_dialog()
{
    connect_chat = new connect2_chat(this);
    connect_chat->setAttribute(Qt::WA_DeleteOnClose);
    connect(connect_chat, &connect2_chat::back, this, &myChat::hostback);
    connect_chat->exec();
}

void myChat::open_chatroom_dialog()
{
    chatroom = new Chatroom(this);
    chatroom->setAttribute(Qt::WA_DeleteOnClose);
    chatroom->exec();
}

void myChat::open_sisu()
{
    open_sisu_dialog();
}


void myChat::open_new_dialog(const QString & dialog_name)
{

    if (si_su != Q_NULLPTR)
    {
        si_su->close();
        si_su = Q_NULLPTR;
    }

    if (cre_con != Q_NULLPTR)
    {
        cre_con->close();
        cre_con = Q_NULLPTR;
    }

    if (create_chat != Q_NULLPTR)
    {
        create_chat->close();
        create_chat = Q_NULLPTR;
    }

    if (connect_chat != Q_NULLPTR)
    {
        connect_chat->close();
        connect_chat = Q_NULLPTR;
    }

    if (chatroom != Q_NULLPTR)
    {
        chatroom->close();
        chatroom = Q_NULLPTR;
    }

    if (dialog_name == "si_su")
    {
        open_sisu_dialog();
    }

    if (dialog_name == "cre_con")
    {
        open_crecon_dialog();
    }

    if (dialog_name == "create_chat")
    {
        open_createchat_dialog();
    }

    if (dialog_name == "connect_chat")
    {
        open_connectchat_dialog();
    }

    if (dialog_name == "chatroom")
    {
        open_chatroom_dialog();
    }
}

void myChat::hostback()
{
    open_new_dialog("cre_con");
}

void myChat::confirm_accepted()
{
    open_new_dialog("cre_con");
}

void myChat::confirm_denied()
{
    QMessageBox::about(this, "error", "confirm_denied");
}

void myChat::host_chat()
{
    open_new_dialog("create_chat");
}

void myChat::guest_chat()
{
    open_new_dialog("connect_chat");
}

void myChat::connect_chat_accepted()
{
    open_new_dialog("chatroom");
}

void myChat::connect_chat_denied()
{
    QMessageBox::about(this, "error", "host chat denied");
}

void myChat::create_chat_accepted()
{
    open_new_dialog("chatroom");
}

void myChat::create_chat_denied()
{
    QMessageBox::about(this, "error", "connect to chat denied");
}
