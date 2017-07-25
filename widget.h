#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "treemodel.h"
#include "treeitem.h"
#include <QTreeView>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QSortFilterProxyModel>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

signals:

public slots:
    void patternChanged();

private:
    TreePictureModel model;
    QSortFilterProxyModel proxy;
    QTextEdit sort;
    QTreeView view;
};

#endif // WIDGET_H
