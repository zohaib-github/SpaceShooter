// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "player.h"
#include "alpha.h"
#include "beta.h"
#include "gamma.h"
#include "monster.h"
#include "dragon.h"
#include "heart.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;
using namespace std;

class Game
{

public:
Sprite background; //Game background sprite
Texture bg_texture;
Sprite paus;
Texture _paus;
Player* p; //player 
Bullet* b[16];
Bullet* b2[7];
Bullet* b3[7]; 
Enemy* enemy[3][20];
Enemy* dra;
Enemy* mon;
Add* pow;
Add* liv;
Add* dan;
Add* fir;
Heart* h[10];
bool flag , flagm , flagi , flagd , flagpow , _p , flagliv , flagdan , flagfir ,flaglif, got_pow , got_liv, got_dan, got_fir , pause_end , mon_alive , mon_fire,generator , setposition , dra_alive , dra_fire,generator2 , setposition2;
int time_m,life,col,level,index;
bool enmy[3][20];

Game()
{
	for(int i=0;i<10;i++)
	h[i] = new Heart("Images/plane_right.png");
	
pow = new Power("Images/PNG/Power-ups/powerupBlue_bolt.png");
    		
	liv = new Live("Images/PNG/Power-ups/pill_red.png");
		
	dan = new Danger("Images/PNG/Power-ups/powerupRed.png");
		
	fir = new Fire("Images/PNG/Power-ups/things_gold.png");
	
	for(int i=0;i<16;i++)
	{	
  		b[i] = new Bullet("Images/bullet.png");
	}
	for(int i=0;i<7;i++)
	{	
  		b2[i] = new Bullet("Images/bullet.png");
  		b2[i]->sprite.setPosition(3000,3000);
	} 
	for(int i=0;i<7;i++)
	{	
  		b3[i] = new Bullet("Images/PNG/Effects/fire02.png");
  		b3[i]->sprite.setScale(2,2);
  		b3[i]->sprite.setPosition(3000,3000);
	} 

   p=new Player("Images/player_ship.png" , pow , liv , dan , fir , b , b2 , b3);
mon=new Monster("Images/monster.png");
	mon->b->sprite.setPosition(-2000,-2000);
	

col=20;
	for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

dra=new Dragon("Images/dragon.png");
dra->b->speed=5;
dra->b->sprite.setPosition(-2000,-2000);

_paus.loadFromFile("Images/Space 1.jpg");
paus.setTexture(_paus);
paus.setScale(1, 0.35);
flag=false;
flagi=false;
flagm=false;
flagd=false;
_p = true;
flagpow=false;
flagliv=false;
flagdan=false;
flagfir=false;
got_pow = false;
got_dan = false;
got_liv = false;
got_fir = false;
flaglif=false;
pause_end=false;
mon_alive=false;
mon_fire=true;
generator=false;
setposition=false;
dra_alive=false;
dra_fire=true;
generator2=false;
setposition2=false;
life=3;
level=0;
index=0;

}


void start_game(RenderWindow& window , int LeveL , int& SCORE)
{

//////////////////////////////////////  Initializing Invaders Of All Types  [[START]] //////////////////////////////////////////////////////////////////////////
int l=life;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("Images/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("Images/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("Images/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}



//////////////////////////////////////  Initializing Invaders Of All Types  [[END]]  //////////////////////////////////////////////////////////////////////////


sf::SoundBuffer buffer;
if (!buffer.loadFromFile("Music/destroy.ogg"))   
    cout<<"failed"; // error
sf:: Sound sound;
sound.setBuffer(buffer);

sf::SoundBuffer buffer2;
if (!buffer2.loadFromFile("Music/kill.wav"))   
    cout<<"failed"; // error
sf:: Sound sound2;
sound2.setBuffer(buffer2);

sf::SoundBuffer buffer3;
if (!buffer3.loadFromFile("Music/shoot.wav"))   
    cout<<"failed"; // error
sf:: Sound sound3;
sound3.setBuffer(buffer3);


Text text,text1,text2,text3,text4, gameover_text;
    srand(time(0));
    Clock clock;
    float timer=0,delay=0.6,time_p=0,time_addons=0,time_pow=0,time_fir=0,time_alp=0,time_beta=0,time_gama=0,stop=0 , mon_time=0,dra_time , t_m=0,t_d=0 , over_time=0 , elapsedTime=0 , elapsedTime2=0, interval=0,interval2=0 , monster_time=0, dragon_time=0;
    int pause=0,number=-5,count=0,lev,indb=0,indg=0 , score=0 , back_menu=0;
    bool bg=true;
    
    lev=LeveL;
    while (window.isOpen())
    {
 
 SCORE = score;
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time; 
        
        time_p+=time;
       
   
 	Event e;
        while (window.pollEvent(e))
        {  
       
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left) && flag==false) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)  && flag==false) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)  && flag==false) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down) && flag==false) // If down key is pressed
            p->move("d");  //player will move downwards
        if (((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Left))) && flag==false) // If down key is pressed
            p->move("Dright");  
        if (((Keyboard::isKeyPressed(Keyboard::Up) && Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Down) && Keyboard::isKeyPressed(Keyboard::Right))) && flag==false) // If down key is pressed
            p->move("Dleft");        
        if ( flag==false && time_p>=0.5 && got_pow!=true && got_fir!=true ) 
          { 
           	//sound3.play(); 
           	p->fire(); 
           	time_p=0;
          }    
          
    	
    	if (Keyboard::isKeyPressed(Keyboard::P))
    		 pause=1;
    	
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\  Extra Settings////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    	
    	
    	if(lev>=1 && lev<4 && bg==true)
{
bg_texture.loadFromFile("Images/bg1.jpg");
background.setTexture(bg_texture);
background.setScale(1.2, 0.6);
level=1;
bg=false;
}

else if(lev>=4 && lev<7 && bg==true)
{
bg_texture.loadFromFile("Images/bg2.jpg");
background.setTexture(bg_texture);
background.setScale(1.2, 0.6);
level=2;
bg=false;
}

else if(lev>=7 && bg==true)
{
bg_texture.loadFromFile("Images/bg3.jpg");
background.setTexture(bg_texture);
background.setScale(1.2, 0.6);
level=3;
bg=false;
}

h[0]->sprite.setPosition(75,14);h[1]->sprite.setPosition(115,16);h[2]->sprite.setPosition(145,16);h[3]->sprite.setPosition(180,16);
h[4]->sprite.setPosition(215,16);h[5]->sprite.setPosition(250,16);h[6]->sprite.setPosition(285,16);h[7]->sprite.setPosition(325,16);
h[8]->sprite.setPosition(355,16);h[9]->sprite.setPosition(390,16);
            
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\PAUSE AND RESUME////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 
            if(pause==1)
            {
        
        sf::Music music;
if (!music.openFromFile("Music/menu.ogg"))    // background music
    cout<<"error loading music"<<endl; // error
music.play();
sf::Music music1;
if (!music1.openFromFile("Music/shatter.ogg"))    // background music
    cout<<"error loading music"<<endl; // error
music1.setVolume(100.0f);
        
        Font font;
        font.loadFromFile("font/Plaguard-ZVnjx.otf");
        
        Text text3;
        text3.setFont(font);
        text3.setString("SPACE SHOOTER");
        text3.setCharacterSize(60);
        text3.setFillColor(Color::White);
        text3.setPosition(180, 70);
        Text text;
        text.setFont(font);
        text.setString("Resume Game");
        text.setCharacterSize(40);
        text.setFillColor(Color::White);
        text.setPosition(270, 225);
        Text text4;
        text4.setFont(font);
        text4.setString("Restart Game");
        text4.setCharacterSize(40);
        text4.setFillColor(Color::White);
        text4.setPosition(270, 300);
        Text text2;
        text2.setFont(font);
        text2.setString("Instructions");
        text2.setCharacterSize(40);
        text2.setFillColor(Color::White);
        text2.setPosition(270, 375);
        Text text1;
        text1.setFont(font);
        text1.setString("Exit");
        text1.setCharacterSize(40);
        text1.setFillColor(Color::White);
        text1.setPosition(270, 450);

	
	while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed)
                {
                
                    if (text.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                        pause=0;
                    	break;
                    }
                    else if (text4.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                   	back_menu = 1;
                   	break;
                    }
                    else  if (text2.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                        window.close();
                    }
                    else  if (text1.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                        window.close();
                    }
                
               }
            
            }
            if(pause==0)
            break;
            if(back_menu==1)
            break;
            
            if (text.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text.setFillColor(sf::Color::Red); // Change the text color to red
    	    else
            text.setFillColor(sf::Color::White);
            
            if (text1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text1.setFillColor(sf::Color::Red); // Change the text color to red
    	    else
            text1.setFillColor(sf::Color::White);
            
            if (text2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text2.setFillColor(sf::Color::Red); // Change the text color to red
    	    else
            text2.setFillColor(sf::Color::White);
            
            if (text4.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text4.setFillColor(sf::Color::Red); // Change the text color to red
    	    else
            text4.setFillColor(sf::Color::White);
            
            		window.clear();
                        window.draw(paus); 
            		window.draw(text);
             		window.draw(text1);
             		window.draw(text2);
               		window.draw(text3);
               		window.draw(text4);
            		window.display();
             
        }
        if(back_menu==1)
            break;
                    }
            	
            
            
            
            
            
            
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\    TIMER AND LIFE DISPLAY   ////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
            
           
             Font font;
        font.loadFromFile("font/Plaguard-ZVnjx.otf");
        
         
        
        std::ostringstream ssScore;        
           ssScore<<"SCORE: "<<score;
        text2.setFont(font);
        text2.setString(ssScore.str());
        text2.setCharacterSize(20);
        text2.setFillColor(Color::White);
        text2.setPosition(20, 50);
        std::ostringstream ttimer;        
           ttimer<<"LIFE:  ";
        text1.setFont(font);
        text1.setString(ttimer.str());
        text1.setCharacterSize(20);
        text1.setFillColor(Color::White);
        text1.setPosition(20, 20);
        std::ostringstream llevel;        
           llevel<<"LEVEL: "<<level;
        text.setFont(font);
        text.setString(llevel.str());
        text.setCharacterSize(20);
        text.setFillColor(Color::White);
        text.setPosition(20, 80);
        std::ostringstream mmonster; 
           mmonster<<"Upcoming Monster: "<<monster_time<<endl;
        text3.setFont(font);
        text3.setString(mmonster.str());
        text3.setCharacterSize(20);
        text3.setFillColor(Color::White);
        text3.setPosition(440, 15);
        std::ostringstream monster; 
           monster<<"Upcoming Dragon: "<<dragon_time<<endl;
        text4.setFont(font);
        text4.setString(monster.str());
        text4.setCharacterSize(20);
        text4.setFillColor(Color::White);
        text4.setPosition(440, 45);
        
        
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\PLAYER FUNCTIONS////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 int lifes=life;
 
 	if(flag==false && got_pow==true )
 	{
 	time_pow += time;
 	 	
 		p->fire2(sound3);
      		p->b2[0]->move2(2 , 30);
      		p->b2[1]->move2(0.14 , 30);
      		p->b2[2]->move2(0.7 , 30);
      		p->b2[3]->move2(-2 , 30);
      		p->b2[4]->move2(-0.14 , 30);
      		p->b2[5]->move2(-0.7 , 30);
      		p->b2[6]->move2(0 , 30);
 	}
 	if(flag==false && got_fir==true )
 	{
 	time_fir += time;
 		p->fire3(sound3);
      		p->b3[0]->move2(2 , 30);
      		p->b3[1]->move2(0.14 , 30);
      		p->b3[2]->move2(0.7 , 30);
      		p->b3[3]->move2(-2 , 30);
      		p->b3[4]->move2(-0.14 , 30);
      		p->b3[5]->move2(-0.7 , 30);
      		p->b3[6]->move2(0 , 30);
      		
 	}
 	
	
	
       if( flag==false && got_pow==false)
       {   
      		for(int i=0;i<16;i++)
      		{
      		  p->b[i]->move();
      		}
       }
     	  if(flag==true)
          {
            for(int i=0;i<16;i++)
            {
              if(b[i]->bulletFired)
              {
                b[i]->move();
              }
            }
            if(got_pow==true)
            {
            	for(int i=0;i<7;i++)
             	{
              		if(b2[i]->bulletFired)
              		{
                	b2[i]->move();
              		}
            	}
            }
             if(got_fir==true)
            {
            	for(int i=0;i<7;i++)
             	{
              		if(b3[i]->bulletFired)
              		{
                	b3[i]->move();
              		}
            	}
            }
          }
      
       bool li=false;
	if(flag==false)
{
		if(flagi==false && mon_alive==false)
	 {
	 	for(int i=0;i<3;i++)
	 	for(int j=0;j<col;j++)
	 	if(!enmy[i][j])
	 	if( enemy[i][j]->b->sprite.getPosition().x <= p->sprite.getPosition().x+40 && enemy[i][j]->b->sprite.getPosition().x >= p->sprite.getPosition().x-40  && enemy[i][j]->b->sprite.getPosition().y <= p->sprite.getPosition().y+60 && enemy[i][j]->b->sprite.getPosition().y >= p->sprite.getPosition().y-80)
 	 		{ li=true;flaglif=true;}
 	 		
 	 		for(int i=0;i<3;i++)
 	 		for(int j=0;j<col;j++)
 	 		if(!enmy[i][j])
 	 	if( enemy[i][j]->sprite.getPosition().x <= p->sprite.getPosition().x+60 && enemy[i][j]->sprite.getPosition().x >= p->sprite.getPosition().x-40  && enemy[i][j]->sprite.getPosition().y <= p->sprite.getPosition().y+40 && enemy[i][j]->sprite.getPosition().y >= p->sprite.getPosition().y-40)
 	 		{ li=true; flaglif=true;}	
		
	 }	
	 
		if(flagm==false)
	{
		if( mon->b->sprite.getPosition().x <= p->sprite.getPosition().x+25 && mon->b->sprite.getPosition().x >= p->sprite.getPosition().x-15  && mon->b->sprite.getPosition().y <= p->sprite.getPosition().y+40 && mon->b->sprite.getPosition().y >= p->sprite.getPosition().y-760)
		{ li=true;flaglif=true;}
		if( mon->sprite.getPosition().x <= p->sprite.getPosition().x+65 && mon->sprite.getPosition().x >= p->sprite.getPosition().x-180  && mon->sprite.getPosition().y <= p->sprite.getPosition().y+80 && mon->sprite.getPosition().y >= p->sprite.getPosition().y-200)
 	 		{ li=true; flaglif=true;}
	}	
		if(flagd==false)
	{	
	
		if( dra->b->sprite.getPosition().x <= p->sprite.getPosition().x+25 && dra->b->sprite.getPosition().x >= p->sprite.getPosition().x-15  && dra->b->sprite.getPosition().y <= p->sprite.getPosition().y+40 && dra->b->sprite.getPosition().y >= p->sprite.getPosition().y-40)
		{ li=true;flaglif=true;}
		if( dra->sprite.getPosition().x <= p->sprite.getPosition().x+65 && dra->sprite.getPosition().x >= p->sprite.getPosition().x-180  && dra->sprite.getPosition().y <= p->sprite.getPosition().y+80 && dra->sprite.getPosition().y >= p->sprite.getPosition().y-200)
 	 		{ li=true; flaglif=true;}
	}
	
if( p->dan->sprite.getPosition().x <= p->sprite.getPosition().x+50 && p->dan->sprite.getPosition().x >= p->sprite.getPosition().x-50  && p->dan->sprite.getPosition().y <= p->sprite.getPosition().y && p->dan->sprite.getPosition().y >= p->sprite.getPosition().y-20)
 { li=true; flaglif=true;}
		
		if(li==true)
		life-=1;	
		
		if( life<=0 && got_pow==false)
		{
		
		sound2.play();
		  delete p;
		   p=NULL;
		   flag=true;
        gameover_text.setFont(font);
        gameover_text.setString("GAME OVER");
        gameover_text.setCharacterSize(40);
        gameover_text.setFillColor(Color::White);
        gameover_text.setPosition(270, 375);
        	break;	
		}
		 if(life>0 && li==true)
		{
			p->sprite.setPosition(340,700);
			li=false;
		}
}
	if(flag==true)
	over_time+=time;
	
	if(over_time>5)
	break;		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\  ADD_ON FUNCTIONS   ////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 
 		
 		time_addons+=time;
 		int t = time_addons;

 	if(t % 5 == 0 && t!=0 && _p!=false)
 	{ number = rand() % 5;  time_addons=0;}
 	
 	if(number==1 && flag==false)
 {		if(_p==true && flag==false)
 		{
 			
 			p->pow->position();
 			flagpow = false;
 			_p=false;
 		}
 		
 		if(flagpow == false && flag==false)
 		{
 			p->pow->move();
 			if(!p->pow->isReleased && flag==false)
 		       {	
 			p->pow->sprite.setPosition(-300,-100);
 			 flagpow=true;
 			 _p=true;
 			time_addons=0;
 			 number=-5;
 		       } 
 		}
 }		
 		
 
        if(number==2 && flag==false)
 {		if(_p==true && flag==false)
 		{
 		
 			p->liv->position();
 			flagliv = false;
 			_p=false;
 		}
 		
 		if(flagliv == false && flag==false)
 		{
 			p->liv->move();
 			if(!p->liv->isReleased && flag==false)
 			{
 			
 			p->liv->sprite.setPosition(-300,-100);
 			 flagliv=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }
 

 	if(number==3 && flag==false)		
 {		if(_p==true && flag==false)
 		{
 			
 			p->dan->position();
 			flagdan = false;
 			_p=false;
 			
 		}
 		
 		if(flagdan == false && flag==false)
 		{
 			p->dan->move();
 			if(!p->dan->isReleased && flag==false)
 			{
 			    p->dan->sprite.setPosition(-300,-100);
 			    score+=5;
 			 flagdan=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }		
 	if(number==4 && flag==false)
 {		if(_p==true && flag==false)
 		{
 			
 			p->fir->position();
 			flagfir = false;
 			_p=false;
 			
 		}
 		
 		if(flagfir == false && flag==false)
 		{
 			p->fir->move();
 			if(!p->fir->isReleased && flag==false)
 			{
 			     p->fir->sprite.setPosition(-300,-100);
 			 flagfir=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }		
 
 if(number==1 && flag==true)
 {		if(_p==true && flag==true)
 		{
 			
 			pow->position();
 			flagpow = false;
 			_p=false;
 		}
 		
 		if(flagpow == false && flag==true)
 		{
 			pow->move();
 			if(!pow->isReleased && flag==true)
 		       {	
 			pow->sprite.setPosition(-300,-100);
 			 flagpow=true;
 			 _p=true;
 			time_addons=0;
 			 number=-5;
 		       } 
 		}
 }		
 		
 
        if(number==2 && flag==true)
 {		if(_p==true && flag==true)
 		{
 		
 			liv->position();
 			flagliv = false;
 			_p=false;
 		}
 		
 		if(flagliv == false && flag==true)
 		{
 			liv->move();
 			if(!liv->isReleased && flag==true)
 			{
 			
 			liv->sprite.setPosition(-300,-100);
 			 flagliv=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }
 

 	if(number==3 && flag==true)		
 {		if(_p==true && flag==true)
 		{
 			
 			dan->position();
 			flagdan = false;
 			_p=false;
 			
 		}
 		
 		if(flagdan == false && flag==true)
 		{
 			dan->move();
 			if(!dan->isReleased && flag==true)
 			{
 			   dan->sprite.setPosition(-300,-100);
 			 flagdan=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }		
 	if(number==4 && flag==true)
 {		if(_p==true && flag==true)
 		{
 			
 			fir->position();
 			flagfir = false;
 			_p=false;
 			
 		}
 		
 		if(flagfir == false && flag==true)
 		{
 			fir->move();
 			if(!fir->isReleased && flag==true)
 			{
 			   fir->sprite.setPosition(-300,-100);
 			 flagfir=true;
 			 _p=true;
 			 time_addons=0;
 			 number=-5;
 			}
 		}
 }		
	/////////////////////////////////////////////     PowerUp   /////////////////////////////////////////////////////////////////////////////////// 
	
 		 if(flag==false && flagpow==false )
 		{
 		
 		  p->pow->taken(p->sprite.getPosition().x , p->sprite.getPosition().y);		 
 		  got_pow = p->pow->istaken;
 		  
		}
		
		if(flag==false && got_pow==true )
		p->pow->sprite.setPosition(-300,-100);
	
		if(time_pow>=5 && flag==false)
		{
			p->pow->istaken=false;
			got_pow=false;
			time_addons=0;
			time_pow=0;
		}
		
		if(got_pow==true && flaglif==true)
		{
			life = lifes;
			flaglif = false;
		}
		
		
	/////////////////////////////////////////////     LIFE   /////////////////////////////////////////////////////////////////////////////////// 
		
		
		if(flag==false && flagliv==false)
 		{
 		 	 p->liv->taken(p->sprite.getPosition().x , p->sprite.getPosition().y);		 
 		 	 got_liv = p->liv->istaken;
		}
		
		if(flag==false && got_liv==true)
		{
			p->liv->sprite.setPosition(-300,-100);
			p->liv->istaken = false;
			got_liv=false;
			life += 1;
			_p=true;
			time_addons=0;
			flagliv=true;
		}
		
		
	/////////////////////////////////////////////     Danger   /////////////////////////////////////////////////////////////////////////////////// 
	
		if(flag==false && flagdan==false )
 		{
 		 	 p->dan->taken(p->sprite.getPosition().x , p->sprite.getPosition().y);		 
 		 	 got_dan = p->dan->istaken;
		}
		if(flag==false && got_dan==true)
		{
			p->dan->sprite.setPosition(-300,-100);
			p->dan->istaken = false;
			got_dan=false;
			_p=true;
			time_addons=0;
			flagdan=true;
		}
	/////////////////////////////////////////////     FIRE       /////////////////////////////////////////////////////////////////////////////////// 
	
 		 if(flag==false && flagfir==false)
 		{
 		
 		  p->fir->taken(p->sprite.getPosition().x , p->sprite.getPosition().y);		 
 		  got_fir = p->fir->istaken;
 		  
		}
		
		if(flag==false && got_fir==true)
		p->fir->sprite.setPosition(-300,-100);
	
		if(time_fir>=5 && flag==false)
		{
			p->fir->istaken=false;
			got_fir=false;
			time_addons=0;
			time_fir=0;
		}	
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\   ENEMY FUNCTIONS    ////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 	
/////////////////////////////////////////////////////    Invader     ////////////////////////////////////////////////////////////////////////////////////

stop+=time;

if(!mon_alive && !dra_alive)					
shapes(lev , enemy , enmy , bg , time , time_alp ,time_beta,time_gama ,index , indb , indg , stop);
	
	else
	{
		for(int j=0;j<col;j++)
		if(!enmy[0][j])
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
if(!enmy[1][j])
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
if(!enmy[2][j])
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

	}
	
	if(!mon_alive && !dra_alive)
	{
		for(int i=0;i<16;i++)
		{
			for(int k=0;k<3;k++)
			for(int j=0;j<col;j++)
			if(!enmy[k][j])
		 	{
		 		enemy[k][j]->destroy(b[i]->sprite.getPosition().x , b[i]->sprite.getPosition().y);
				if(enemy[k][j]->isDestroyed)
				{
				   b[i]->bulletFired = false;
				   break;
				}
				if(b[i]->bulletFired == false)
				break;
			}
			if(b[i]->bulletFired == false)
				break;
		}
		
		for(int i=0;i<7;i++)
		{
			for(int k=0;k<3;k++)
			for(int j=0;j<col;j++)
			if(!enmy[k][j])
		{	
		  enemy[k][j]->destroy(b2[i]->sprite.getPosition().x , b2[i]->sprite.getPosition().y);
		  if(enemy[k][j]->isDestroyed)
				{
				   b2[i]->bulletFired = false;
				}
		 } 
		  for(int k=0;k<3;k++)
		  for(int j=0;j<col;j++)
		  if(!enmy[k][j])
		  enemy[k][j]->destroy(b3[i]->sprite.getPosition().x , b3[i]->sprite.getPosition().y);
		}
		
		for(int i=0;i<3;i++)
		for(int j=0;j<col;j++)
		if(!enmy[i][j])
		if(enemy[i][j]->isDestroyed==true)
		{
		sound.play();
		 delete enemy[i][j];
		enemy[i][j] = NULL;
		enmy[i][j] = true;		
		
		 	if(lev>0 && lev<4)
			{
				if(i==0)
				score+=10;
				if(i==1)
				score+=20;
				if(i==2)
				score+=30;
			}
			if(lev>3 && lev<7)
			{
				if(i==0)
				score+=20;
				if(i==1)
				score+=40;
				if(i==2)
				score+=60;
			}
			if(lev>6 && lev<10)
			{
				if(i==0)
				score+=30;
				if(i==1)
				score+=60;
				if(i==2)
				score+=90;
			}
		
		}
		
	}
	
	////////////////////////////////////////////    Monster     //////////////////////////////////////////////////////////////////////
	
	monster_time -= time;
	
	elapsedTime += time;
    
    if(generator==false)
    {      
    
        elapsedTime = 0; 
        interval = rand() % 60 + 1; 
        monster_time = interval;
        generator=true;
    }
    
	
	if(elapsedTime > interval)
	{ mon_alive = true;  }
	
	if(flagm==false && mon_alive == true)		// flagm will be true if monster destroys
     {
     		
     		mon_time+=time;
		mon->b->speed=5;
		mon->b->sprite.setScale(1.5,20);
		
		
	if(mon_time>2)
	{
	
		mon_fire = true;
	}
	else
	{
	 mon->b->sprite.setPosition(-2000,-2000);
	}
	if(mon_fire)
	{
	   mon->fire();
	   t_m+=time;
	   mon_time=0;
	}
	if(t_m>3)
	{ t_m=0; mon_fire=false; mon_time=0; }
	
 	 mon->move(); 
	 if(!setposition)
	{ mon->sprite.setPosition(40,100); setposition=true; }
		for(int i=0;i<16;i++)
		{
		  mon->destroy(b[i]->sprite.getPosition().x , b[i]->sprite.getPosition().y);
		}
		
		if(mon->isDestroyed==true)
		{
		
		sound.play();
		cout<<"jkadg"<<endl;
		  delete mon;
		  cout<<"jkadg2"<<endl;
		   mon=NULL;
		mon_alive = false;
		  
		  generator=false;
		  setposition=false;
		   score+=40;
		mon = new Monster("Images/monster.png");
		}
		
		if(elapsedTime > interval + 15)
		{
		  mon_alive = false;
		  mon->sprite.setPosition(-2000,-2000);
		  mon->b->sprite.setPosition(-2000,-2000);
		  mon->mon_position=false;
		  generator=false;
		  setposition=false;
		}
    }  

	////////////////////////////////////////////    Dragon     //////////////////////////////////////////////////////////////////////
	
	dragon_time -= time;
	elapsedTime2 += time;
	
	if(generator2==false)
    {      
        elapsedTime2 = 0; 
        interval2 = rand() % 60 + 1; 
        dragon_time = interval2;
        generator2=true;
    }
    
	
	if(elapsedTime2 > interval2)
	{ dra_alive = true;  }
	
	if(flagd==false && dra_alive == true)		// flagm will be true if monster destroys
     {
     		
     		dra_time+=time;
		
	if( dra->b->bulletFired==false )
	dra->fire();
	dra->b->move(); 	
	
	
	 if(!setposition2)
	{ dra->sprite.setPosition(340,100); dra->sprite.setScale(1,1); dra->b->sprite.setPosition(390,110);setposition2=true; }
		for(int i=0;i<16;i++)
		{
		  dra->destroy(b[i]->sprite.getPosition().x , b[i]->sprite.getPosition().y);
		}
		
		if(dra->isDestroyed==true)
		{
		
		sound.play();
		  delete dra;
		   dra=NULL;
		   score+=40;
		dra = new Dragon("Images/dragon.png");
		dra_alive = false;
		  dra->sprite.setPosition(-2000,-2000);
		  dra->b->sprite.setPosition(-2000,-2000);
		  dra->b->bulletFired = false;
		  generator2=false;
		  setposition2=false;
		}
		
		if(elapsedTime2 > interval2 + 15)
		{
		  dra_alive = false;
		  dra->sprite.setPosition(-2000,-2000);
		  dra->b->sprite.setPosition(-2000,-2000);
		  generator2=false;
		  setposition2=false;
		  dra->b->bulletFired = false;
		}
    }  
	
/*	if(flagd==false )
 	
       {
	if( dra->b->bulletFired==false )
	dra->fire();
	dra->b->move(); 
	}
	if(flagd==false && flag==false )
	{
		for(int i=0;i<16;i++)
		{
		  dra->destroy(p->b[i]->sprite.getPosition().x , p->b[i]->sprite.getPosition().y);
		}
		
		if(dra->isDestroyed==true)
		{
		sound.play();
		  delete dra;
		   dra=NULL;
		flagd=true;
		}
	}  
*/
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
 ////////////////////////\\\\\\\\\\\\\\\\\\\\\\\WINDOW FUNCTIONS////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
  
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	
	if ( flag==false)
	window.draw(p->sprite);   // setting player on screen
	
	 if (flag==false && got_pow==false)
	 {
	 	for(int i=0;i<7;i++)
	 	{
	 	 p->b2[i]->sprite.setPosition(-300,-300); 
	 	}
	 	for(int i=0;i<16;i++)
	 	{
	 	 	if(p->b[i]->bulletFired)
       			window.draw(p->b[i]->sprite); 
	 	}
	}
	if (flag==false && got_pow==true)
	 {
	 	
	 	for(int i=0;i<16;i++)
	 	{
	 	 p->b[i]->sprite.setPosition(-300,-300); 
	 	}
	 	for(int i=0;i<7;i++)
	 	{
	 	 	if(p->b2[i]->bulletFired)
       			window.draw(p->b2[i]->sprite); 
	 	}
	}
	
	if (flag==false && got_fir==false)
	 {
	 	for(int i=0;i<7;i++)
	 	{
	 	 p->b3[i]->sprite.setPosition(-300,-300); 
	 	}
	 	for(int i=0;i<16;i++)
	 	{
	 	 	if(p->b[i]->bulletFired)
       			window.draw(p->b[i]->sprite); 
	 	}
	}
	if (flag==false && got_fir==true)
	 {
	 	
	 	for(int i=0;i<16;i++)
	 	{
	 	 p->b[i]->sprite.setPosition(-300,-300); 
	 	}
	 	for(int i=0;i<7;i++)
	 	{
	 	 	if(p->b3[i]->bulletFired)
       			window.draw(p->b3[i]->sprite); 
	 	}
	}
	
	for(int i=0;i<3;i++)
	for(int j=0;j<col;j++)
	{	
		if(!enmy[i][j])
		{
		window.draw(enemy[i][j]->sprite);
         	window.draw(enemy[i][j]->b->sprite);
         	}
         }
   
    
         if(flagm==false)
		{ window.draw(mon->sprite);
        	 window.draw(mon->b->sprite);
         }
         
         if(flagd==false)
         {
	window.draw(dra->sprite);
         window.draw(dra->b->sprite);
         }


	if(life>=1)window.draw(h[0]->sprite);
	if(life>=2)window.draw(h[1]->sprite);
	if(life>=3)window.draw(h[2]->sprite);
	if(life>=4)window.draw(h[3]->sprite);
	if(life>=5)window.draw(h[4]->sprite);
	if(life>=6)window.draw(h[5]->sprite);
	if(life>=7)window.draw(h[6]->sprite);
	if(life>=8)window.draw(h[7]->sprite);
	if(life>=9)window.draw(h[8]->sprite);
	if(life>=10)window.draw(h[9]->sprite);	
	
	if( !flagpow && flag==false)
	window.draw(p->pow->sprite);
	
	if( !flagliv && flag==false)
	window.draw(p->liv->sprite);
	
	if( !flagdan && flag==false)
	window.draw(p->dan->sprite);
	
	if(!flagfir && flag==false)
	window.draw(p->fir->sprite);
	
	if( !flagpow && flag!=false)
	window.draw(pow->sprite);
	
	if( !flagliv && flag!=false)
	window.draw(liv->sprite);
	
	if( !flagdan && flag!=false)
	window.draw(dan->sprite);
	
	if(!flagfir && flag!=false)
	window.draw(fir->sprite);

	if(flag==true)
	{
	    for(int i=0;i<16;i++)
	 	{
	 	 	if(b[i]->bulletFired)
       			window.draw(b[i]->sprite); 
	 	}
	 	for(int i=0;i<7;i++)
	 	{
	 	 	if(b2[i]->bulletFired)
       			window.draw(b2[i]->sprite); 
	 	}
	 	for(int i=0;i<7;i++)
	 	{
	 	 	if(b3[i]->bulletFired)
       			window.draw(b3[i]->sprite); 
	 	}
	}

	window.draw(text1);
	window.draw(text2);
	if(monster_time>0)
	window.draw(text3);
	window.draw(text);
	if(dragon_time>0)
	window.draw(text4);
	window.draw(gameover_text);
	window.display();  //Displying all the sprites
    }


  }

void shapes(int &lev , Enemy* enemy[3][20] , bool enmy[3][20] , bool &bg , float& time , float& time_alp,float& time_beta,float& time_gama,int &index,int &indb,int &indg , float& stop)
{

int count=0,col=20;


					///////////////////////////////////////////
					////////////    Rectangle   ///////////////
					///////////////////////////////////////////
    if(lev==1)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(170,100); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(570,100); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(170,300); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(570,300); count++; }
if(!enmy[1][4])
{ enemy[1][4]->sprite.setPosition(230,100); count++; }
if(!enmy[1][5])
{ enemy[1][5]->sprite.setPosition(500,100); count++; }
if(!enmy[1][6])
{ enemy[1][6]->sprite.setPosition(370,100); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(290,100); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(430,100); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(290,310); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(430,310); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(160,170); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(560,170); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(160,240); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(560,240); count++; }
if(!enmy[0][4])
{ enemy[0][4]->sprite.setPosition(230,310); count++; }
if(!enmy[0][5])
{ enemy[0][5]->sprite.setPosition(500,310); count++; }
if(!enmy[0][6])
{ enemy[0][6]->sprite.setPosition(370,310); count++; }



time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<6;i++)
     {
	 index = rand()%6 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<4;i++)
     {
	 indg = rand()%4 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<7;i++)
     {
	 indb = rand()%7 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}


}
if(lev==1)
{
if(count<=0)
{

lev=2;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("Images/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("Images/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("Images/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

bg=true;
count=0;
time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
stop=0;
indg=0;
}
else if(count>0)
{ count=0; lev=1; }
}
					///////////////////////////////////////////
					////////////    Triangle   ////////////////
					///////////////////////////////////////////
if(lev==2 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(170,400); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(290,400); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(430,400); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(570,400); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(350,110); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(280,210); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(430,210); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(220,300); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(490,300); count++; }

time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<4;i++)
     {
	 index = rand()%4 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<1;i++)
     {
	 indg = 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<4;i++)
     {
	 indb = rand()%4 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}

}
if(lev==2 && stop>=5)
{
 if(count<=0)
{
lev=3;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

bg=true;
time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
stop=0;
count=0;
}
else if(count>0)
{ count=0; lev=2; }
}
					///////////////////////////////////////////
					////////////    CROSS SIGN   //////////////
					///////////////////////////////////////////
		
if(lev==3 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(200,80); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(300,180);count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(500,380); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(600,480); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(400,280); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(200,490); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(300,390); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(500,190); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(600,90); count++; }
time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<4;i++)
     {
	 index = rand()%4 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<1;i++)
     {
	 indg = 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<4;i++)
     {
	 indb = rand()%4 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==3 && stop>=5)
{
 if(count<=0)
{
lev=4;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

bg=true;
time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
stop=0;
count=0;
}
else if(count>0)
{ count=0; lev=3; }
}		
						
					
					///////////////////////////////////////////
					//////////////    CIRCLE   ////////////////
					///////////////////////////////////////////


if(lev==4 && stop>=8)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(450,120); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(520,180); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(460,430); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(530,370); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(360,90); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(360,480); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(170,270); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(550,270); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(270,120); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(220,180); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(260,450); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(200,370); count++; }
time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<4;i++)
     {
	 index = rand()%4 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<4;i++)
     {
	 indg = rand()%4 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<4;i++)
     {
	 indb = rand()%4 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==4 && stop>=8)
{
 if(count<=0)
{
lev=5;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

bg=true;
time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
count=0;
stop=0;
}
else if(count>0)
{ count=0; lev=4; }
}		
	


                                        ///////////////////////////////////////////
					//////////////    Heart     ///////////////
					///////////////////////////////////////////

if(lev==5 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(150,130); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(560,140); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(520,250); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(470,300); count++; }
if(!enmy[1][4])
{ enemy[1][4]->sprite.setPosition(420,350); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(210,90); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(280,130); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(420,130); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(500,90); count++; }
if(!enmy[2][4])
{ enemy[2][4]->sprite.setPosition(350,400); count++; }
if(!enmy[2][5])
{ enemy[2][5]->sprite.setPosition(350,170); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(140,210); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(560,210); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(190,260); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(240,310); count++; }
if(!enmy[0][4])
{ enemy[0][4]->sprite.setPosition(290,360); count++; }
time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<5;i++)
     {
	 index = rand()%5 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<6;i++)
     {
	 indg = rand()%6 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<5;i++)
     {
	 indb = rand()%5 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==5 && stop>=5)
{
 if(count<=0)
{
lev=6;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}

time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
count=0;
stop=0;
}
else if(count>0)
{ count=0; lev=5; }
}		
	
	
					///////////////////////////////////////////
					//////////////    Diamond   ///////////////
					///////////////////////////////////////////

if(lev==6 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(250,170); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(470,170); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(480,280); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(430,330); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(360,380); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(200,240); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(510,230); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(360,70); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(250,290); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(300,340); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(300,120); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(420,120); count++; }
time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<4;i++)
     {
	 index = rand()%4 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<4;i++)
     {
	 indg = rand()%4 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<4;i++)
     {
	 indb = rand()%4 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==6 && stop>=5)
{
 if(count<=0)
{
lev=7;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}
bg=true;
time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
stop=0;
count=0;
}
else if(count>0)
{ count=0; lev=6; }
}		

					///////////////////////////////////////////
					///////////    Diamond filled   ///////////
					///////////////////////////////////////////


if(lev==7 && stop>=8)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(250,170); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(470,170); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(480,280); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(430,330); count++; }
if(!enmy[1][4])
{ enemy[1][4]->sprite.setPosition(310,170); count++; }
if(!enmy[1][5])
{ enemy[1][5]->sprite.setPosition(370,170); count++; }
if(!enmy[1][6])
{ enemy[1][6]->sprite.setPosition(420,170); count++; }
if(!enmy[1][7])
{ enemy[1][7]->sprite.setPosition(360,120); count++; }


if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(360,380); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(200,235); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(510,230); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(360,70); count++; }
if(!enmy[2][4])
{ enemy[2][4]->sprite.setPosition(280,235); count++; }
if(!enmy[2][5])
{ enemy[2][5]->sprite.setPosition(430,235); count++; }
if(!enmy[2][6])
{ enemy[2][6]->sprite.setPosition(360,235); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(250,290); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(300,340); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(300,120); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(420,120); count++; }
if(!enmy[0][4])
{ enemy[0][4]->sprite.setPosition(310,290); count++; }
if(!enmy[0][5])
{ enemy[0][5]->sprite.setPosition(370,290); count++; }
if(!enmy[0][6])
{ enemy[0][6]->sprite.setPosition(420,290); count++; }
if(!enmy[0][7])
{ enemy[0][7]->sprite.setPosition(360,340); count++; }

time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<8;i++)
     {
	 index = rand()%8 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<7;i++)
     {
	 indg = rand()%7 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<8;i++)
     {
	 indb = rand()%8 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==7 && stop>=8)
{
 if(count<=0)
{
lev=8;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}


time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
stop=0;
count=0;
}
else if(count>0)
{ count=0; lev=7; }
}		
				
				
					///////////////////////////////////////////
					//////////////    Heart filled     ////////
					///////////////////////////////////////////

if(lev==8 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(150,130); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(560,140); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(520,250); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(470,300); count++; }
if(!enmy[1][4])
{ enemy[1][4]->sprite.setPosition(420,350); count++; }
if(!enmy[1][5])
{ enemy[1][5]->sprite.setPosition(420,300); count++; }
if(!enmy[1][6])
{ enemy[1][6]->sprite.setPosition(420,250); count++; }
if(!enmy[1][7])
{ enemy[1][7]->sprite.setPosition(420,200); count++; }
if(!enmy[1][8])
{ enemy[1][8]->sprite.setPosition(470,200); count++; }
if(!enmy[1][9])
{ enemy[1][9]->sprite.setPosition(520,200); count++; }
if(!enmy[1][10])
{ enemy[1][10]->sprite.setPosition(450,160); count++; }
if(!enmy[1][11])
{ enemy[1][11]->sprite.setPosition(510,160); count++; }
if(!enmy[1][12])
{ enemy[1][12]->sprite.setPosition(470,245); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(210,90); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(280,130); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(420,130); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(500,90); count++; }
if(!enmy[2][4])
{ enemy[2][4]->sprite.setPosition(350,400); count++; }
if(!enmy[2][5])
{ enemy[2][5]->sprite.setPosition(350,170); count++; }
if(!enmy[2][6])
{ enemy[2][6]->sprite.setPosition(350,220); count++; }
if(!enmy[2][7])
{ enemy[2][7]->sprite.setPosition(350,340); count++; }
if(!enmy[2][8])
{ enemy[2][8]->sprite.setPosition(350,280); count++; }


if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(140,210); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(560,210); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(190,260); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(240,310); count++; }
if(!enmy[0][4])
{ enemy[0][4]->sprite.setPosition(290,360); count++; }
if(!enmy[0][5])
{ enemy[0][5]->sprite.setPosition(290,300); count++; }
if(!enmy[0][6])
{ enemy[0][6]->sprite.setPosition(290,250); count++; }
if(!enmy[0][7])
{ enemy[0][7]->sprite.setPosition(290,200); count++; }
if(!enmy[0][8])
{ enemy[0][8]->sprite.setPosition(240,200); count++; }
if(!enmy[0][9])
{ enemy[0][9]->sprite.setPosition(190,200); count++; }
if(!enmy[0][10])
{ enemy[0][10]->sprite.setPosition(190,160); count++; }
if(!enmy[0][11])
{ enemy[0][11]->sprite.setPosition(240,160); count++; }
if(!enmy[0][12])
{ enemy[0][12]->sprite.setPosition(235,255); count++; }


time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<13;i++)
     {
	 index = rand()%13 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<9;i++)
     {
	 indg = rand()%9 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<13;i++)
     {
	 indb = rand()%13 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}

}
if(lev==8 && stop>=5)
{
 if(count<=0)
{
lev=9;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = false;

for(int i=0;i<3;i++)
{
        for(int j=0;j<col;j++)
        {
        	if(i==0)          
            enemy[i][j] = new Alpha("img/enemy_1.png");
        	if(i==1)
            enemy[i][j] = new Beta("img/enemy_2.png");	
            	if(i==2)
            enemy[i][j] = new Gamma("img/enemy_3.png");	
        }
}
for(int i=0;i<3;i++)
{
for(int j=0;j<col;j++)
enemy[i][j]->b->speed=5;
}

for(int j=0;j<col;j++)
{ enemy[0][j]->sprite.setScale(0.35,0.35); enemy[0][j]->sprite.setPosition(-3000,-3000); enemy[0][j]->b->sprite.setPosition(-3000,-3000); }

for(int j=0;j<col;j++)
{ enemy[1][j]->sprite.setScale(0.3,0.3); enemy[1][j]->sprite.setPosition(-3000,-3000); enemy[1][j]->b->sprite.setPosition(-3000,-3000);}

for(int j=0;j<col;j++)
{ enemy[2][j]->sprite.setScale(0.3,0.3); enemy[2][j]->sprite.setPosition(-3000,-3000); enemy[2][j]->b->sprite.setPosition(-3000,-3000);}


time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
stop=0;
count=0;
}
else if(count>0)
{ count=0; lev=8; }
}		


					///////////////////////////////////////////
					////////////    CIRCLE FILLED   ///////////
					///////////////////////////////////////////

if(lev==9 && stop>=5)
{

if(!enmy[1][0])
{ enemy[1][0]->sprite.setPosition(465,115); count++; }
if(!enmy[1][1])
{ enemy[1][1]->sprite.setPosition(520,170); count++; }
if(!enmy[1][2])
{ enemy[1][2]->sprite.setPosition(460,440); count++; }
if(!enmy[1][3])
{ enemy[1][3]->sprite.setPosition(530,360); count++; }
if(!enmy[1][4])
{ enemy[1][4]->sprite.setPosition(420,360); count++; }
if(!enmy[1][5])
{ enemy[1][5]->sprite.setPosition(420,470); count++; }
if(!enmy[1][6])
{ enemy[1][6]->sprite.setPosition(470,170); count++; }
if(!enmy[1][7])
{ enemy[1][7]->sprite.setPosition(420,90); count++; }
if(!enmy[1][8])
{ enemy[1][8]->sprite.setPosition(420,170); count++; }
if(!enmy[1][9])
{ enemy[1][9]->sprite.setPosition(430,220); count++; }
if(!enmy[1][10])
{ enemy[1][10]->sprite.setPosition(480,220); count++; }
if(!enmy[1][11])
{ enemy[1][11]->sprite.setPosition(545,220); count++; }
if(!enmy[1][12])
{ enemy[1][12]->sprite.setPosition(430,310); count++; }
if(!enmy[1][13])
{ enemy[1][13]->sprite.setPosition(490,310); count++; }
if(!enmy[1][14])
{ enemy[1][14]->sprite.setPosition(550,310); count++; }
if(!enmy[1][15])
{ enemy[1][15]->sprite.setPosition(480,360); count++; }
if(!enmy[1][16])
{ enemy[1][16]->sprite.setPosition(430,410); count++; }
if(!enmy[1][17])
{ enemy[1][17]->sprite.setPosition(500,400); count++; }

if(!enmy[2][0])
{ enemy[2][0]->sprite.setPosition(360,80); count++; }
if(!enmy[2][1])
{ enemy[2][1]->sprite.setPosition(360,470); count++; }
if(!enmy[2][2])
{ enemy[2][2]->sprite.setPosition(170,260); count++; }
if(!enmy[2][3])
{ enemy[2][3]->sprite.setPosition(550,260); count++; }
if(!enmy[2][4])
{ enemy[2][4]->sprite.setPosition(260,260); count++; }
if(!enmy[2][5])
{ enemy[2][5]->sprite.setPosition(360,260); count++; }
if(!enmy[2][6])
{ enemy[2][6]->sprite.setPosition(460,260); count++; }
if(!enmy[2][7])
{ enemy[2][7]->sprite.setPosition(360,135); count++; }
if(!enmy[2][8])
{ enemy[2][8]->sprite.setPosition(360,195); count++; }
if(!enmy[2][9])
{ enemy[2][9]->sprite.setPosition(360,395); count++; }
if(!enmy[2][10])
{ enemy[2][10]->sprite.setPosition(360,325); count++; }

if(!enmy[0][0])
{ enemy[0][0]->sprite.setPosition(270,110); count++; }
if(!enmy[0][1])
{ enemy[0][1]->sprite.setPosition(220,170); count++; }
if(!enmy[0][2])
{ enemy[0][2]->sprite.setPosition(260,440); count++; }
if(!enmy[0][3])
{ enemy[0][3]->sprite.setPosition(200,360); count++; }
if(!enmy[0][4])
{ enemy[0][4]->sprite.setPosition(250,360); count++; }
if(!enmy[0][5])
{ enemy[0][5]->sprite.setPosition(310,470); count++; }
if(!enmy[0][6])
{ enemy[0][6]->sprite.setPosition(270,170); count++; }
if(!enmy[0][7])
{ enemy[0][7]->sprite.setPosition(320,90); count++; }
if(!enmy[0][8])
{ enemy[0][8]->sprite.setPosition(320,170); count++; }
if(!enmy[0][9])
{ enemy[0][9]->sprite.setPosition(310,220); count++; }
if(!enmy[0][10])
{ enemy[0][10]->sprite.setPosition(250,220); count++; }
if(!enmy[0][11])
{ enemy[0][11]->sprite.setPosition(180,220); count++; }
if(!enmy[0][12])
{ enemy[0][12]->sprite.setPosition(180,310); count++; }
if(!enmy[0][13])
{ enemy[0][13]->sprite.setPosition(240,310); count++; }
if(!enmy[0][14])
{ enemy[0][14]->sprite.setPosition(300,310); count++; }
if(!enmy[0][15])
{ enemy[0][15]->sprite.setPosition(310,360); count++; }
if(!enmy[0][16])
{ enemy[0][16]->sprite.setPosition(310,420); count++; }
if(!enmy[0][17])
{ enemy[0][17]->sprite.setPosition(230,400); count++; }
time_alp += time;
if(time_alp>5 )
{

     for(int i=0;i<18;i++)
     {
	 index = rand()%18 + 0;
	if(enmy[0][index] == false)
			{
			if(enemy[0][index]->b->bulletFired == false)
				enemy[0][index]->fire();
				break;
			}
     }      
}

if(enmy[0][index] == false)
{
	enemy[0][index]->b->move();
	if(enemy[0][index]->b->bulletFired==true)
	time_alp=0;
}

time_gama += time;
if(time_gama>2 )
{

     for(int i=0;i<11;i++)
     {
	 indg = rand()%11 + 0;
	if(enmy[2][indg] == false)
			{
			if(enemy[2][indg]->b->bulletFired == false)
				enemy[2][indg]->fire();
				break;
			}
     }      
}

if(enmy[2][indg] == false)
{
	enemy[2][indg]->b->move();
	if(enemy[2][indg]->b->bulletFired==true)
	time_gama=0;
}

time_beta += time;
if(time_beta>3 )
{

     for(int i=0;i<18;i++)
     {
	 indb = rand()%18 + 0;
	if(enmy[1][indb] == false)
			{
			if(enemy[1][indb]->b->bulletFired == false)
				enemy[1][indb]->fire();
				break;
			}
     }      
}

if(enmy[1][indb] == false)
{
	enemy[1][indb]->b->move();
	if(enemy[1][indb]->b->bulletFired==true)
	time_beta=0;
}
}
if(lev==9 && stop>=5)
{
 if(count<=0)
{
lev=10;
for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
delete enemy[i][j];

for(int i=0;i<3;i++)
for(int j=0;j<col;j++)
enmy[i][j] = true;

time_alp=0;
time_beta=0;
time_gama=0;
index=0;
indb=0;
indg=0;
count=0;
}
else if(count>0)
{ count=0; lev=9; }

}
		
}

};

