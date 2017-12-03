//
//  Collision.hpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-27.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <SFML/Graphics.hpp>

class Collider {

public:
    Collider(sf::RectangleShape& body);
    ~Collider();
    
    void Move(float dx, float dy) { body.move(dx,dy);}
    
    bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
    
    sf::Vector2f GetPosition() { return body.getPosition(); }
    
    sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
    
    
private:
    sf::RectangleShape& body;
    
    

};




#endif /* Collision_hpp */
