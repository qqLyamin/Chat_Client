#include "mymessage.h"

void MyMessage::set_msg(QString str)
{
    my_msg = str;
}

QByteArray MyMessage::get_msg() const
{
    if (!my_msg.isEmpty())
    {
        return my_msg.toUtf8();
    }
    else {
        return QByteArray();
    }
}

QString MyMessage::get_str_msg() const
{
    return my_msg;
}

QString MyMessage::pull_back_msg(const QByteArray& msg_back) const
{
    return QString::fromUtf8(msg_back);
}

MyMessage::MyMessage()
{
}
