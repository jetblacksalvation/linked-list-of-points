#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "sqaure.h"
square thing(0, 0, 4, 40, true, sf::Color::Blue);
struct points {
    float x, y;
    points* next;// looks at the next thing;
    int tag;
    
    points() {
        x = NULL;
        y = NULL;
        next = NULL;
        tag = NULL;
    };
    points(int newx, int newy,points* newthing ,int newtag) {
        x = newx;
        y = newy;
        next = newthing;
        tag = newtag;
        
    }
    ~points() {//stops data leaks

    };
    void drawat(sf::RenderWindow& wind) {
        if (next != NULL) {
            if (tag == 0 and tag + 1 != NULL) {

                while (this->x != next->x and this->y != next->y) {
                    thing.x = this->x;
                    thing.y = this->y;


                    if (this->x < next->x) {
                        this->x++;
                    }
                    else if (this->x > next->x) {
                        this->x--;
                    }
                    std::cout << thing.x << std::endl;
                    if (this->y > next->y) {
                        this->y--;
                    }
                    else if (this->y < next->y) {
                        this->y++;
                    }
                    std::cout << thing.y << std::endl;
                    if (this->x == next->x and this->y == next->y) { std::cout << "exit condition reached\n"; return; }
                    else {
                        //the bug is right here, the sqaure stays static 
                        wind.clear(sf::Color::White);
                        thing.draw(wind);
                        wind.display();
                        thing.update();

                    }
                }
            }

            
        }
        if (next == NULL) {
            std::cout << "is null\n";
        }
        
    };
    
};


int main()
{


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Walking thing", sf::Style::None);
    window.setFramerateLimit(60);

    points* three = new points(100, 1000, NULL, 2);
    points* two = new points(500, 500, three,1);//goal 
    
    while (1) {

        window.clear({ 255,255,255 }); //uncomment this to make clear screen, to stop screen from smudging 
        
        points one(20, 20, two,0);
        one.x = 20;

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
