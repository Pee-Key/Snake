#include "Menu.h"

Menu::Menu(Snake &snake):snake(snake){

    this->difficulty=0;

    menuT.loadFromFile("background-menu.png");
    diffT.loadFromFile("back-difficulty1.png");
    menuST.loadFromFile("Start Game.png");
    menuBT.loadFromFile("Best scores.png");
    menuCT.loadFromFile("Creators.png");
    menuQT.loadFromFile("Quit.png");
    diffET.loadFromFile("Easy.png");
    diffNT.loadFromFile("Normal.png");
    diffHT.loadFromFile("Hard.png");
    creatorT.loadFromFile("creator.png");
    youLoseT.loadFromFile("lose.png");

    menu.setTexture(menuT);
    diff.setTexture(diffT);
    startGame.setTexture(menuST);
    bestScores.setTexture(menuBT);
    creators.setTexture(menuCT);
    quit.setTexture(menuQT);
    easy.setTexture(diffET);
    normal.setTexture(diffNT);
    hard.setTexture(diffHT);
    creatorM.setTexture(creatorT);
    lose.setTexture(youLoseT);

}


Menu::~Menu(){}

void Menu::drawMenu(sf::RenderWindow &window){

    bool menuNeed = true;
    int menuAction =0;

    startGame.setPosition(320,320);
    bestScores.setPosition(320,448);
    creators.setPosition(320,576);
    quit.setPosition(320,704);


    sf::Event event;
  while (window.pollEvent(event))
  {
   if (event.type == sf::Event::Closed)
    window.close();
  }
    while(menuNeed == 1){

        startGame.setColor(sf::Color::White);
        bestScores.setColor(sf::Color::White);
        creators.setColor(sf::Color::White);
        quit.setColor(sf::Color::White);

        menuAction = 0;

        if (sf::IntRect(320,320,320,64).contains(sf::Mouse::getPosition(window))) {
            startGame.setColor(sf::Color::Red);
            menuAction = 1;
        }
        if (sf::IntRect(320,448,320,64).contains(sf::Mouse::getPosition(window))) {
            bestScores.setColor(sf::Color::Red);
            menuAction = 2;
        }
        if (sf::IntRect(320,576,320,64).contains(sf::Mouse::getPosition(window))) {
            creators.setColor(sf::Color::Red);
            menuAction = 3;
        }
        if (sf::IntRect(320,704,320,64).contains(sf::Mouse::getPosition(window))) {
            quit.setColor(sf::Color::Red);
            menuAction = 4;
        }



        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            if (menuAction == 1) {menuNeed = false; chooseDifficulty(window); }
            if (menuAction == 2) {menuNeed = false;}
            if (menuAction == 3) {menuNeed = false; creatorMenu(window);}
            if (menuAction == 4) {window.close(); menuNeed = false; }
        }

            window.draw(menu);
            window.draw(startGame);
            window.draw(bestScores);
            window.draw(creators);
            window.draw(quit);

        window.display();
    }

}

void Menu::chooseDifficulty(sf::RenderWindow &window){

    sf::Clock clock;

    bool diffneed = true;
    int diffchoose = 0;

    easy.setPosition(320,320);
    normal.setPosition(320,448);
    hard.setPosition(320,576);

    sf::Event event;
    while (window.pollEvent(event))
    {
    if (event.type == sf::Event::Closed)
        window.close();
      }

    while(diffneed == 1){

            easy.setColor(sf::Color::White);
            normal.setColor(sf::Color::White);
            hard.setColor(sf::Color::White);

            diffchoose = 0;

        if(sf::IntRect(320,320,320,64).contains(sf::Mouse::getPosition(window))){
            easy.setColor(sf::Color::Red);
            diffchoose = 1;

        }
        if(sf::IntRect(320,448,320,64).contains(sf::Mouse::getPosition(window))){
            normal.setColor(sf::Color::Red);
            diffchoose = 2;
        }
        if(sf::IntRect(320,576,320,64).contains(sf::Mouse::getPosition(window))){
            hard.setColor(sf::Color::Red);
            diffchoose = 3;
        }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){

        if (diffchoose == 1){difficulty = 0.2; diffneed = false;}
        if (diffchoose == 2){difficulty = 0.15; diffneed = false;}
        if (diffchoose == 3){difficulty = 0.1; diffneed = false;}

    }
    window.draw(diff);
    window.draw(easy);
    window.draw(normal);
    window.draw(hard);

    window.display();
    }

}

float Menu::setDiff(float diff){

    return difficulty = diff;

}

void Menu::youLose(sf::RenderWindow &window){

     while(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)!= true){

    window.draw(lose);

    window.display();
    }
    drawMenu(window);
}


void Menu::creatorMenu(sf::RenderWindow &window){

    while(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)!= true){
    window.draw(creatorM);

    window.display();
    }

    drawMenu(window);

}

void Menu::game(){

    sf::RenderWindow window(sf::VideoMode(snake.widthX, snake.heightX), "Snake Game!");
    window.setFramerateLimit(60);

    drawMenu(window);


    sf::Font font;
    font.loadFromFile("RAVIE.TTF");
    sf::Text scoreout;
    scoreout.setFont(font);
    scoreout.setColor(sf::Color::Red);
    scoreout.setPosition(snake.widthX/2-32,16);

    sf::Texture headT, backT, fruitT;
    headT.loadFromFile("red.png");
    backT.loadFromFile("background.png");
    fruitT.loadFromFile("fruit.png");

    sf::Sprite head(headT);
    head.scale(4.f,4.f);
    sf::Sprite background(backT);
    sf::Sprite fruit(fruitT);

    sf::Clock clock;
    float timer=0;

    snake.f.x=2;
    snake.f.y=5;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        std::ostringstream scr;
        scr << snake.countScore(snake.length);
        scoreout.setString(scr.str());

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) snake.direction=1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) snake.direction=2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) snake.direction=3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) snake.direction=4;

        if (timer>difficulty) {timer=0; snake.Update(); snake.Fruit();}

        if (snake.s[0].x>(snake.width-2) || snake.s[0].x<1 || snake.s[0].y>(snake.height-2) || snake.s[0].y<1) {std::cout<<"you hit the wall"<<std::endl; youLose(window);}



    window.clear();

    window.draw(background);
    window.draw(scoreout);


    for (int i=0;i<snake.length;i++){
        head.setPosition(snake.s[i].x*snake.sizeOfTexture, snake.s[i].y*snake.sizeOfTexture);
         {window.draw(head);}
    }

    fruit.setPosition(snake.f.x*snake.sizeOfTexture, snake.f.y*snake.sizeOfTexture);  window.draw(fruit);

    window.display();
    }
}


