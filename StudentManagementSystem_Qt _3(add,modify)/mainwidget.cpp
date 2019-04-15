#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    menuwidget = new MenuWidget;
    addstudentwidget = new AddStudentWidget;
    selectwidget = new SelectWidget;
    modifywidget = new ModifyWidget;
    sortwidget = new SortWidget;
    stackLayout = new QStackedLayout;

    stackLayout->addWidget(menuwidget);
    stackLayout->addWidget(addstudentwidget);
    stackLayout->addWidget(selectwidget);
    stackLayout->addWidget(modifywidget);
    stackLayout->addWidget(sortwidget);

    setLayout(stackLayout);

    connect(menuwidget, &MenuWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(addstudentwidget, &AddStudentWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(selectwidget, &SelectWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(modifywidget, &ModifyWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(sortwidget, &SortWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
    delete ui;
}
