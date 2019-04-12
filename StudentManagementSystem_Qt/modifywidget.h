#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>

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
    void on_returnButton_clicked();
};

#endif // MODIFYWIDGET_H
