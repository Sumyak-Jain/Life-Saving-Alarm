#include "loginpage.h"

LoginPage::LoginPage(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant LoginPage::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex LoginPage::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex LoginPage::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int LoginPage::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int LoginPage::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant LoginPage::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
