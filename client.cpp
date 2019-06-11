#include "client.h"

Client::Client()
{
    socket = Q_NULLPTR;
}

Client::~Client()
{
    socket->deleteLater();
}

void Client::SetSocket(QTcpSocket * S)
{
    socket = S;
    connect(socket, &QTcpSocket::stateChanged, this, &Client::SocketStateChanged);//послал в myChat
}

void Client::SocketStateChanged(QAbstractSocket::SocketState State)
{
    qDebug() << QAbstractSocket::SocketState();
    switch (State) {
        case QAbstractSocket::ConnectedState:
            qDebug() << "Connected";
        break;

        case QAbstractSocket::UnconnectedState:
            qDebug() << "No Connection";
            emit Disconnected();
        break;
    default: break;
    }
}

void Client::reg_form_was_closed()
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::Confirm);
}

void Client::Connect(const QString & income_name, const QString & income_password)
{
    name = income_name;
    password = income_password;
    ConnectToServer();
    qDebug() << "void Client::Connect";
}

void Client::ConnectToServer()
{
    if (socket == Q_NULLPTR)
    {
        QTcpSocket * tmp = new QTcpSocket;
        SetSocket(tmp);
    }

    if (connection_counter == 0)
    {
        connection_counter++;
        socket->connectToHost("127.0.0.1", 33333);
        connect(socket, &QTcpSocket::readyRead, this, &Client::Confirm);
    }
    else
    {
        qDebug() << "got to server";
        emit go_toServer();
    }
    qDebug() << "void Client::Connect";
}

void Client::Confirm()
{
    qDebug() << "void Client::Confirm()";
    qDebug() << socket->readAll();
    if (connection_counter == 1 || socket->readAll() == "connected:ok")
    {
        if (counter == 0)
        {
            emit imconnected_to_sisu();
            counter++;
        }
        else
        {
            disconnect(socket, &QTcpSocket::readyRead, this, &Client::Confirm);
            connect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_connectuser);
            QString msg = "check_user:" + name + "*" + password;
            SendMessage(msg);
        }
    }
}

void Client::Registre_new_client(const QString & name, const QString & password, const QString & email)
{
    if (connection_counter == 1 || socket->readAll() == "connected:ok")
    {
        qDebug() << "Client::Registre New Client";
        connect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_registration);
        disconnect(socket, &QTcpSocket::readyRead, this, &Client::Confirm);
        QString msg = "registrate:" + name + "*" + password + "~" + email;
        SendMessage(msg);
    }
}

void Client::AcceptConfirm_registration()
{
    if (QString(socket->readAll()) == "registrate:ok")
    {
        disconnect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_registration);
        emit ConfirmAccepted();
    }
    else if (QString(socket->readAll()) == "registrate:nope")
    {
        qDebug() << "reg nope thats all";
    }
}

void Client::ReadMessage()
{
    emit Show(QString(socket->readAll()));
}

void Client::ConfirmChatnameAndPassword_connect(const QString & chatname, const QString & chatpassword)
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_Connectchat);
    QString msg = "check_connecting:" + chatname + "*" + chatpassword;
}

void Client::ConfirmChatnameCreated(const QString & chatname, const QString & chatpassword)
{
    connect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_Createchat);
    QString msg = "check_creating:" + chatname + "*" + chatpassword;
}

void Client::AcceptConfirm_Connectchat()
{
    if (QString(socket->readAll()) == "check_connecting:ok")
    {
        disconnect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_Connectchat);
        emit Accept_chat_connecting();
    }
    else if (QString(socket->readAll()) == "check_connecting:nope")
    {
        socket->close();
        emit Deni_chat_connecting();
    }
}

void Client::AcceptConfirm_Createchat()
{
    if (QString(socket->readAll()) == "check_creating:ok")
    {
        disconnect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_Createchat);
        emit CreateAccepted();
    }
    else if (QString(socket->readAll()) == "check_creating:nope")
    {
        socket->close();
        emit CreateDenied();
    }
}

void Client::AcceptConfirm_connectuser()
{
    if (QString(socket->readAll()) == "check:ok")
    {
        disconnect(socket, &QTcpSocket::readyRead, this, &Client::AcceptConfirm_connectuser);
        emit ConfirmAccepted();
    }
    else if (QString(socket->readAll()) == "check:nope")
    {
        socket->close();
        emit ConfirmDenied();
    }
}

void Client::SendMessage(const QString & msg)
{
    qDebug() << "отправляем сообщение";
    if (socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(msg.toUtf8());
    }
    else
    {
        socket->connectToHost("127.0.0.1", 33333);
        emit resendMessage(msg);
    }
    qDebug() << "отправили";
}


