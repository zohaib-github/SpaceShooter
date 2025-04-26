#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
#include <string.h>
using namespace sf;
class Live : public Add
{

public:



 Live() {}
 
 	 Live(std::string png_path){
  
            tex.loadFromFile(png_path);
            sprite.setTexture(tex);
            sprite.setPosition(-300,-100);
            sprite.setScale(1.5,1.5);
        }

virtual void position() {
	
	if(!isReleased)
      {	
	 x = rand()%700;
	
	sprite.setPosition(x,0);
	isReleased=true;
      }
	
}
   
virtual void move() {
	
	if(isReleased)
            {
                sprite.move( 0 , speed);
                
                if(sprite.getPosition().y > 780) 
                isReleased=false;
                
            } 
	
}

virtual void taken(int _x , int _y) {

	if( _x <= sprite.getPosition().x+50 && _x >= sprite.getPosition().x-50  && _y <= sprite.getPosition().y && _y >= sprite.getPosition().y-60)
	istaken=true;
}

virtual ~Live() {}

};
