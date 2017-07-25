#include "delegate.h"
#include <QPainter>
#include <QPen>
//#include <QLen
Delegate::Delegate(QObject *parent) : QStyledItemDelegate(parent) {}

void Delegate::paint(QPainter *pPainter, const QStyleOptionViewItem &option,
                     const QModelIndex &index) const
{
    QRect rect = option.rect;
    QLinearGradient grad(0,0,rect.width(), rect.height());
    pPainter->setPen(Qt::blue);
    grad.setColorAt(0, Qt::blue);
    grad.setColorAt(0.5, Qt::white);
    grad.setColorAt(1, Qt::green);
    pPainter->setBrush(grad);

    pPainter->drawRect(rect);

    QStyledItemDelegate::paint(pPainter, option, index);
}
