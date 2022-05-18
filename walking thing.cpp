#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "sqaure.h"
square thing;
struct points {
    float x, y;
    points* next;// looks at the next thing;
   

    points() {
        x = NULL;
        y = NULL;
        next = NULL;
    };
    points(int newx, int newy,points* newthing, sf::RenderWindow& nextwind) {
        x = newx;
        y - newy;
        next = newthing;
        if (next != NULL) {
            next->drawat(nextwind);
        }
        else {
            std::cout << "end of linked list, f off\n";//this is a linkd of points- below main i will define the algorithm
            // and eventually impliment it into the code
        }
    }
    ~points() {//stops data leaks

    };
    void drawat(sf::RenderWindow& wind) {
        thing.x = this->x;
        thing.y = this->y;
        thing.draw(wind);
        wind.clear({0,0,0});

    };

};


int main()
{
    for (int o = 1; o <= 15; o++) {
        new points(5*o,5*5,);


    }


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Walking thing", sf::Style::None);
    window.setFramerateLimit(60);



    //window.clear //uncomment this to make clear screen, to stop screen from smudging 
    window.display();
}
/*
    if this-> x <next->x
        this->x ++;
    else if this->x > next -> x
        this-> x --;
    if-- do y



*/