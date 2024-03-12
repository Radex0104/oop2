#include "dialog.h"
#include "ui_dialog.h"
#include<newedit.h>
#include <QMessageBox>
#include<data.h>
#include<get2.h>
#include <QDebug>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Телефонная книга") ;

    DM = new Data() ;
    OM = new Get2() ;
    OM->contacts = DM->createClientList() ;
    clients2grid();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ButNewBook_clicked()
{
    Contact * contact = new Contact() ;

    NewEdit * d = new NewEdit(this) ;
    d->setWindowTitle("Новый клиент");
    d->setContact(contact) ;
    d->exec() ;
    OM->contacts.append(contact);
    DM->insertClient(contact) ;
    clients2grid() ;
    qDebug() << contact;
    delete d ;
}

void Dialog::on_ButEdit_clicked()
{
    if (ui->table->currentRow()==-1) {
        QMessageBox::information(this,"Ошибка","Не выбран клиент") ;
        return ;
    }

    Contact * client = OM->contacts[ui->table->currentRow()] ;

    NewEdit * d = new NewEdit(this) ;
    d->setWindowTitle("Коррекция клиента");
    d->setContact(client) ;
    d->exec() ;
    DM->updateClient(client) ;
    clients2grid() ;

    delete d ;
}

void Dialog::clients2grid(bool filtered)
{
    QTableWidget * table = ui->table ;

    table->setSelectionBehavior(QAbstractItemView::SelectRows) ;
    table->setSelectionMode(QAbstractItemView::SingleSelection) ;

    table->setColumnCount(3) ;
    table->setHorizontalHeaderItem(0,new QTableWidgetItem("Фамилия")) ;
    table->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя")) ;
    table->setHorizontalHeaderItem(2,new QTableWidgetItem("Телефон")) ;

    table->setRowCount(0);

    int k = 0 ;
    for (int i=0; i<OM->contacts.size(); i++) {
        bool z = true ;
        if (filtered) z = z && (OM->contacts[i]->isMatch(ui->edSearch->text().trimmed().toLower())) ;

        if (z) {
        table->setRowCount(k+1);

        table->setVerticalHeaderItem(k,new QTableWidgetItem(QString::number(i+1))) ;
        table->setItem(k,0,new QTableWidgetItem(OM->contacts[i]->Family)) ;
        table->setItem(k,1,new QTableWidgetItem(OM->contacts[i]->Name)) ;
        table->setItem(k,2,new QTableWidgetItem(OM->contacts[i]->email)) ;
        k++ ;
        }
    }

    table->resizeColumnsToContents();
}

void Dialog::on_ButDel_clicked()
{
    if (ui->table->currentRow()==-1) {
        QMessageBox::information(this,"Ошибка","Не выбран клиент") ;
        return ;
    }

    Contact * client = OM->contacts[ui->table->currentRow()] ;

    DM->deleteClient(client) ;
    OM->contacts.removeAll(client) ;

    clients2grid() ;

}

void Dialog::on_ButFind_clicked()
{
    clients2grid(true) ;
}
