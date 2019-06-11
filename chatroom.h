#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>

namespace Ui {
class Chatroom;
}

class Chatroom : public QDialog
{
    Q_OBJECT

public:
    explicit Chatroom(QWidget *parent = nullptr);
    ~Chatroom();
public slots:
//    void confirm_accept();
//    void confirm_denied();
private:
    Ui::Chatroom *ui;
};

#endif // CHATROOM_H
