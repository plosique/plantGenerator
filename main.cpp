#include "LSystem.h"
#include<vector> 
#include<iostream>


int main(){
    std::vector<std::pair<char,std::string>> productions(2);
    productions[0] = std::make_pair('a',"ab");
    productions[1] = std::make_pair('b',"a");

    cfLSystem LSystem(productions);
    for(int i=0;i<7;i++){
        std::string output = apply("a", i, LSystem);
        std::cout<<output<<std::endl;
    }
    return 0;
}
