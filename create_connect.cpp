#include "create_connect.h"
#include "ui_create_connect.h"

create_connect::create_connect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::create_connect)
{
    ui->setupUi(this);
    connect(ui->HostChatButton_2, &QPushButton::clicked, this, &create_connect::Host_button_haspressed);
    connect(ui->GuestInChatButton_2, &QPushButton::clicked, this, &create_connect::Guest_button_haspressed);
    connect(ui->ExitButton, &QPushButton::clicked, this, &create_connect::exit);
}

create_connect::~create_connect()
{
    delete ui;
}

void create_connect::Host_button_haspressed()
{
   emit host();
}

void create_connect::Guest_button_haspressed()
{
    emit guest();
}

void create_connect::exit()
{
    this->close();
    //emit create_connect::back();
}
