#include "get2.h"
#include <QSharedPointer>

QSharedPointer<Get2> OM;
Get2::Get2()
{
    NullClient = new Contact() ;
}
Contact *Get2::findClientById(int id)
{
    for (int i=0; i<contacts.size(); i++)
        if (contacts[i]->id==id) return contacts[i] ;
    return NullClient ;
}
