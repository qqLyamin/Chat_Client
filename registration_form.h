#ifndef REGISTRATION_FORM_H
#define REGISTRATION_FORM_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class registration_form;
}

class registration_form : public QDialog
{
    Q_OBJECT
public:
    explicit registration_form(QWidget *parent = nullptr);
    ~registration_form();
public slots:
    void close_window();
    void sign_up();
signals:
    void close_reg_form();
    void new_user(const QString &, const QString &, const QString &);
private:
    Ui::registration_form *ui;
};

#endif // REGISTRATION_FORM_H
