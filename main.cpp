/*
    Name: Natthapong Lueangphumphitthaya
    ID Number: 63011208
*/

#include <QApplication>
#include "Game.h"

Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    game = new Game();
    game->show();
    game->displayMainMenu(); // menu caller func

    return a.exec();

}
