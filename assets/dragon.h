// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>

using namespace sf;
class Dragon : public Enemy
{

public:


Dragon(std::string png_path)
{

 b = new bomb("Images/bullet.png");
b->speed=1;
isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=-2000;y=-2000;
sprite.setPosition(x,y);
//b->sprite.setPosition(-2000,-2000);
sprite.setScale(1,1);

}
Dragon() {}

   virtual void fire()
    {
        b->fire(sprite.getPosition().x  , sprite.getPosition().y);
    }

virtual void destroy(int _x , int _y)
{

  if( _x <= sprite.getPosition().x+190 && _x >= sprite.getPosition().x-190  && _y <= sprite.getPosition().y+100 && _y >= sprite.getPosition().y-100)
  isDestroyed = true;
 
}



virtual ~Dragon()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
