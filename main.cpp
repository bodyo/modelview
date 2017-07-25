#include "widget.h"

#include <QApplication>
#include <QFile>
#include <QTreeView>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget wig;
    wig.setWindowTitle(QObject::tr("Simple Tree Model"));
    wig.show();
    return app.exec();
}
