#ifndef CREATE_CONNECT_H
#define CREATE_CONNECT_H

#include <QDialog>
#include "create.h"
#include "connect.h"

namespace Ui {
class create_connect;
}

class create_connect : public QDialog
{
    Q_OBJECT

public:
    explicit create_connect(QWidget *parent = nullptr);
    ~create_connect();

public slots:
    void Host_button_haspressed();
    void Guest_button_haspressed();
    void exit();
signals:
    void host();
    void guest();
    void back();
private:
    Ui::create_connect *ui;
};

#endif // CREATE_CONNECT_H
