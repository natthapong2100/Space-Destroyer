#include "Health.h"
#include "Game.h"
#include <QFont>

extern Game * game;
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3; // start game with health = 3
    setPlainText(QString("Health: " + QString::number(health)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial", 20));
}

void Health::decrease(){
    if(gameOver()){
        health = 0; // always show 0 when health decrease and game over
        setPlainText(QString("Health: " + QString::number(health)));
    }
    else if(health <= 2){
        health--;
        setPlainText(QString("Health: " + QString::number(health) + "\nSpecial Bullet ON"));
    }
    else{
        health--;
        setPlainText(QString("Health: " + QString::number(health)));
    }

}

int Health::getHealth(){
    return health;
}

bool Health::gameOver()
{
    if(health >= 1){
        return 0;
    }
    else{
        return 1;
    }
}
