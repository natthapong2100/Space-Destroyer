#include "Game.h"
#include "Effect_explosion.h"
#include <QTimer>
#include <QGraphicsScene>

Effect_explosion::Effect_explosion(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/fx_explosion.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(del()));
    timer->start(200);
}

void Effect_explosion::del()
{
    scene()->removeItem(this);
    delete this;
}
