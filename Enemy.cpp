#include "Game.h"
#include "Enemy.h"
#include "Effect_explosion.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // for using rand(), it returns really large int

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set random position
    int random_number = rand() % 700; // limit to 700 (size of width screen)
    setPos(random_number, 0);

    if (game->score->getScore() > 20){
        setPixmap(QPixmap(":/images/pro_eb1.png"));
        blueCome = 1;
    }
    else{
        setPixmap(QPixmap(":/images/pro_eg1.png"));
    }

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); //Move caller func

    timer->start(50);
}

void Enemy::move(){
    QList<QGraphicsItem *> collide_items = collidingItems();
    for (int i = 0; i < collide_items.size(); ++i){
        if (typeid(*(collide_items[i])) == typeid(Player)){            
            game->health->decrease();

            // create FX explosion
            Effect_explosion *explosion = new Effect_explosion();
            explosion->setPos(x() - 5, y());
            scene()->addItem(explosion);

            // display Game over text
            if(game->health->getHealth() == 0){
                game->displayGameOver();
            }            

            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    if(blueCome == 1){
        setPos(x(), y() + 10); // blue enemy speed
    }
    else{
        setPos(x(), y() + 5);
    }


    if (pos().y() > 600){ // delete when Enemy out of screen
        scene()->removeItem(this);
        delete this;
    }
}

