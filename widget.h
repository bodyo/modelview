#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "treemodel.h"
#include "treeitem.h"
#include <QTreeView>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSortFilterProxyModel>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);

signals:

public slots:
    void patternChanged();

private:
    TreePictureModel model;
    QSortFilterProxyModel proxy;
    QLineEdit sort;
    QTreeView view;
};

#endif // WIDGET_H
