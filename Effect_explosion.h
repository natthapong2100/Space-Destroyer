#ifndef EFFECT_EXPLOSION_H
#define EFFECT_EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Effect_explosion: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Effect_explosion(QGraphicsItem * parent=0);
public slots:
    void del();
};

#endif // EFFECT_EXPLOSION_H
