#include "contact.h"

Contact::Contact()
{

}
bool Contact::isMatch(QString str)
{
    if (Family.toLower().indexOf(str)!=-1) return true ;
    if (Name.toLower().indexOf(str)!=-1) return true ;
    return false ;
}
