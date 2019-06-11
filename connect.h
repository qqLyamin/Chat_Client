#ifndef CONNECT_H
#define CONNECT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class connect2_chat;
}

class connect2_chat : public QDialog
{
    Q_OBJECT

public:
    explicit connect2_chat(QWidget *parent = nullptr);
    ~connect2_chat();
signals:
    void connect_2chatroom(QString chat_name, QString chat_password);
    void back();
public slots:
    void chatname_and_password();
private:
    Ui::connect2_chat *ui;
};

#endif // CONNECT_H
