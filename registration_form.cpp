#include "registration_form.h"
#include "ui_registration_form.h"

registration_form::registration_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration_form)
{
    ui->setupUi(this);
    connect(ui->ExitRegistrationButton, &QPushButton::clicked, this, &registration_form::close_window);
    connect(ui->SingUPRegistrationButton, &QPushButton::clicked, this, &registration_form::sign_up);
}

registration_form::~registration_form()
{
    delete ui;
}

void registration_form::close_window()
{
    emit close_reg_form();
    this->close();
}

void registration_form::sign_up()
{
    if (!ui->lineEdit_Nickname->text().isEmpty())
    {
        if (!ui->lineEdit_Password->text().isEmpty())
        {
            if (!ui->lineEdit_ConfirmPassword->text().isEmpty())
            {
                if (!ui->lineEdit_email->text().isEmpty())
                {
                    emit new_user(ui->lineEdit_Nickname->text(), ui->lineEdit_email->text(), ui->lineEdit_Password->text());
                    this->close();
                    //QMessageBox::about(this, "Congratulations!", "your registration done!");
                }
                else {
                    QMessageBox::about(this, "error", "please enter your email");
                }
            }
            else {
                QMessageBox::about(this, "error", "please confirm your password");
            }
        }
        else {
            QMessageBox::about(this, "error", "please enter your password");
        }
    }
        else {
        QMessageBox::about(this, "error", "please enter your nickname");
    }
}
