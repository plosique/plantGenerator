#include<string>
#include<vector>
#include<map>
#include<utility>


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

