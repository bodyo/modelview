#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

class TreeItem
{
public:
    explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = 0);
    ~TreeItem() = default;

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    void setData(int column, const QVariant &data);
    int row() const;
    TreeItem *parentItem();

private:
    QList<TreeItem*> _childItems;
    QList<QVariant> _itemData;
    TreeItem *_parent;
};

#endif // TREEITEM_H
