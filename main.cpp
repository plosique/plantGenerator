#include "LSystem.h"
#include<vector> 
#include<iostream>
#include <SFML/Graphics.hpp>


int main(){
    std::vector<std::pair<char,std::string>> productions(1);
    productions[0] = std::make_pair('F',"F-F+F+FF-F-F+F");

    cfLSystem LSystem(productions);
    std::string axiom = "F-F-F-F"; 
    std::string word = apply(axiom, 3, LSystem);
    sf::VertexArray vArr =  renderWord(word,100,100,90); 

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        window.draw(vArr);
        window.display();
    }

    return 0;
}
