#include "path.h"
Path::Path(QString str){
    QStringList list=str.split(" ");
    from=list[0].toLongLong();
    to=list[1].toLongLong();

    if(list.size()>2){
        weight=list[2].toLongLong();
    }
}
//bool Path::operator<(const Path& path2){
//    if(from<path2.from) return true;
//    else if(from>path2.from) return false;
//    return to<path2.to;
//}

bool operator<(const Path& path1,const Path& path2){
    if(path1.from<path2.from) return true;
    else if(path1.from>path2.from) return false;
    return path1.to<path2.to;
}

bool operator==(const Path& p1,const Path& p2){
    return p1.from==p2.from&&p1.to==p2.to&&p1.weight==p2.weight;
}
uint qHash(const Path& p){
    int_t result=p.from*p.to;
    if(p.weight){
        result^=p.weight;
    }
    return result;
}
