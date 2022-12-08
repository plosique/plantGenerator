#ifndef PARSER_H
#define PARSER_H

#include<string> 
#include<fstream>
#include<utility>
#include<iostream> 

struct Arguments{
   int n;
   float delta;
   std::string axiom; 
   std::vector<std::pair<char,std::string>> productions;
   std::map<char,char> aliases; 
};

void print(const Arguments &arguments){
   std::cout<<"n: "<<arguments.n<<" delta: "<<arguments.delta<<"\n"; 
   std::cout<<"axiom: "<<arguments.axiom<<"\n"; 
   for(std::pair<char, std::string> production : arguments.productions){
    std::cout<<production.first<<" "<<production.second<<"\n"; 
   }
   for(std::pair<char,char> alias : arguments.aliases){
     std::cout<<alias.first<<" "<<alias.second<<"\n";
   }
}


Arguments parse(std::ifstream &fractFile){
  Arguments arguments;
  fractFile >> arguments.n;
  fractFile >> arguments.delta;
  fractFile >> arguments.axiom; 
  int numProductions;
  fractFile >> numProductions; 
  for(int i=0;i<numProductions;i++){
    char key;
    fractFile >> key;
    std::string dummy;
    fractFile >> dummy; 
    std::string value;
    fractFile >> value; 
    arguments.productions.push_back(std::make_pair(key,value)); 

  }

  int numAliases;
  fractFile >> numAliases;
  for(int i=0;i<numAliases;i++){
    char key;
    fractFile >> key;
    std::string replacedBy;
    fractFile >> replacedBy;
    char value;
    fractFile >> value; 
    arguments.aliases.insert(std::make_pair(key,value)); 
  }

  return arguments;
}

#endif
