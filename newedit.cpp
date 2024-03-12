#include "newedit.h"
#include "ui_newedit.h"

void NewEdit::setContact(Contact *contact)
{
    obj = contact ;
    ui->edName->setText(obj->Name) ;
    ui->edFamily->setText(obj->Family) ;
    ui->edEmail->setText(obj->email) ;
}

NewEdit::NewEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEdit)
{
    ui->setupUi(this);
}

NewEdit::~NewEdit()
{
    delete ui;
}

void NewEdit::on_pushButton_2_clicked()
{
    hide() ;
}

void NewEdit::on_pushButton_clicked()
{
    obj->Name = ui->edName->text().trimmed() ;
    obj->Family = ui->edFamily->text().trimmed() ;
    obj->email = ui->edEmail->text().trimmed() ;
    hide();
}
