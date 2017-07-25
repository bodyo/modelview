#ifndef DELEGATE_H
#define DELEGATE_H
#include <QStyledItemDelegate>

class Delegate : public QStyledItemDelegate {
public:
  Delegate(QObject *parent = 0);

  void paint(QPainter *pPainter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const override;
};

#endif // DELEGATE_H
