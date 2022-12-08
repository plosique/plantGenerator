#include "lsystem.h"
#include "image.h"
#include "parser.h" 

#include <vector> 
#include <iostream>
#include <string> 
#include <fstream> 

#include <SFML/Graphics.hpp>


int main(const int argc, const char *argv[]){
    if(argc!=2){
      std::cout << "Usage ./fractal fractal_file" << std::endl; 
       return 0; 
    }

    std::ifstream inputFile;
    inputFile.open(argv[1],std::ios::in);
   
    Arguments arguments = parse(inputFile); 

    const int dimx = 500;
    const int dimy = 500;

    cfLSystem LSystem(arguments.productions);
    std::string word = apply(arguments.axiom, arguments.n, LSystem,arguments.aliases);
    sf::VertexArray vArr =  renderWord(word,arguments.delta); 
    scaleAndCenter(vArr,dimx,dimy);

    sf::RenderWindow window(sf::VideoMode(dimx, dimy), "Fractal Generator!");
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
