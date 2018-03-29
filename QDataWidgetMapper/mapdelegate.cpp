#include "mapdelegate.h"
#include <QLineEdit>
#include <QComboBox>

MapDelegate::MapDelegate(QObject *parent, const QStringList &headerList) : QItemDelegate(parent)
{
    _headerList=headerList;
}

void MapDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(_headerList.at(index.column()).left(8)=="comboBox"){
        QComboBox *comboBox=qobject_cast<QComboBox*> editor;
        if(comboBox){
            comboBox->setCurrentText(index.model()->data(index,Qt::EditRole).toString());
        }
    }else{//lineedit
        return QItemDelegate::setEditorData(editor, index);
    }
}

void MapDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(_headerList.at(index.column()).left(8)=="comboBox"){
        QComboBox *comboBox=qobject_cast<QComboBox*> editor;
        if(comboBox){
            model->setData(index,comboBox->currentText());
        }
    }else{
        return QItemDelegate::setModelData(editor, model, index);
    }
}
