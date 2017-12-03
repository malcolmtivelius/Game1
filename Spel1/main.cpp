
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Platform.hpp"
#include <vector>

static const float VIEW_HEIGHT = 1080.0f;
static const float VIEW_BREADTH = 1920.0f;



void resizeView(const sf::RenderWindow& window, sf::View& view){
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Spel1", sf::Style::Default);
    
    //Set view
    sf::View view(sf::Vector2f(0.0f,0.0f),sf::Vector2f(VIEW_BREADTH,VIEW_HEIGHT));
    
    //The length of the map!
    const float MAP_LENGTH = 5000.0f;

    // Player
    sf::Texture playerTexture;
    playerTexture.loadFromFile("/Users/MalcolmTivelius/Git/Games/Spel1/Texture/tux_from_linux.png");
    unsigned int jumpCounter = 0;

    
    sf::Vector2f spawnLocation = sf::Vector2f((-MAP_LENGTH/2.0f + 300.0f), 900.0f);
    
    //Texture, imageCount, switchTime, speed, jumpHeight, spawnLoaction
    Player player(&playerTexture, sf::Vector2u(3,9), 0.3f, 400.0f, 200.0f, spawnLocation);
    
    
    
    //Platforms
    

    //Background image
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(MAP_LENGTH,VIEW_HEIGHT));
    background.setPosition(-MAP_LENGTH/2, 0);
    sf::Texture backgroundTexture;
    backgroundTexture.setRepeated(true);
    backgroundTexture.loadFromFile("/Users/MalcolmTivelius/Git/Games/Spel1/Texture/Stars_background.png");
    background.setFillColor(sf::Color::Color(84,84,84));
 //   background.setTexture(&backgroundTexture);
    
    
    /*These platforms make the play area*/
    Platform ground(sf::Color::Color(64,64,64), sf::Vector2f(MAP_LENGTH, 100.0f), sf::Vector2f(0.0f,1080.0f));
    Platform leftWall(nullptr,sf::Vector2f(1000.0f,3000.0f), sf::Vector2f(-MAP_LENGTH/2-500, 0.0f));
    Platform rightWall(nullptr,sf::Vector2f(1000.0f,3000.0f),sf::Vector2f(MAP_LENGTH/2+500, 0.0f));
    
    /*All objects colliding with the player*/
    std::vector<Platform> platforms;
    platforms.emplace_back(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f,200.0f));
    platforms.emplace_back(nullptr, sf::Vector2f(400.0f, 200.0f),sf::Vector2f(500.0f, 1000.0f));
    platforms.emplace_back(ground);
    platforms.emplace_back(leftWall);
    platforms.emplace_back(rightWall);



    
    float deltaTime = 0.0f;
    sf::Clock clock;
    
   // window.setFramerateLimit(60);
    
    // Start the game loop
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;
        //printf("%f""\n",deltaTime);
        
        // Process events
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            
            switch (evnt.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
                case sf::Event::KeyPressed:
                    if(evnt.key.code == sf::Keyboard::Space && jumpCounter < 2){
                        player.jump();
                        ++jumpCounter;
                    }
                default:
                    break;
                
            }

        }
        
        player.Update(deltaTime);
        
        sf::Vector2f direction;
        
        for(Platform& platform : platforms) {
            if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
                player.OnCollision(direction);
                if(direction.y < 0) {
                    jumpCounter = 0; //Landing on feet - resetting the counter
                }
            }
        }
        
        float posX = player.GetPosition().x;
        float posY = player.GetPosition().y;
        
        if(posX < -MAP_LENGTH/2 + VIEW_BREADTH/2) {
            view.setCenter(-MAP_LENGTH/2 + VIEW_BREADTH/2, VIEW_HEIGHT/2);
        } else if(posX > MAP_LENGTH/2 - VIEW_BREADTH/2) {
            view.setCenter(MAP_LENGTH/2 - VIEW_BREADTH/2, VIEW_HEIGHT/2);
        }else {
            view.setCenter(posX,(VIEW_HEIGHT/2));
        }
        
        
        window.clear(sf::Color::Color(208,208,208));
        window.setView(view);
        
       // window.draw(background);

        for (Platform& platform : platforms) {
            platform.Draw(window);
        }
        player.Draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
