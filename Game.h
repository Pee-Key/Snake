#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Menu.h"

class Game
{
    public:
        Game();

        void gameplay();

        ~Game();
    private:
        Snake &snake;
        Menu &menu;
};

#endif // GAME_H
