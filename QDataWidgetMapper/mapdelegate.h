#ifndef MAPDELEGATE_H
#define MAPDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include <QAbstractItemDelegate>
#pragma execution_character_set("utf-8")

class MapDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MapDelegate(const QStringList &headerList, QObject *parent=0);

    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const
                      QModelIndex &index) const Q_DECL_OVERRIDE;
//signals:
//    void commitData(QWidget *editor);
//    void closeEditor(QWidget *editor, EndEditHint hint);
private:
    QStringList _headerList;
};

#endif // MAPDELEGATE_H
