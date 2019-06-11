#ifndef CREATE_H
#define CREATE_H

#include <QDialog>
#include "chatroom.h"
#include <thread>
#include <QMessageBox>

namespace Ui {
class Create_chat;
}

class Create_chat : public QDialog
{
    Q_OBJECT

public:
    explicit Create_chat(QWidget *parent = nullptr);
    ~Create_chat();
signals:
    void create_chatroom(const QString &, const QString &);
    void back();
public slots:
    void chatname_and_password_creating();
private:
    Ui::Create_chat *ui;
};

#endif // CREATE_H
