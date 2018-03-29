#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QSignalMapper>
#include <QObjectList>
#include <QDebug>
#include <QPushButton>
#include "mapdelegate.h"

#pragma execution_character_set("utf-8")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList objectNameList;
    //遍历控件
//    QSignalMapper *mapper = new QSignalMapper(this);
    QObjectList list = children();
    foreach (QObject *obj, list) {
        if (obj->metaObject()->className() == QStringLiteral("QWidget")){
            QObjectList list2 = obj->children();
            foreach (QObject *obj1, list2){
                if(obj1->inherits("QLineEdit")){
                    QLineEdit* c=qobject_cast<QLineEdit*>(obj1);
                    objectNameList.push_back(c->objectName());
                    temp.insert(c->objectName(),c);
                }
            }
        }
    }
//    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(slotButton(QString)));
    //建立映射
    QStandardItemModel* model=new QStandardItemModel(1,objectNameList.size());
//    model->setItem(0,0,new QStandardItem("hello world"));
    model->setHorizontalHeaderLabels(objectNameList);
    mapper=new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);

    _mapDelegate=new MapDelegate(this,objectNameList);
//    mapper->setItemDelegate(_mapDelegate);


    widgetList::const_iterator it;
    for(it=temp.begin();it!=temp.end();++it){
        mapper->addMapping(it.value(),objectNameList.indexOf(it.key()));
    }
    mapper->toFirst();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotButton(const QString &str)
{
    qDebug()<<str;
}

void MainWindow::on_pushButton_clicked()
{
    mapper->submit();
    qDebug()<<mapper->model()->index(0,0).data().toString();
    qDebug()<<mapper->model()->index(0,1).data().toString();
    qDebug()<<mapper->model()->index(0,2).data().toString();
    qDebug()<<mapper->model()->index(0,3).data().toString();
    qDebug()<<mapper->model()->index(0,4).data().toString();
}
