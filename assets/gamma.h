#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
class Gamma : public Invader
{

public:


Gamma(std::string png_path)
{

 b = new bomb("Images/bullet.png");

isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);

}
Gamma() {}

 virtual void fire()
    {
        b->fire(sprite.getPosition().x  , sprite.getPosition().y);
    }




virtual void destroy(int _x , int _y)
{

  if( _x <= sprite.getPosition().x+40 && _x >= sprite.getPosition().x-40  && _y <= sprite.getPosition().y && _y >= sprite.getPosition().y-60)
  { isDestroyed = true;}
 
}

virtual ~Gamma()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
