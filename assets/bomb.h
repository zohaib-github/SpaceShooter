// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;


class bomb {
public:
    
   Texture tex;
        Sprite sprite;
        bool bulletFired = false;
        float speed=5 , tilted_move=0;
       
        int x,y;
        bomb()
        {}
        bomb(std::string png_path){
            tex.loadFromFile(png_path);
            sprite.setTexture(tex);
            sprite.setScale(0.3,0.8);
        }
       
        void move()
        {
            if(bulletFired)
            {  
                sprite.move( 0 , speed);
                if(sprite.getPosition().y > 800) bulletFired=false;
                
            } 
        }
        
       void fire(int x , int y) 
      {
        if (!bulletFired) 
        {
            bulletFired = true;
            sprite.setPosition(x,y);         
        }
      }

 
};
