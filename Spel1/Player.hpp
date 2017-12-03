//
//  Player.hpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-26.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collider.hpp"
#include <cmath>

class Player {
    
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f spawnLocation);
    ~Player();
    
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);
    
    sf::Vector2f GetPosition() {
        return body.getPosition();
    }
    Collider GetCollider() { return Collider(body); }
    
    //En meter säger vi är 100 SFML enheter därför alltså 9.82*100 = 982
    void jump() { velocity.y = -sqrtf(2.0f * 982.0f * jumpHeight); }
    
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    
    sf::Vector2f velocity;
    float jumpHeight;
    int jumpCounter;
};



#endif /* Player_hpp */
