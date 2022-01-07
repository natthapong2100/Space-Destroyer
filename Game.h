#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QString>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QObject>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Bullet.h"
#include "Button.h"
#include "Effect_fire.h"
#include "Enemy.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    int sceneWidth, sceneHeight;
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Enemy * enemy;

    void displayMainMenu();
    void displayGameOver();

public slots:
    void start();

};

#endif // GAME_H
