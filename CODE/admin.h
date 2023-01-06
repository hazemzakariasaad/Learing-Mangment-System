#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Admin; }
QT_END_NAMESPACE

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Admin *ui;
};
#endif // ADMIN_H
