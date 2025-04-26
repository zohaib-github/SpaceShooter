// ZOHAIB KHAN
// 22I-0946
// FINAL PROJECT

#include <SFML/Audio.hpp>
#include "game.h"
#include <string>
#include "fstream"
class Menu

{
public:

Sprite background;
Texture texture;
int badge;
int score;
string line;
string* player_names;
int* scores;
string filename;
int num_players=0;

Menu()
{
player_names = new string[100];
scores = new int[100];
line = "";
texture.loadFromFile("Images/Space 1.jpg");
background.setTexture(texture);
background.setScale(1, 0.35);
 filename = "Players";
score=0;
}

void display_menu()

{

Game g;
 RenderWindow window(VideoMode(780, 780), title);
 
int level=1 ;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
  //						 MUSIC SYSTEM									      //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

sf::Music music;
if (!music.openFromFile("Music/menu.ogg"))    // background music
    cout<<"error loading music"<<endl; // error
music.play();
sf::Music music1;
if (!music1.openFromFile("Music/shatter.ogg"))    // background music
    cout<<"error loading music"<<endl; // error
music1.setVolume(100.0f);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
  //						 TEXT SYSTEM									      //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Font font;
        if (!font.loadFromFile("font/Plaguard-ZVnjx.otf"))
        {
            cout << "Error: Failed to load font." << endl;
        }
        Text text;
        text.setFont(font);
        text.setString("SPACE SHOOTER");
        text.setCharacterSize(60);
        text.setFillColor(Color::White);
        text.setPosition(180, 70);
        Text text1;
        text1.setFont(font);
        text1.setString("Start Game");
        text1.setCharacterSize(40);
        text1.setFillColor(Color::White);
        text1.setPosition(270, 220);
        Text text2;
        text2.setFont(font);
        text2.setString("Select Level");
        text2.setCharacterSize(40);
        text2.setFillColor(Color::White);
        text2.setPosition(270, 290);
        Text text7;
        text7.setFont(font);
        text7.setString("Easy");
        text7.setCharacterSize(30);
        text7.setFillColor(Color::White);
        text7.setPosition(245, 360);
        Text text3;
        text3.setFont(font);
        text3.setString("Medium");
        text3.setCharacterSize(30);
        text3.setFillColor(Color::White);
        text3.setPosition(345, 360);
        Text text4;
        text4.setFont(font);
        text4.setString("Hard");
        text4.setCharacterSize(30);
        text4.setFillColor(Color::White);
        text4.setPosition(485, 360);
        Text highscores;
        highscores.setFont(font);
        highscores.setString("Highest Scorers");
        highscores.setCharacterSize(40);
        highscores.setFillColor(Color::White);
        highscores.setPosition(270, 430);
        Text text5;
        text5.setFont(font);
        text5.setString("Instructions");
        text5.setCharacterSize(40);
        text5.setFillColor(Color::White);
        text5.setPosition(270, 500);
        Text text6;
        text6.setFont(font);
        text6.setString("Exit");
        text6.setCharacterSize(40);
        text6.setFillColor(Color::White);
        text6.setPosition(270, 570);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
  //						 LOOP SYSTEM									      //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int i=1;
 
        while (window.isOpen())
        {
            Event event;        
	
            while (window.pollEvent(event))
            {
        
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed)
                {
                    if (text3.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                  
                    	music1.play();
                        level=4;
                    }
                    else  if (text1.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                    
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   //                                                        Entering Player Name
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
    Text label;
    label.setFont(font);
    label.setString("Enter your name: ");
    label.setCharacterSize(40);
    label.setPosition(240, 200);

    RectangleShape inputBox(sf::Vector2f(300.f, 30.f));
    inputBox.setPosition(270, 300);
    inputBox.setFillColor(Color::White);
    inputBox.setOutlineThickness(10);
    

    Text inputText;
    inputText.setFont(font);
    inputText.setString("");
    inputText.setCharacterSize(30);
    inputText.setPosition(270, 295);
    inputText.setFillColor(Color::Black);

     Text text3;
        text3.setFont(font);
        text3.setString("< Back");
        text3.setCharacterSize(30);
        text3.setFillColor(Color::White);
        text3.setPosition(40, 670);
    
    string name;
    bool done = false;
    while(window.isOpen() && !done)
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
                
                if (event.type == Event::MouseButtonPressed)
                {
                    if (text3.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {                  
                    	music1.play();
                      break;
                    }
                }
             else if(event.type == sf::Event::TextEntered)
             {
                if(event.text.unicode == '\b')
                {
                    if (name!="")
                    {
                        for(int i=0;name[i]!='\0';i++)
                        {
                          if(name[i+1]=='\0')
                          {
                          name.erase(i);
                         
                          }
                        }
                        inputText.setString(name);
                    }
                } 
                else if(event.text.unicode == '\r')
                {
               
                    if (name!="")
                    {
                        done = true;
                    }
                }
                else if(event.text.unicode < 128)
                {
                    // regular ASCII character
                    name += static_cast<char>(event.text.unicode);
                    inputText.setString(name);
                }
             } 
         }

        window.clear(Color::White);
        window.draw(background);
        window.draw(label);
        window.draw(inputBox);
        window.draw(inputText);
        window.draw(text3);
        window.display();
    }
   
   
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                        Descending Order Sorting
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    	
                    	ofstream file(filename, ios::app);
			file<<name<<" ";
			
                    	music.pause();
                        music1.play();
                        Game g;
                        g.start_game(window , level , score );
                        
                        file<< "		 "<<score<<endl;
                        file.close();
                        i++;
                        
ifstream read(filename);
           
while (getline(read, line))
{
    stringstream ss(line);
    string player_name;
    int score;
    
    ss >> player_name >> score;
    player_names[num_players] = player_name;
    scores[num_players] = score;
    num_players++;
    
}    
read.close();

for(int i=0; i<num_players-1 ;i++)
 {
      for(int j=i+1; j<num_players ;j++)
      {
            if(scores[i] < scores[j])
            {
                int temp_score = scores[i];
                scores[i] = scores[j];
                scores[j] = temp_score;
		
                string temp_name = player_names[i];
                player_names[i] = player_names[j];
                player_names[j] = temp_name;
            }
      }
 }
 

   ofstream write(filename);
    if(write.is_open())
    {
        for(int i=0; i<num_players ;i++)
        {
            write<<player_names[i]<<"		 "<<scores[i]<<endl;
        }
        write.close();
    }
num_players=0;

                    }
                    else  if (text4.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                    	
                        music1.play();
                        level=7;
                    }
                    else  if (text7.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                    
                        music1.play();
                        level=1;
                    }
                    else  if (text5.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                   
                        music1.play();
                      
                    }
                    else  if (text6.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                  
                        music1.play();
                        window.close();
                    }
                    else  if (highscores.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {
                    
                    
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                                        Displaying Menu
   //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              
                    bool back=false;
                  Text name;
        name.setFont(font);
        name.setString("NAME");
        name.setCharacterSize(30);
        name.setFillColor(Color::White);
        name.setPosition(20, 70);
        Text tex1;
        tex1.setFont(font);
        tex1.setString("SCORE");
        tex1.setCharacterSize(30);
        tex1.setFillColor(Color::White);
        tex1.setPosition(250, 70);
        Text tex2;
        tex2.setFont(font);
        tex2.setString("BADGE");
        tex2.setCharacterSize(30);
        tex2.setFillColor(Color::White);
        tex2.setPosition(450, 70);
        Text tex3;
        tex3.setFont(font);
        tex3.setString("< Back");
        tex3.setCharacterSize(30);
        tex3.setFillColor(Color::White);
        tex3.setPosition(40, 670);
                        music1.play();
                        
                        
                        ifstream read(filename);    
while (getline(read, line))
{
    stringstream ss(line);
    string player_name;
    int score;
    
    ss >> player_name >> score;
    player_names[num_players] = player_name;
    scores[num_players] = score;
    num_players++;
    
}    
read.close();
Text tex4;
	std::ostringstream ssScore;  
	for(int i=0;i<num_players;i++)      
             ssScore<<player_names[i]<<"                        "<<scores[i] <<"                       "<<i+1<<endl;
        tex4.setFont(font);
        tex4.setString(ssScore.str());
        tex4.setCharacterSize(20);
        tex4.setFillColor(Color::White);
        tex4.setPosition(20, 120);

    while(window.isOpen() && !back)
    {
        
Event event;        
	
            while (window.pollEvent(event))
            {
        
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed)
                {
                    if (text3.getGlobalBounds().contains(Vector2f(event.mouseButton.x , event.mouseButton.y)))
                    {                  
                    	music1.play();
                       back=true;
                       break;
                    }
                }
            } 
            read.close();       
        window.clear(Color::White);
        window.draw(background);
        window.draw(name);
        window.draw(tex1);
        window.draw(tex2);
         window.draw(tex3);
         window.draw(tex4);
        window.display();
    }
                        
                    }
                    
                }
            }
            
            

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////          
  //						 TEXT HOVERING SYSTEM							              //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
           
            if (text.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text.setFillColor(sf::Color::White); // Change the text color back to white
            
            if (text1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text1.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else
            text1.setFillColor(sf::Color::White); // Change the text color back to white
            
            if (text2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text2.setFillColor(sf::Color::White); // Change the text color back to white
            
            if (text3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text3.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else if(level==4)
    	    text3.setFillColor(sf::Color::Green);
    	    else
            text3.setFillColor(sf::Color::White);
            
            if (text4.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text4.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else if(level==7)
    	    text4.setFillColor(sf::Color::Green);
    	    else
            text4.setFillColor(sf::Color::White); // Change the text color back to white
            
            if (text5.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text5.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else
            text5.setFillColor(sf::Color::White); // Change the text color back to white
            
            if (text6.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text6.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else
            text6.setFillColor(sf::Color::White); // Change the text color back to white
    
    	    if (text7.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            text7.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else if(level==1)
    	    text7.setFillColor(sf::Color::Green);
    	    else
            text7.setFillColor(sf::Color::White);
            
            if (highscores.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            highscores.setFillColor(sf::Color::Blue); // Change the text color to red
    	    else
            highscores.setFillColor(sf::Color::White); 
            
            window.clear();
            window.draw(background);
         
            window.draw(text);
             window.draw(text1);
             window.draw(text2);
               window.draw(text3);
               window.draw(text4);
               window.draw(text5);
               window.draw(text6);
               window.draw(text7);
               window.draw(highscores);
            window.display();
 
   }
}


};
