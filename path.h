#ifndef PATH_H
#define PATH_H
#include "global.h"
#include <QStringList>
#include <QString>

struct Path{
public:
//    bool operator<(const Path& path2);
    int_t from;
    int_t to;
    int_t weight=0;
    Path(QString str);

};
uint qHash(const Path& p);
bool operator==(const Path& p1,const Path& p2);


#endif // PATH_H


