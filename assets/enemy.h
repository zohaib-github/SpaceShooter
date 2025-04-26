// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
#include  "bomb.h"
using namespace sf;
class Enemy
{

public:

bomb* b;
Texture tex;
Sprite sprite;
float speed=5;
int x,y,delta_x=1;
bool isDestroyed , bulletFired , mon_position; // this bulletfired is for monster only

 Enemy() {}

virtual void fire() {}
   
virtual void move() {}

virtual void move_b(float&){} // for monster only

virtual void destroy(int _x , int _y) {}

virtual ~Enemy() {}

};
