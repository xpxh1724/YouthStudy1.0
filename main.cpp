#include "mainwidget.h"
#include <QApplication>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    //永远不应用高分屏及缩放
#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    QApplication::setAttribute(Qt::AA_Use96Dpi);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5,14,0))
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::Floor);
#endif
    QApplication a(argc, argv);
    mainWidget w;
    return a.exec();
}
