#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "sqaure.h"
square thing(0, 0, 4, 40, true, sf::Color::Blue);

struct points {
public:
    int x, y;
    points() : x(NULL), y(NULL) {};
    points(int x , int y):x(x),y(y) {};
};

class linked_points {
private:
    int* arr_x;
    int* arr_y;
    int size; 

public:
    linked_points() {
        arr_x = NULL;
        arr_y = NULL;
        size = NULL;
    };
    linked_points(std::initializer_list<int> list) {
        arr_x = (int*)malloc(int(list.size() / 2) * sizeof(int));// this is not working, instead, make to heap allocated integer arrays
        arr_y = (int*)malloc(int(list.size() / 2) * sizeof(int));
        size = list.size();




        if (list.size() % 2 == 0) {
            
        }
        else {
            exit;
        }
        int count = 1;
        
        int secondcount = 0;
        for (auto elem : list) {// x comma y
            
               
                if (count %3 == 1) {
                    arr_x[secondcount] = elem;
                }
                else if (count % 3 ==2) {
                    arr_x[secondcount ] = elem;
                }
                else if (count %3 ==0 ) {
                    secondcount++;
                }
                
                count += 1;
                

            
            

           
        }


    }
    void draw_to_points(sf::RenderWindow& wind) {
        square* ptr = new square(0,0,4,20,true,sf::Color::Black);
        ptr->x = arr_x[0];
        ptr->y = arr_y[0];






        std::cout << ptr->x<<" is x \n" << std::endl;
        std::cout << ptr->y<<" is y \n" << std::endl;
        int tempcount = 0;

        while (tempcount <= size) {
            std::cout << sizeof(arr_x) << std::endl << std::endl;
        }

        while (tempcount <= size) {
            
            tempcount++;
            if (ptr->x < arr_x[tempcount]) {
                ptr->x ++;
            }
            else if (ptr->x > arr_x[tempcount]) {
                ptr->x--;
            }
            if (ptr->y < arr_y[tempcount]) {
                ptr->y++;
            }
            else if (ptr->y > arr_y[tempcount]) {
                ptr-> y--;
            }
            if (ptr->y == arr_y[tempcount] and ptr->x == arr_x[tempcount]) {
                tempcount++;
            }
            
            //drawing logic;
            wind.clear(sf::Color::White);
            ptr->draw(wind);
            ptr->update();
            
            
            wind.display();

        };
        
        //end draw
        


    };
};




//wind.clear(sf::Color::White);
//thing.draw(wind);
//wind.display();
//thing.update();
int main()
{


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Walking thing", sf::Style::None);
    window.setFramerateLimit(60);

        
    while (1) {
        linked_points bruh({ 0,0, 50,50 , 100, 20 });
        bruh.draw_to_points(window);
    }
}   
/*
    if this-> x <next->x
        this->x ++;
    else if this->x > next -> x
        this-> x --;
    if-- do y



*/
