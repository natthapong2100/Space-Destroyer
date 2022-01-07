#include "SpecialBullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Effect_explosion.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern Game * game; // there is an external global object called game

SpecialBullet::SpecialBullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/pro_greenB.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}


void SpecialBullet::move(){
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

            scene()->removeItem(collide_items[i]);
            delete collide_items[i];
            return;

        }
    }

    // move bullet up (for move only)
    setPos(x(), y() - 13);

    if (pos().y() + 500 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
