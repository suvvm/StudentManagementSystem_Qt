#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QVector>
#include "studentinfo.h"

namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = nullptr);
    ~ModifyWidget();

private:
    Ui::ModifyWidget *ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //点击主菜单按钮
    void on_deleteButton_clicked(); //点击删除按钮
    void on_modifyButton_clicked(); //点击修改按钮
};

#endif // MODIFYWIDGET_H
