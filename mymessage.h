#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <QString>
#include <QByteArray>

class MyMessage
{
    QString my_msg;

public:

    void set_msg(QString);

    QByteArray get_msg() const;
    QString get_str_msg() const;

    QString pull_back_msg(const QByteArray&) const;

    MyMessage();
};

#endif // MYMESSAGE_H
