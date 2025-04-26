
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;


class Bullet {
public:
    
   Texture tex;
        Sprite sprite;
        bool bulletFired = false;
        float speed=20 , tilted_move=0;      
        int x,y;
        
        Bullet()
        {}
        
        Bullet(std::string png_path){
            tex.loadFromFile(png_path);
            sprite.setTexture(tex);
            sprite.setScale(0.3,0.5);
        }
       
        void move()
        {
            if(bulletFired)
            {
                sprite.move( tilted_move , -speed);
                if(sprite.getPosition().y < -100) bulletFired=false;
            } 
        }
        
         void move2(float _x , float _y)
        {
            if(bulletFired)
            {
                sprite.move( _x , -_y);
                if(sprite.getPosition().y < -100) bulletFired=false;
            } 
        }
        
       void fire2(int x , int y) 
      {
        if (!bulletFired) 
        {
            bulletFired = true;
            sprite.setPosition(x,y);         
        }
      }
      

   
};
