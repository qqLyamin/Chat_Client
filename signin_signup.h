#ifndef SIGNIN_SIGNUP_H
#define SIGNIN_SIGNUP_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include "registration_form.h"
#include "create_connect.h"

namespace Ui {
class signin_signup;
}

class signin_signup : public QDialog
{
    Q_OBJECT
    QString name;
    QString password;
    registration_form * reg_form;
    create_connect * cre_con;
    bool got_this_user = 0;
    bool connected;

public:
    explicit signin_signup(QWidget *parent = nullptr);
    ~signin_signup();
public slots:
    void set_name_pw(QString);
    void registration_button();
    void sign_in();
    void im_connected();
signals:
    void reg_form_closed();
    void connectToServer();
    void new_user(const QString &, const QString &, const QString &);
    void confirm_entrance(const QString &, const QString &);
private:
    Ui::signin_signup *ui;
};

#endif // SIGNIN_SIGNUP_H
