#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Effect_explosion.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/pro_purpleB.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); //Move caller func
    timer->start(50);

}


void Bullet::move(){
    QList<QGraphicsItem *> collide_items = collidingItems();
    for (int i = 0; i < collide_items.size(); ++i){
        if (typeid(*(collide_items[i])) == typeid(Enemy)){

            if(game->health->getHealth() > 0){
                 game->score->increase();
            }
            // create FX explosion
            Effect_explosion *explosion = new Effect_explosion();
            explosion->setPos(x() - 10, y() - 20);
            scene()->addItem(explosion);

            // remove them both from the scene
            scene()->removeItem(collide_items[i]);
            scene()->removeItem(this);            

            // delete memory
            delete collide_items[i];
            delete this;
            return;

        }
    }

    setPos(x(), y()-10);

    if (pos().y() + 500 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
