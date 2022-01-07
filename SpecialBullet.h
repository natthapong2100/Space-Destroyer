#ifndef SPECIALBULLET_H
#define SPECIALBULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class SpecialBullet: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    SpecialBullet(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // SPECIALBULLET_H
