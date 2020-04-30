#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <sstream>

class Snake
{
    public:
        Snake();

        int width,height;
        int sizeOfTexture;
        int widthX,heightX;
        int direction,length;
        int score;

        void Update();
        void Fruit();
        int countScore(int length);

        struct SnakeStruct
        { int x,y;}  s[289];

        struct Fruit
        { int x,y;} f;

        ~Snake();
    private:
};

#endif // SNAKE_H
