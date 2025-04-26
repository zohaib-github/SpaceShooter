#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
class Beta : public Invader
{

public:


Beta(std::string png_path)
{

 b = new bomb("Images/bullet.png");

isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);

}
Beta() {}

 virtual void fire()
    {
        b->fire(sprite.getPosition().x  , sprite.getPosition().y);
    }


virtual void move()
{
   delta_x+=1;
sprite.move(delta_x,y);

}

virtual void destroy(int _x , int _y)
{

  if( _x <= sprite.getPosition().x+30 && _x >= sprite.getPosition().x-30  && _y <= sprite.getPosition().y+20 && _y >= sprite.getPosition().y-30)
  {isDestroyed = true;}
 
}

virtual ~Beta()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
