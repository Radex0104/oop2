#include "get2.h"

Get2 * OM ;

Get2::Get2()
{

}
Contact *Get2::findClientById(int id)
{
    for (int i=0; i<contacts.size(); i++)
        if (contacts[i]->id==id) return contacts[i] ;
    return NullClient ;
}
