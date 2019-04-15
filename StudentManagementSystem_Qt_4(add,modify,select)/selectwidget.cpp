#include "selectwidget.h"
#include "ui_selectwidget.h"

SelectWidget::SelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectWidget)
{
    ui->setupUi(this);
}

SelectWidget::~SelectWidget()
{
    delete ui;
}

void SelectWidget::on_returnButton_clicked(){
    emit display(0);
}

void SelectWidget::on_selectButton_clicked(){
    if(ui->idLineEdit->text() == ""){
        QMessageBox::about(NULL, "反馈", "id不能为空");
        return;
    }
    QFile file("student.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读的方式打开文本文件
    if(!file.isOpen()){ //文件打开失败
        QMessageBox::about(NULL, "反馈", "文件打开失败");
        return;
    }
    QTextStream inp(&file);
    //以file作为Qt文本流
    QVector<StudentInfo> allStudentInfo;
    //数据类型为StudentInfo的QVector容器
    while(!inp.atEnd()){ //读到文件结尾
        QString name;
        int id, math, english, languageC;
        inp >> name >> id >> math >> english >> languageC;
        allStudentInfo.push_back(StudentInfo(name, id, math, english, languageC));
        //调用之前建立的构造函数实例化一个StudentInfo对象并将其加入allStudentInfo
    }
    allStudentInfo.pop_back();
    //扔掉最后的无用数据
    file.close();
    //关闭文件
    int id = ui->idLineEdit->text().toInt();
    bool flag = false;
    for(auto i : allStudentInfo){
        if(i.getId() == id){
            ui->showNameLabel->setText(i.getName());
            ui->showMathLabel->setText(QString::number(i.getMath()));
            ui->showEnLabel->setText(QString::number(i.getEnglish()));
            ui->showCLabel->setText(QString::number(i.getLanguageC()));
            ui->showAvgLabel->setText(QString::number(i.getAvg()));
            flag = true;
            break;
        }
    }
    if(!flag){
       QMessageBox::about(NULL, "反馈", "id不存在！");
    }
    ui->idLineEdit->clear();
}
