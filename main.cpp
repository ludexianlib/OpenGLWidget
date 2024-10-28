#include "Widget.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include "VertexObject/Vertexes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Vertex v1;
    v1.position = Vec3D{ 3, 4, 1 };
    v1.color = Vec3D{ 1, 1, 1 };
    v1.texture = Vec2D{ 2, 2 };
    Vertex v2;
    v2.position = Vec3D{ 1, 1, 1 };

    Mesh mesh;
    mesh.vertexes = {
        v1, v2
    };
    
    qDebug() << "size: " << mesh.vertexes.size();
    qDebug() << "size: " << sizeof(Vertex);
    qDebug() << "size: " << sizeof(mesh.vertexes);
    qDebug() << "offset: " <<  offsetof(Vertex, position);

    Widget w;
    w.show();
    return a.exec();
}
