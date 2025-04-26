// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
#include  "invader.h"
using namespace sf;
class Alpha : public Invader
{

public:


 Alpha(std::string png_path)
{

 b = new bomb("Images/bullet.png");

isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);


}
Alpha() {}

 virtual void fire()
    {
        b->fire(sprite.getPosition().x  , sprite.getPosition().y);
    }


virtual void destroy(int _x , int _y)
{

  if( _x <= sprite.getPosition().x+40 && _x >= sprite.getPosition().x-40  && _y <= sprite.getPosition().y+30 && _y >= sprite.getPosition().y-30)
 { isDestroyed = true; }
 
}

virtual ~Alpha()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
