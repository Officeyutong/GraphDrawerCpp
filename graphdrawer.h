#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <configdialog.h>
#include "global.h"
#include "path.h"
#include <QHash>
#include <QSet>
#include <QMap>
#include "utils.h"
#include <map>
#include <set>
#include <QTextStream>
#include <functional>
#include <iostream>
#include <cstdio>
using namespace std;

class GraphDrawer
{
private:
    ConfigDialog *dialog;
    QPainter* painter;
    set<int_t> vertexes;
    QSet<Path> edges;
    QMap<int_t ,QPoint> points;
public:
    GraphDrawer(ConfigDialog *dialog,QPainter * painter);
    void draw();
    void parse();

};

#endif // GRAPHDRAWER_H
