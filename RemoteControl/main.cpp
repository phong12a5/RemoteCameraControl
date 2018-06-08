#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyModel.h"


int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyModel* model = MyModel::getInstance();
    engine.rootContext()->setContextProperty("MyModel", model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
