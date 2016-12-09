#ifndef DOWNLODER_H
#define DOWNLODER_H
#include "QString"
using namespace std;

class downloder
{
public:
    downloder();
    QString downlode(string);
    friend int write(char *, size_t, size_t, string *);
};

#endif // DOWNLODER_H
