// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
class Monster : public Enemy
{

public:
bool flag1;
bool flag2 , bulletFired=false , mon_position=false;

Monster(std::string png_path)
{

 b = new bomb("Images/PNG/Effects/fire00.png");
 
flag1=true;flag2=false;
isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=-2000;y=-2000;
sprite.setPosition(x,y);
sprite.setScale(0.15,0.15);

}
Monster() {}

 virtual void fire()
    {
       	
        	b->sprite.setPosition(sprite.getPosition().x+100  , sprite.getPosition().y);

    }
    
   virtual  void move_b(float& mon_time)
        {
       	        
                b->sprite.setPosition( -3000 , -3000); 
        }


virtual void move()
{
	
  if(sprite.getPosition().x<=0)
  { flag1=true;flag2=false; }
  if(flag1==true)
  sprite.move(5,0);

 if(sprite.getPosition().x>=600)
 { flag2=true;flag1=false; }
 if(flag2==true)
  sprite.move(-5,0);


}

virtual void destroy(int _x , int _y)
{

  if( _x <= sprite.getPosition().x+100 && _x >= sprite.getPosition().x-50  && _y <= sprite.getPosition().y && _y >= sprite.getPosition().y-60)
  isDestroyed = true;
 
}

virtual ~Monster()
{
if(b!=NULL)
{
  delete b;
  b = NULL;
}
}

};
