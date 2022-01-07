#include "Game.h"
#include "Enemy.h"
#include "Button.h"
#include "Enemy.h"
#include "Effect_fire.h"
#include <QTimer>
#include <QFont>


Game::Game(QWidget *parent)
{
    sceneWidth = 850;
    sceneHeight = 628;

    // set up Screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sceneWidth, sceneHeight);

    // set up Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 850, 628);
    setBackgroundBrush(QBrush(QImage(":/images/pro_bg1.png")));
    setScene(scene);

}

void Game::displayMainMenu()
{
    // create the Title text
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Rocket Destroyer"));
    QFont titleFont("Helvetica", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::white);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 250;
    titleText->setPos(xPos, yPos);
    scene->addItem(titleText);

    // create Play Button
    Button * playButtton = new Button(QString("Play Game"));
    int pxPos = width()/2 - titleText->boundingRect().width()/2 + 90;
    int pyPos = 330;
    playButtton->setPos(pxPos, pyPos);
    connect(playButtton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButtton);

    // create Quit button
    Button * quitButtton = new Button(QString("Quit"));
    int qxPos = width()/2 - titleText->boundingRect().width()/2 + 90;
    int qyPos = 380;
    quitButtton->setPos(qxPos, qyPos);
    connect(quitButtton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButtton);

}

void Game::start()
{
    // clear the screen
    scene->clear();

    // create Player
    player = new Player();
    player->setPos(400, 500);
    //make player focusable (make player accept the key pressed)
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // create Score and Health
    score = new Score();
    score->setPos(50, 50);
    scene->addItem(score);
    health = new Health();
    health->setPos(50, 75);
    scene->addItem(health);

    // spawn 1st Enemy
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player,SLOT(spawn()));
    timer->start(500);

    // spawn 2nd Enemy
    QTimer * timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()), player,SLOT(spawn()));
    timer2->start(1000);

    show();
}

void Game::displayGameOver()
{
    // create "Game Over" Text
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Game Over !!"));
    QFont titleFont("Helvetica", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::red);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 220;
    titleText->setPos(xPos, yPos);
    scene->addItem(titleText);

    // create score text
    QGraphicsTextItem * scoreText = new QGraphicsTextItem(QString("Your Score: ")+QString::number(score->getScore()));
    QFont scoreFont("Helvetica", 30);
    scoreText->setFont(scoreFont);
    scoreText->setDefaultTextColor(Qt::green);
    int xsPos = width()/2 - scoreText->boundingRect().width()/2;
    int ysPos = 280;
    scoreText->setPos(xsPos, ysPos);
    scene->addItem(scoreText);

    // create Play again Button
    Button * playAgainButtton = new Button(QString("Play again"));
    int pa_xPos = width()/2 - titleText->boundingRect().width()/2 + 50;
    int pa_yPos = 345;
    playAgainButtton->setPos(pa_xPos, pa_yPos);
    connect(playAgainButtton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playAgainButtton);

    // create Quit button
    Button * quitButtton = new Button(QString("Quit"));
    int qxPos = width()/2 - titleText->boundingRect().width()/2 + 50;
    int qyPos = 395;
    quitButtton->setPos(qxPos, qyPos);
    connect(quitButtton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButtton);
}

