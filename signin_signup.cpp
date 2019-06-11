#include "signin_signup.h"
#include "ui_signin_signup.h"

signin_signup::signin_signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signin_signup)
{
    ui->setupUi(this);
    connected = false;
    connect(ui->RegistrationButton, &QPushButton::clicked, this, &signin_signup::registration_button);
    connect(ui->SignInFirstButton, &QPushButton::clicked, this, &signin_signup::sign_in);
    connect(ui->ExitButton, &QPushButton::clicked, this, &signin_signup::close);

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint |
                   Qt::WindowTitleHint | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("Lya...Chat");
    this->setAttribute(Qt::WA_CustomWhatsThis);
}

signin_signup::~signin_signup()
{
    delete ui;
}

void signin_signup::set_name_pw(QString str)
{
    if (sender() == ui->client_name)
    {
        name = str;
    }
    else {
        password = str;
    }
}

void signin_signup::registration_button()
{
    if (connected)
    {
        reg_form = new registration_form();
        reg_form->setAttribute(Qt::WA_DeleteOnClose);
        reg_form->setModal(true);
        connect(reg_form, &registration_form::new_user, this, &signin_signup::new_user);
        connect(reg_form, &registration_form::close_reg_form, this, &signin_signup::reg_form_closed);
        reg_form->show();
    }
}

void signin_signup::sign_in()
{
    emit confirm_entrance(ui->client_name->text(),ui->client_password->text());
    qDebug() << "void signin_signup::sign_in()";
}

void signin_signup::im_connected()
{
    connected = true;
}

