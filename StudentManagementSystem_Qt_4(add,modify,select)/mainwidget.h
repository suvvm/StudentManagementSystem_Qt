#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "menuwidget.h"
#include "addstudentwidget.h"
#include "selectwidget.h"
#include "modifywidget.h"
#include "sortwidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

    MenuWidget *menuwidget;	//菜单窗口
    AddStudentWidget *addstudentwidget;	//添加学生窗口
    SelectWidget *selectwidget;	//查询窗口
    ModifyWidget *modifywidget;	//修改窗口
    SortWidget *sortwidget;	//排序窗口
    QStackedLayout *stackLayout;	//QStackedLayout布局


};

#endif // MAINWIDGET_H
