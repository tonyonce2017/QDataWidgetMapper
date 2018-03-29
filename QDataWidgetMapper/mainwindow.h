#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QHash>
#include <QWidget>

class MapDelegate;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void slotButton(const QString& str);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QDataWidgetMapper* mapper;
    typedef QHash<QString, QWidget*> widgetList;
    widgetList temp;
    MapDelegate* _mapDelegate;
};

#endif // MAINWINDOW_H
