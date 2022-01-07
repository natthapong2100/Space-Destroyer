#include "Game.h"
#include "Effect_exhaust.h"
#include <QTimer>
#include <QGraphicsScene>

Effect_exhaust::Effect_exhaust(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/images/fx_exhaust.png"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(del()));
    timer->start(100);
}

void Effect_exhaust::del()
{
    scene()->removeItem(this);
    delete this;
}
