//
//  Platform.hpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-27.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#ifndef Platform_hpp
#define Platform_hpp

#include <SFML/Graphics.hpp>
#include "Collider.hpp"


class Platform {
    
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    Platform(sf::Color::Color color, sf::Vector2f size, sf::Vector2f position);
    ~Platform();
    
    void Draw(sf::RenderWindow& window);
    Collider GetCollider() {return Collider(body); }
    
private:
    sf::RectangleShape body;
    
    
};




#endif /* Platform_hpp */
