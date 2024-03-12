#ifndef DATA_H
#define DATA_H
#include <QList>
#include "contact.h"
#include <QString>
class Data
{
public:
    Data();

    QList<Contact*> createClientList() ;
    bool insertClient(Contact * contact) ;
    bool updateClient(Contact * contact) ;
    bool deleteClient(Contact * contact) ;

    int getFirstIntFromSQL(QString sql) ;
};
extern Data * DM ;
#endif // DATA_H
