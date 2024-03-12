#ifndef NEWEDIT_H
#define NEWEDIT_H

#include <QDialog>
#include "contact.h"

namespace Ui {
class NewEdit;
}

class NewEdit : public QDialog
{
    Q_OBJECT

public:
    void setContact(Contact * client) ;
    explicit NewEdit(QWidget *parent = nullptr);
    ~NewEdit();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Contact * obj ;
    Ui::NewEdit *ui;
};

#endif // NEWEDIT_H
