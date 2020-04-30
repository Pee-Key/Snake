#ifndef MENU_H
#define MENU_H

#include "Snake.h"

class Menu
{
    public:
        Menu();
        Menu(Snake &snake);

        float difficulty;

        sf::Texture menuT, diffT, menuST, menuBT, menuCT, menuQT;
        sf::Texture diffET, diffNT, diffHT;
        sf::Texture creatorT,youLoseT;

        sf::Sprite menu, diff, startGame, bestScores, creators, quit;
        sf::Sprite easy, normal, hard;
        sf::Sprite creatorM, lose;

        void drawMenu(sf::RenderWindow &window);
        void chooseDifficulty(sf::RenderWindow &window);
        float setDiff(float difficulty);
        void creatorMenu(sf::RenderWindow &window);
        void youLose(sf::RenderWindow &window);

        void game();


        ~Menu();
    private:
        Snake &snake;
};

#endif // MENU_H
