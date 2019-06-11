#include "mychat.h"
#include <QApplication>
#include <QObject>
#include <QStyleFactory>
#include "create.h"
#include "connect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));

    Create_chat sad;
    sad.show();
    connect2_chat dsa;
    dsa.show();
    //myChat w;

    return a.exec();
}
