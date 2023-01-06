#ifndef CREATESTUDENT_H
#define CREATESTUDENT_H
#include "Database.h"
#include <QDialog>
#include<QListWidgetItem>
#include<QMessageBox>
using namespace std ;
namespace Ui {
class CreateStudent;
}

class CreateStudent : public QDialog
{
    Q_OBJECT

public:
    explicit CreateStudent(QWidget *parent = nullptr);
    void pushToVector(int row,Student &s);
    bool isnum(QString a);
    bool isstring(QString b) ;
    bool age (int s);
    ~CreateStudent();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateStudent *ui;
};

#endif // CREATESTUDENT_H
