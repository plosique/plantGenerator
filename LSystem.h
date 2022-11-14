#include<string>
#include<vector>
#include<map>
#include<utility>
#include<iostream>

#include <SFML/Graphics.hpp>


sf::Vector2f R90(sf::Vector2f xy){
    return sf::Vector2f(-xy.y,xy.x);

}

sf::Vector2f R180(sf::Vector2f xy){
    return sf::Vector2f(-xy.x,-xy.y);

}

sf::Vector2f R270(sf::Vector2f xy){
    return sf::Vector2f(xy.y,-xy.x);

}

sf::Vector2f R(sf::Vector2f xy, float theta){
   return sf::Vector2f(sin(theta) ) 
}

class turtle{
    sf::Vector2f loc; 
    sf::Vector2f dir; 

    public:
        turtle(sf::Vector2f _loc, sf::Vector2f _dir) :loc(_loc), dir(_dir) {};

        sf::Vector2f getLoc(){
            return loc;
        }

        sf::Vector2f getDir(){
            return dir;
        }

        //update the turtle -- boolean indicates whether anything is actually drawn
        bool processSymbol(char symbol){
            bool res = false; 
            switch(symbol){
                case 'F':
                    loc+=dir;
                    res = true; 
                    break;
               case '-':
                    dir = R270(dir);
                    res = false;
                    break;
               case '+':
                    dir = R90(dir);
                    res = false;
                    break;
               default:
                    std::cerr<<"Unrecognized Symbol"<<std::endl;
            }
            return res; 
        }
};


//cf stands for context-free
class cfLSystem{
    std::map<char,std::string> productions;
    public:
        cfLSystem(std::vector<std::pair<char,std::string>> _productions){
            for(std::pair<char,std::string> production : _productions){
                productions.insert(production); 
            }
        }

        std::map<char,std::string> getProductions(){
            return productions; 
        }
};

std::string apply(std::string axiom,int depth,cfLSystem LSystem){
    std::string res = axiom;
    std::map<char,std::string> productions = LSystem.getProductions();
    for(int i=0;i<depth;i++){
        std::string resi = "";
        for(char c : res){
            if(productions.count(c)){
                resi+=productions[c]; 
            }else{
                resi+=c; 
            }
        }
        res = resi; 
    }
    return res; 
}

sf::VertexArray renderWord(std::string s,int startx, int starty){
    int numSymbols = s.size();  
    sf::VertexArray arr(sf::LinesStrip,numSymbols+1); 
    sf::Vector2f loc = sf::Vector2f(float(startx), float(starty));  
    sf::Vector2f dir(1,0);  
    arr[0] = loc;
    turtle todd(loc, dir);
    for(int i=0;i<numSymbols;i++){
        todd.processSymbol(s.at(i));
        arr[i+1].position =  todd.getLoc(); 
        arr[i+1].color = sf::Color::Green; 
    }
    
    return arr; 

}
