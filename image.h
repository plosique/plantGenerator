#ifndef IMAGE_H
#define IMAGE_H

#include <SFML/Graphics.hpp>
#include<iostream>

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

    float ry = maxy - miny;
    float rx = maxx - minx; 

    float r;
    float fdim;
    if(ry>rx){
      r = ry;
      fdim = fdimy; 
    }else{
      r = rx;
      fdim = fdimx; 
    }

    float scaler = 4./5.; 

    float scalingFactor = (scaler*fdim)/r;
    scale(va,scalingFactor);

    sf::Vector2f translation1(fdimx/2-((scaler*fdim)/(2*r))*rx,fdimy/2. - ((scaler*fdim)/(2*r)*ry));
    translate(va,translation1);

    
}

#endif
