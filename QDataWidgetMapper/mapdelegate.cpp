#include "mapdelegate.h"
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>

#include <QDebug>
MapDelegate::MapDelegate(const QStringList &headerList, QObject *parent) : QItemDelegate(parent)
{
    _headerList=headerList;
}

void MapDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    qDebug()<<"column "<<index.column();
    if(index.column()>=0 && _headerList.at(index.column()).left(8)=="comboBox"){
        QComboBox *comboBox=qobject_cast<QComboBox*>(editor);
        if(comboBox){
            comboBox->setCurrentText(index.model()->data(index,Qt::EditRole).toString());
        }
    }else if(index.column()>=0 && _headerList.at(index.column()).left(8)=="checkBox"){
        QCheckBox *checkBox=qobject_cast<QCheckBox*>(editor);
        if(checkBox){
            checkBox->setChecked(index.model()->data(index,Qt::EditRole).toString()=="1"?true:false);
        }
    }else{//lineedit
        return QItemDelegate::setEditorData(editor, index);
    }
}

void MapDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    qDebug()<<"column "<<index.column();
    if(index.column()>=0 && _headerList.at(index.column()).left(8)=="comboBox"){
        QComboBox *comboBox=qobject_cast<QComboBox*>(editor);
        if(comboBox){
            model->setData(index,comboBox->currentText());
        }
    }else if(index.column()>=0 && _headerList.at(index.column()).left(8)=="checkBox"){
        QCheckBox *checkBox=qobject_cast<QCheckBox*>(editor);
        if(checkBox){
            model->setData(index,checkBox->isChecked()?"1":"0");
        }
    }else{
        return QItemDelegate::setModelData(editor, model, index);
    }
}
