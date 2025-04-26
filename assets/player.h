// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
#include<string.h>
#include  "bullet.h"
#include "powerup.h"
#include "lives.h"
#include "fire.h"
#include "danger.h"
using namespace sf;
class Player
{

public:

Bullet* b[16];
Bullet* b2[7];
Bullet* b3[7]; 
Add* pow;
Add* liv;
Add* dan;
Add* fir;
Texture tex;
Sprite sprite;
float speed=20;
int x,y;
bool isDestroyed;
Player(std::string png_path , Add* p , Add* l , Add* d , Add* f , Bullet* a[] , Bullet* e[] , Bullet* c[])
{
	
for (int i = 0; i < 16; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < 7; i++) {
        b2[i] = e[i];
    }
    for (int i = 0; i < 7; i++) {
        b3[i] = c[i];
    }
	pow = p;
	liv = l;
	dan = d;
	fir = f;

isDestroyed=false;
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);

}

    void fire()
    {
        for(int i=0;i<16;i++)
	{	
		if(!b[i]->bulletFired)
		{
		b[i]->sprite.setPosition(sprite.getPosition().x  , sprite.getPosition().y );
		b[i]->bulletFired=true;
		break;
		}
	}
    }
    
    void fire2(sf::Sound& sound)
    {
    	for(int i=0;i<7;i++)
	{	
		if(!b2[i]->bulletFired)
		{
		sound.play();
		b2[i]->sprite.setPosition(sprite.getPosition().x   , sprite.getPosition().y  );
		b2[i]->bulletFired=true;
		
		}
	}
    }
    void fire3(sf::Sound& sound)
    {
   
    	for(int i=0;i<7;i++)
	{	
		if(!b3[i]->bulletFired)
		{	
		sound.play();	
		b3[i]->sprite.setPosition(sprite.getPosition().x + 40  , sprite.getPosition().y );
		b3[i]->bulletFired=true;
		}
	}
    }


void move(std::string s)
{


float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;
else if(s=="r")
	delta_x=1;
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;
	
if(s=="Dright")
{
tex.loadFromFile("Images/plane_right.png");
sprite.setTexture(tex);
}
else if(s=="Dleft")
{
tex.loadFromFile("Images/plane_left.png");
sprite.setTexture(tex);
}
else
{
tex.loadFromFile("Images/player_ship.png");
sprite.setTexture(tex);
}

// wrap-around Environment code //
if(sprite.getPosition().x <= -100)
        sprite.setPosition(sprite.getPosition().x + 780 + 100 , sprite.getPosition().y);
    
else if(sprite.getPosition().x > 780 )
        sprite.setPosition(sprite.getPosition().x - 780 - 100, sprite.getPosition().y);
    
if(sprite.getPosition().y < -100) 
        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 780 + 100 );
    
else if(sprite.getPosition().y > 780 )
        sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 780 - 100);
// wrap-around Environment code end //

delta_x*=speed;
delta_y*=speed;


sprite.move(delta_x, delta_y);

}

void destroy(int _x , int _y, int& life)
{



  if( _x <= sprite.getPosition().x+50 && _x >= sprite.getPosition().x-50  && _y <= sprite.getPosition().y && _y >= sprite.getPosition().y-60)
  isDestroyed = true;
  if( _x <= sprite.getPosition().x+70 && _x >= sprite.getPosition().x-70  && _y <= sprite.getPosition().y+70 && _y >= sprite.getPosition().y-70)
  isDestroyed = true;
  
   
  if(isDestroyed == true)
  { life -= 1; isDestroyed=false;}
}



};
