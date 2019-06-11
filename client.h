#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
    QString name;
    QString password;
    int counter = 0;
    int connection_counter = 0;

public:
    void SetSocket(QTcpSocket *);

    Client();
    ~Client();
    void ConnectToServer();
private:
    void AcceptConfirm_connectuser();
private slots:
    void SocketStateChanged(QAbstractSocket::SocketState);//состояние сокета
public slots:
    void reg_form_was_closed();
    void SendMessage(const QString &);
    void AcceptConfirm_registration();
    void Registre_new_client(const QString &, const QString &, const QString &);
    void Connect(const QString &, const QString &);
    void Confirm();
    void ReadMessage();
    void ConfirmChatnameAndPassword_connect(const QString &, const QString &);
    void ConfirmChatnameCreated(const QString &, const QString &);
    void AcceptConfirm_Connectchat();
    void AcceptConfirm_Createchat();
signals:
    void resendMessage(const QString &);
    void go_toServer();
    void imconnected_to_sisu();
    void CHeckSignIn_toServer(const QString &, const QString &);

    void CreateAccepted();
    void CreateDenied();
    void CreateChat(const QString &, const QString &);
    void Accept_chat_connecting();
    void Deni_chat_connecting();
    void Disconnected();
    void ConfirmAccepted();
    void ConfirmDenied();
    void Show(const QString &);
public:
    QTcpSocket * socket;
};

#endif // CLIENT_H
