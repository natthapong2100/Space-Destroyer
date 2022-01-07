#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect_fire.h"
#include "Effect_exhaust.h"
#include "Health.h"
#include "Game.h"
#include "SpecialBullet.h"
#include <QGraphicsScene>
#include <QKeyEvent>


extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/pro_pr1.png"));

}

void Player::keyPressEvent(QKeyEvent *event)
{
    int vel = 25;


    if (event->key() == Qt::Key_Space){
        if(game->health->getHealth() <= 1){
            SpecialBullet * bulletS = new SpecialBullet();
            bulletS->setPos(x() + 11, y() - 18);
            scene()->addItem(bulletS);
        }
        else{
            // create bullet
            Bullet *bullet = new Bullet();
            bullet->setPos(x() + 26, y() - 7); //set the coordinate when create obj at top-left of rect
            scene()->addItem(bullet); //display a bullet
        }


        // create FX fire
        Effect_fire *fire = new Effect_fire();
        fire->setPos(x() + 16, y() - 20);
        scene()->addItem(fire);

    }
    else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right
            || event->key() == Qt::Key_Up || event->key() == Qt::Key_Down){

        // create FX exhaust
        Effect_exhaust *exhaust = new Effect_exhaust();        

        if (event->key() == Qt::Key_Left && pos().x() > 0 + vel){
            setPos(x() - vel, y());            
        }
        else if (event->key() == Qt::Key_Right && pos().x() < 850 - 60 - vel){
        //because the width of player is 60
            setPos(x() + vel, y());            
        }
        else if (event->key() == Qt::Key_Up && pos().y() > 0 + vel){
            setPos(x(), y() - vel);            
        }
        else if (event->key() == Qt::Key_Down && pos().y() < 628 - 55 - vel){
            setPos(x(), y() + vel);            
        }
        exhaust->setPos(x() + 23, y() + 55); // player move first then create exhaust
        scene()->addItem(exhaust);

    }

}

void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}
