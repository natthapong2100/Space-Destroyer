#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    int blueCome = 0;
public:
    Enemy(QGraphicsItem * parent=0);

public slots:
    void move();
};

#endif // ENEMY_H
