#include "menuwidget.h"
#include "ui_menuwidget.h"

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::on_addButton_clicked(){
    emit display(1);
}

void MenuWidget::on_selectButton_clicked(){
    emit display(2);
}

void MenuWidget::on_modifyButton_clicked(){
    emit display(3);
}

void MenuWidget::on_sortButton_clicked(){
    emit display(4);
}

void MenuWidget::on_exitButton_clicked(){
    QApplication::exit();
}
