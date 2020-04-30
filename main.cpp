#include "Snake.h"
#include "Menu.h"
#include "Game.h"

int main()
{
    srand(time(NULL));

    Snake snake;
    Menu menu(snake);

    menu.game();

    return 0;
}
