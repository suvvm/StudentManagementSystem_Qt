#ifndef ADDSTUDENTWIDGET_H
#define ADDSTUDENTWIDGET_H

#include <QWidget>

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
    void on_returnButton_clicked();
};

#endif // ADDSTUDENTWIDGET_H
