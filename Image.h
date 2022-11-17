#include <SFML/Graphics.hpp>



void scale(sf::VertexArray &va,float scalingFactor){
    for(unsigned int i=0;i<va.getVertexCount();i++){
        va[i].position*=scalingFactor; 
    }
}

void translate(sf::VertexArray &va,sf::Vector2f translation){
    for(unsigned int i=0;i<va.getVertexCount();i++){
        va[i].position+=translation; 
    }
}

void scaleAndCenter(sf::VertexArray &va, int dimx,int dimy){
    float fdimx = float(dimx);
    float fdimy = float(dimy);
    float minx,maxx,miny,maxy; 
    minx = va[0].position.x;
    maxx = minx;
    miny = va[0].position.y;
    maxy = miny;
    for(unsigned int i=0;i<va.getVertexCount();i++){
        sf::Vertex v = va[i]; 
        maxy = std::max(maxy,v.position.y);
        maxx = std::max(maxx,v.position.x);
        minx = std::min(minx,v.position.x);
        miny = std::min(miny,v.position.y);
    }
    sf::Vector2f translation0(-minx,-miny);
    translate(va,translation0);


    float scalingFactor = ((4*fdimx)/5)/(maxx-minx);
    scale(va,scalingFactor);

    sf::Vector2f translation1(fdimx/10,fdimy/10);
    translate(va,translation1);

    
}
