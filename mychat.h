#ifndef MYCHAT_H
#define MYCHAT_H

#include <QMainWindow>
#include <QDebug>

#include <QSqlError>
#include <QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QStyle>

#include "signin_signup.h"
//#include "../Server/client.h"
#include "create_connect.h"
#include "create.h"
#include "connect.h"
#include "chatroom.h"
#include "client.h"

namespace Ui {
class myChat;
}

class myChat : public QMainWindow
{
    Q_OBJECT
    signin_signup * si_su;
    create_connect * cre_con;

    Create_chat * create_chat;
    connect2_chat * connect_chat;

    Chatroom * chatroom;

    Client * client;

public:
    explicit myChat(QWidget *parent = nullptr);
    ~myChat();
    void open_sisu_dialog();
    void open_crecon_dialog();
    void open_createchat_dialog();
    void open_connectchat_dialog();
    void open_chatroom_dialog();

public slots:
    void open_sisu();
    void hostback();
    void open_new_dialog(const QString &);

    void confirm_accepted();
    void confirm_denied();

    void host_chat();
    void guest_chat();

    void connect_chat_accepted();
    void connect_chat_denied();

    void create_chat_accepted();
    void create_chat_denied();
signals:
    void connect_to_server();
private:
    Ui::myChat *ui;
};

#endif // MYCHAT_H
