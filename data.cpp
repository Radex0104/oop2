#include "data.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

#include <QDebug>

#include "get2.h"

Data * DM ;
//QSharedPointer<Data> DM;

Data::Data()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("telbook.s3db");

    if (!sdb.open()) {
          qDebug() << sdb.lastError().text();
    }
}

QList<Contact*> Data::createClientList()
{
    QList<Contact*> res ;
    QSqlQuery query("CREATE TABLE "
                       "ContactBook(id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Family TEXT, PhoneNumber TEXT,  FOREIGN KEY (GroupID) REFERENCES Groups(id))");

   // QSqlQuery query("SELECT id,cfamily,cname,email FROM contacts");
    while (query.next()) {
             QSharedPointer<Contact> contact(new Contact());
             contact->id=query.value(0).toInt() ;
             contact->Family=query.value(1).toString();
             contact->Name=query.value(2).toString();
             contact->email=query.value(3).toString();
             res.append(contact.data());
    }
qDebug()<<res;
    return res ;
}

bool Data::insertClient(Contact *contact)
{
    QSqlQuery query ;
    query.prepare(QString("INSERT INTO contacts (cfamily,cname,email) ")+
                    QString(" VALUES (:cfamily,:cname,:email)")) ;
    query.bindValue(":cfamily",contact->Family);
    query.bindValue(":cname",contact->Name);
    query.bindValue(":email",contact->email);

    query.exec() ;

    contact->id = getFirstIntFromSQL("SELECT max(id) FROM contacts") ;

    return true ;
}

bool Data::updateClient(Contact *contact)
{
    QSqlQuery query ;
    query.prepare(QString("UPDATE contacts SET cfamily=:cfamily,cname=:cname,email=:email WHERE id=:id")) ;

    query.bindValue(":cfamily",contact->Family);
    query.bindValue(":cname",contact->Name);
    query.bindValue(":email",contact->email);
    query.bindValue(":id",contact->id);

    query.exec() ;

    return true ;
}

bool Data::deleteClient(Contact *contact)
{
    QSqlQuery query ;
    query.prepare(QString("DELETE FROM contacts WHERE id=:id")) ;
    query.bindValue(":id",contact->id);

    query.exec() ;

    return true ;
}
int Data::getFirstIntFromSQL(QString sql)
{
    QSqlQuery query(sql);
    if (query.next())
        return query.value(0).toInt();
    else
        return 0 ;
}
