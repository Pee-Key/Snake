#include "Snake.h"

Snake::Snake(){

    this->width=15;
    this->height=15;
    this->sizeOfTexture = 64;
    this->widthX= width*sizeOfTexture;
    this->heightX= height*sizeOfTexture;
    this->length=4;
    this->s[0].x=2;
    this->s[0].y=2;

}

Snake::~Snake(){}

void Snake::Update()
 {
    for (int i=length;i>0;--i)
     {s[i].x=s[i-1].x; s[i].y=s[i-1].y;}

    if (direction==1) s[0].y-=1;
    if (direction==2) s[0].x-=1;
    if (direction==3) s[0].y+=1;
    if (direction==4) s[0].x+=1;




    for (int i=1;i<length;i++)
        if (s[0].x==s[i].x && s[0].y==s[i].y) {
            if(i>3){
                length=i;
            }
        }
    }

    void Snake::Fruit(){

        if ((s[0].x==f.x) && (s[0].y==f.y)) {

            f.x=rand()%13+1;
            f.y=rand()%13+1;
            length++;
            countScore(length);
        }
    }

    int Snake::countScore(int length){

        int score = length*10-40;

        return score;
    }
