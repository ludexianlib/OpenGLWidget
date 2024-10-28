#include "Widget.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "VertexObject/Vertexes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
