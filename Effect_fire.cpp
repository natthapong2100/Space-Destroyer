#include "Effect_fire.h"
#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
using namespace std;

extern Game * game;

Effect_fire::Effect_fire(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    if(game->health->getHealth() <= 1){
        setPixmap(QPixmap(":/images/fx_fire2.png"));
    }
    else{
        setPixmap(QPixmap(":/images/fx_fire1.png"));
    }

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(del()));
    timer->start(150);

}

void Effect_fire::del()
{
    scene()->removeItem(this);
    delete this;
}
