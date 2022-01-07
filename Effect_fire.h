#ifndef EFFECT_FIRE_H
#define EFFECT_FIRE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Effect_fire: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Effect_fire(QGraphicsItem * parent=0);
public slots:
    void del();
};

#endif // EFFECT_FIRE_H
