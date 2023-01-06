#ifndef EDITPROFESSOR_H
#define EDITPROFESSOR_H

#include <QDialog>

namespace Ui {
class EditProfessor;
}

class EditProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfessor(QWidget *parent = nullptr);
    ~EditProfessor();

private slots:


    void on_comboBox_Profs_currentIndexChanged(int index);

    void on_ok_clicked();

    void on_save_clicked();

    void on_delete_prof_clicked();

    void on_delete_2_clicked();

    bool isNum(QString s);

    bool isString(QString s);


private:
    Ui::EditProfessor *ui;
};

#endif // EDITPROFESSOR_H
