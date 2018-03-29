#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QAbstractTableModel>
class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = 0);

signals:

public slots:
};

#endif // MODEL_H
