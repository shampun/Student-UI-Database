#include "sims.h"
#include "ui_sims.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SIMS w;

    w.show();
    return a.exec();
}
