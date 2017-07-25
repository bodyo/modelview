#include "treemodel.h"
#include "treeitem.h"
#include <QString>

enum ColumnType
{
    Name,
    Count
};

TreePictureModel::TreePictureModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData{"Name" ,"Count of Points"};
    rootItem = new TreeItem(rootData);
    setupModelData(QStringList{"first", "sec", "third", "five"}, rootItem);
}

TreePictureModel::~TreePictureModel()
{
    delete rootItem;
}

QVariant TreePictureModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
    return item->data(index.column());
}

Qt::ItemFlags TreePictureModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;
    return QAbstractItemModel::flags(index);
}

QVariant TreePictureModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreePictureModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childIndex = parentItem->child(row);
    if (childIndex)
        return createIndex(row, column, childIndex);
    else
        return QModelIndex();
}

QModelIndex TreePictureModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();
    return createIndex(parentItem->row(), 0, parentItem);
}

int TreePictureModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    return parentItem->childCount();
}

int TreePictureModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

void TreePictureModel::setupModelData(const QStringList &lines, TreeItem *parent)
{
    for (const QString &data: lines)
        parent->appendChild(new TreeItem({data, "2342"}, parent));
    TreeItem *child = parent->child(0);
    for (const QString &data: lines)
        child->appendChild(new TreeItem({data+"d", "sdfgfd"}, child));
    child = parent->child(1);
    for (const QString &data: lines)
        child->appendChild(new TreeItem({data+"f", "++++++"}, child));
}

