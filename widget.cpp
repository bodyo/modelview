#include "widget.h"
#include "delegate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), model("")
{
    QVBoxLayout *layout = new QVBoxLayout();
    proxy.setSourceModel(&model);
    proxy.setFilterWildcard("*");
//    proxy.

    layout->addWidget(&sort);
    layout->addWidget(&view);
    view.setModel(&proxy);
    view.setItemDelegate(new Delegate(&view));
    setLayout(layout);

    connect(&sort, &QLineEdit::textChanged, this, &Widget::patternChanged);
}

void Widget::patternChanged()
{
    proxy.setFilterWildcard(sort.text()+'*');
}
