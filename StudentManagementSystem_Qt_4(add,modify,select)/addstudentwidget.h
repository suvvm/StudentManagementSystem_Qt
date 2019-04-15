#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class AddStudentWidget;
}

class AddStudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWidget(QWidget *parent = nullptr);
    ~AddStudentWidget();

private:
    Ui::AddStudentWidget *ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //点击主菜单按钮
    void on_addButton_clicked();    //点击添加按钮
};

#endif // ADDSTUDENTWIDGET_H
