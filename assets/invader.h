#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
#include  "enemy.h"
using namespace sf;
class Invader : public Enemy
{

public:


Invader(std::string png_path)
{

 b = new bomb("Images/bullet.png");

isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);


}
Invader() {}

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
}



virtual ~Invader()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
