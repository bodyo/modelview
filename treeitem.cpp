#include "treeitem.h"

TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parentItem)
{
    _itemData = data;
    _parent = parentItem;
}

void TreeItem::appendChild(TreeItem *child)
{
    _childItems.append(child);
}

TreeItem* TreeItem::child(int row)
{
    return _childItems.value(row);
}

int TreeItem::childCount() const
{
    return _childItems.size();
}

int TreeItem::columnCount() const
{
    return _itemData.size();
}

QVariant TreeItem::data(int column) const
{
    return _itemData.value(column);
}

int TreeItem::row() const
{
    if (_parent)
        return _parent->_childItems.indexOf(const_cast<TreeItem*>(this));
    return 0;
}

TreeItem *TreeItem::parentItem()
{
    return _parent;
}

