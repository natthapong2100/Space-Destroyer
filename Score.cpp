#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game * game;
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initialize the score to 0
    score = 0;
    setPlainText(QString("Score: " + QString::number(score)));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("arial", 20));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: " + QString::number(score)));

}

int Score::getScore()
{
    return score;
}

