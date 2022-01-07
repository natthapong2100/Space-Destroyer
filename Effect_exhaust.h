#ifndef EFFECT_EXHAUST_H
#define EFFECT_EXHAUST_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Effect_exhaust: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Effect_exhaust(QGraphicsItem * parent=0);
public slots:
    void del();
};

#endif // EFFECT_EXHAUST_H
