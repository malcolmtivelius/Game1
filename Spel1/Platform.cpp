//
//  Platform.cpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-27.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#include "Platform.hpp"
#include "Collider.hpp"
#include <SFML/Graphics.hpp>


Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
    
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);
    body.setTexture(texture);
    
}
Platform::Platform(sf::Color::Color color, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);
    body.setFillColor(color);

}

Platform::~Platform() {
    
}


void Platform::Draw(sf::RenderWindow& window) {
    window.draw(body);
}
