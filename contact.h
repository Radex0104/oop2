#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    int id ;
    QString Family ;
    QString Name ;
    QString email ;
    bool isMatch(QString str) ;
    Contact();
};

#endif // CONTACT_H
