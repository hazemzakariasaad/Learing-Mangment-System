#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    int x=0;
    ~MainMenu();

private slots:

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonExport_clicked();

    void on_comboBoxCourse_highlighted(int index);

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
