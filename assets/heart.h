// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <string.h>
using namespace sf;
class Heart
{

public:

Texture tex;
Sprite sprite;
int x=340,y=340;

 Heart(std::string png_path) {
 
 	tex.loadFromFile(png_path);
            sprite.setTexture(tex);
            sprite.setScale(0.26,0.26);
 }
 Heart(){}

};
