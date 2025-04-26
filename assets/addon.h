#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
class Add
{

public:

Texture tex;
Sprite sprite;
float speed=5;
int x=340,y=340;
bool istaken=false;
bool isReleased=false;

 Add() {}

virtual void position() {}
   
virtual void move() {}

virtual void taken(int _x , int _y) {}

virtual ~Add() {}

};
