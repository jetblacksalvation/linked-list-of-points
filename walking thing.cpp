#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "sqaure.h"
square thing(0, 0, 4, 40, true, sf::Color::Blue);
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
        y = newy;
        next = newthing;
        if (next != NULL) {
            this->drawat(nextwind);
        }
        else {// this should NEVER be reached with how i have it set up!!!
            std::cout << "end of linked list, f off\n";//this is a linkd of points- below main i will define the algorithm
            // and eventually impliment it into the code
        }
    }
    ~points() {//stops data leaks

    };
    void drawat(sf::RenderWindow& wind) {
        if (next != NULL) {

            while (this->x != next->x and this->y != next->y) {
                thing.x = this->x;
                thing.y = this->y;
                thing.draw(wind);
                if (this->x < next->x) {
                    this->x++;
                }
                else if (this->x > next->x) {
                    this->x--;
                }
                if (this->y > next->y) {
                    this->y--;
                }
                else if (this->y < next->y) {
                    this->y++;
                }

                if (this->x == next->x and this->y == next->y) { std::cout << "exit condition reached\n"; return; }
            }

        }
        if (next == NULL) {
            std::cout << "is null\n";
        }
        
    };

};


int main()
{
    for (int o = 1; o <= 15; o++) {
  


    }


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Walking thing", sf::Style::None);
    window.setFramerateLimit(60);
    points* two = new points(100, 100, NULL, window);
    
    while (1) {

        window.clear({ 0,0,0 }); //uncomment this to make clear screen, to stop screen from smudging 
        window.display();
        points one(20, 20, two, window);
        one.drawat(window);
    }
}   
/*
    if this-> x <next->x
        this->x ++;
    else if this->x > next -> x
        this-> x --;
    if-- do y



*/
