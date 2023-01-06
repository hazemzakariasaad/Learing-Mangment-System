#ifndef EDITSTUDENT_H
#define EDITSTUDENT_H

#include <QDialog>

namespace Ui {
class EditStudent;
}

class EditStudent : public QDialog
{
    Q_OBJECT

public:
    explicit EditStudent(QWidget *parent = nullptr);
    void displayStudent(int i); //ana el mezawdha sheelha
    void displayScore(int i,int curstd); //ana el mezawdha sheelha
    bool isNum(QString s);
    bool isString(QString s);
    ~EditStudent();

private slots:

    void on_comboBoxStudent_currentIndexChanged(int index);

    void on_comboBoxCurrentCourses_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonMainMenu_clicked();

    void on_pushButtonRemove_clicked();

private:
    Ui::EditStudent *ui;
};

#endif // EDITSTUDENT_H
