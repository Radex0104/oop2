#ifndef GET2_H
#define GET2_H

#include <QList>
#include "contact.h"
#include <QSharedPointer>
class Get2
{
private:
    Contact * NullClient ;
public:
    Get2();
    QList<Contact*> contacts ;
    Contact *findClientById(int id) ;
};
//extern Get2 * OM ;

extern QSharedPointer<Get2> OM;
#endif // GET2_H
