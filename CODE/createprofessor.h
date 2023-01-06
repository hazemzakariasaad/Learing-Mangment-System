#ifndef CREATEPROFESSOR_H
#define CREATEPROFESSOR_H

#include <QDialog>

namespace Ui {
class CreateProfessor;
}

class CreateProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfessor(QWidget *parent = nullptr);
    bool isNum(QString s);
    bool isString(QString s);
    bool age(int s);

    ~CreateProfessor();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_2_clicked();

private:
    Ui::CreateProfessor *ui;
};

#endif // CREATEPROFESSOR_H
