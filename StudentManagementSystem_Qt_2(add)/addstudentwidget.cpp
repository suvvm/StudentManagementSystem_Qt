#include "addstudentwidget.h"
#include "ui_addstudentwidget.h"


AddStudentWidget::AddStudentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudentWidget)
{
    ui->setupUi(this);
}

AddStudentWidget::~AddStudentWidget()
{
    delete ui;
}
void AddStudentWidget::on_returnButton_clicked(){   //"主菜单"按钮点击
    emit display(0);
}

void AddStudentWidget::on_addButton_clicked(){  //"添加"按钮点击
    QString name = ui->nameLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    int id = ui->idLineEdit->text().toInt();
    //将用户输入的学号由idLineEdit取出，并转换为整型
    int math = ui->mathLineEdit->text().toInt();
    //将用户输入的学号由mathLineEdit取出，并转换为整型
    int english = ui->enLineEdit->text().toInt();
    //将用户输入的学号由enLineEdit取出，并转化为整型
    int languageC = ui->cLineEdit->text().toInt();
    //将用户输入的学号由cLineEdit取出，并转化为整型
    if(ui->nameLineEdit->text() == "" || ui->idLineEdit->text() == "" || ui->mathLineEdit->text() == "" || ui->enLineEdit->text() == "" || ui->cLineEdit->text() == ""){
        //插入的五项数据都不能为空，否则在读取文件时会出现问题。
        QMessageBox::about(NULL, "反馈", "存在空项");
    }
    QFile file("student.txt");
    //实例化一个QFile file为我们的数据文件student.txt
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    //open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
    //QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
    //QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾
    if(!file.isOpen()){ //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return;
    }
    QTextStream out(&file);
    //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
    out << name << " " <<  id << " " << math << " " << english << " " << languageC << endl;
    //将我们刚刚获取的数据写入文件
    file.close();
    QMessageBox::about(NULL, "反馈", "插入成功");
    ui->nameLineEdit->clear();
    ui->idLineEdit->clear();
    ui->mathLineEdit->clear();
    ui->enLineEdit->clear();
    ui->cLineEdit->clear();
    //将用户输入的数据清空
}
