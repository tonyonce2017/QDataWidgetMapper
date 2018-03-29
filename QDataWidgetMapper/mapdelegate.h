#ifndef MAPDELEGATE_H
#define MAPDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#pragma execution_character_set("utf-8")

class MapDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MapDelegate(QObject *parent=0, const QStringList &headerList={});

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
private:
    QStringList _headerList;
};

#endif // MAPDELEGATE_H
