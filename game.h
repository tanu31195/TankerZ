#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"

class game: public QGraphicsView{
    Q_OBJECT

public:
    game(QWidget * parent=0);

    void displayMainMenu();
    void displayGameOverWindow(QString textToDisplay);

    QGraphicsScene * scene;
    player * Player;
    score * Score;
    health * Health;

public slots:
    void start();
    void help();
    void restartGame();
    void end();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};

#endif // GAME_H
