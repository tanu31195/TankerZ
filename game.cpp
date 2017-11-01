#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QMediaPlayer>
#include <QImage>
#include "button.h"
#include <QDebug>

game::game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //add background image
    setBackgroundBrush(QBrush(QImage(":/images/resources/bg1.PNG")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/resources/bgsound1.mp3"));
    music->play();

}


void game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("TankerZ"));
    QFont titleFont("comic sans",60);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    button* playButton = new button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the help button
    button* helpButton = new button(QString("Help"));
    int hxPos = this->width()/2 - helpButton->boundingRect().width()/2;
    int hyPos = 350;
    helpButton->setPos(hxPos,hyPos);
    connect(helpButton,SIGNAL(clicked()),this,SLOT(help()));
    scene->addItem(helpButton);

    // create the quit button
    button* quitButton = new button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 425;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void game::start()
{
    // clears main menu
    scene->clear();

    //add background image
    setBackgroundBrush(QBrush(QImage(":/images/resources/bg2.jpg")));

    // create the player and set position
    Player = new player();
    Player->setPos(400,500);

    // set focus and add the player to the scene
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    scene->addItem(Player);

    // create the score/health and add them to the scene
    Score = new score();
    scene->addItem(Score);
    Health = new health();
    Health->setPos(Health->x(),Health->y()+25);
    scene->addItem(Health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),Player,SLOT(spawn()));
    timer->start(2000);

    // spawn health
    QTimer * timerr = new QTimer();
    QObject::connect(timerr,SIGNAL(timeout()),Player,SLOT(hspawn()));
    timerr->start(10000);

    connect(Health, SIGNAL(dead()), this, SLOT(end()) );
}

void game::help()
{
    scene->clear();

    // help screen text
    QString helpText =("-Move with the W, A, S and D keys- \n\n"
                       "-Shoot with space bar \n\n"
                       "-Place mines with M- \n\n"
                       "-You can only shoot powerups to increase health- \n\n"
                       "**Turn up your volume (there is music and sound effects!)**");

    // create help text
    QGraphicsTextItem* helpTextItem = new QGraphicsTextItem(helpText);

    QFont helpTextFont("comic sans",10);
    helpTextItem->setFont(helpTextFont);
    helpTextItem->setPos(200,200);
    scene->addItem(helpTextItem);

    // create the play button
    button* playButton = new button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 400;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);
}

void game::restartGame(){
    // clear scene then call start()
    scene->clear();
    start();
}
// draw panel with required values
void game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void game::end(){

    // game over screen message
    QString message;
    message = "Game Over!!!"  ;

    displayGameOverWindow(message);

}
void game::displayGameOverWindow(QString textToDisplay){

    // pop up semi transparent panel
    drawPanel(0,0,800,600,Qt::black,0.65);

    // draw panel
    drawPanel(200,150,400,300,Qt::lightGray,0.75);

    // create playAgain button
    button* playAgain = new button(QString("Play Again"));
    playAgain->setPos(300,275);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    button* quit = new button(QString("Quit"));
    quit->setPos(300,350);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create score text
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    QFont overTextFont("comic sans",20);
    overText->setFont(overTextFont);
    overText->setPos(310,200);
    scene->addItem(overText);

}
