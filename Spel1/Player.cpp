//
//  Player.cpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-26.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <cmath>
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f spawnLocation) :
    animation(texture,imageCount,switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;
    

    body.setSize(sf::Vector2f(100.0f,150.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(spawnLocation);
    body.setTexture(texture);
}

Player::~Player(){
    
}


void Player::Update(float deltaTime) {
    
    velocity.x = 0.0f;  //Bestämmer inbromsningshastighet 0.0f är tvärstop
    
    // Det här kan du göra med spelaren
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x += speed;
 //   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jumpCounter < 2) {
 //       velocity.y += -sqrtf(2.0f * 982.0f * jumpHeight); //En meter säger vi är 100 SFML enheter därför alltså 9.82*100 = 982
 //       ++jumpCounter;
 //       std::cout << "Hej";
 //   }
    
    
    
    //Gravitationen
    velocity.y += 981.0f * deltaTime;
    
    if(velocity.x == 0.0f) {
        row = 0;
    }else{
        row = 1;
        
        if (velocity.x > 0)
            faceRight = true;
        else
            faceRight = false;
    }
    
    
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);

    
}
void Player::OnCollision(sf::Vector2f direction) {
    if(direction.x < 0.0f) {
        //Collision on the left
        velocity.x = 0.0f;
        
    }else if(direction.x > 0.0f) {
        //Collision on the right
        velocity.x = 0.0f;
    }
    
    if (direction.y < 0.0f) {
        //Collision on the ground
        velocity.y = 0.0f;
        jumpCounter = 0;
        
    }else if (direction.y > 0.0f) {
        //Collision on roof
        velocity.y = 0.0f;
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(body);
}
