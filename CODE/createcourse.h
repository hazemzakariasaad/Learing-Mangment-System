#ifndef CREATECOURSE_H
#define CREATECOURSE_H

#include <QDialog>

namespace Ui {
class CreateCourse;
}

class CreateCourse : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCourse(QWidget *parent = nullptr);
    bool isNum(QString s);
    bool isString(QString s);
    ~CreateCourse();

private slots:
    void on_pushButton_create_clicked();

private:
    Ui::CreateCourse *ui;
};

#endif // CREATECOURSE_H
