//
//  Animation.hpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-25.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#ifndef Animation_hpp
#define Animation_hpp

#include <SFML/Graphics.hpp>


class Animation {
    
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    
    void Update(int row, float deltaTime, bool faceRight);
    
public:
    sf::IntRect uvRect;
    
    
private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    
    float totalTime;
    float switchTime;
    
};

#endif /* Animation_hpp */
