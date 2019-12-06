#ifdef QT_QML_DEBUG

#endif

#include <sailfishapp.h>
#include <counter.h>
#include <custommap.h>
#include <QtQuick>
#include <QGuiApplication>
#include <QQuickView>


int main(int argc, char *argv[])
{
//    const QGuiApplication* app = SailfishApp::application(argc, argv);
//    qmlRegisterType<Counter>("harbour.appname.MyModule",1,0,"Counter");
//    const QMetaObject meta = Counter::staticMetaObject;
 //   QObject *obj = meta.newInstance();
//    QObject::connect(obj, SIGNAL(countChange()), obj, SLOT(printCount()));
    const QMetaObject meta = Counter::staticMetaObject;
    QObject *obj = meta.newInstance();
    QObject::connect(obj, SIGNAL(countChange()), obj, SLOT(printCount()));
    meta.invokeMethod(obj,"increment");
    meta.invokeMethod(obj,"increment");
    meta.invokeMethod(obj,"toNull");

    const QMetaObject meta1 = CustomMap::staticMetaObject;
    QObject *obj1 = meta1.newInstance();
    QObject::connect(obj1, SIGNAL(listChange()), obj1, SLOT(print()));

    QGuiApplication *app = SailfishApp::application(argc, argv);
    QQuickView * view = SailfishApp::createView();
    view->setSource(SailfishApp::pathTo("qml/Laba6.qml"));
    qmlRegisterType<Counter>("custom.Counter",1,0,"Counter");
    qmlRegisterType<CustomMap>("custom.CustomMap",1,0,"CustomMap");
    view->show();

    return app->exec();
//    return SailfishApp::main(argc, argv);
}
