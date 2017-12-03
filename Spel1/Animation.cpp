//
//  Animation.cpp
//  Spel1
//
//  Created by malcolm tivelius on 2017-11-25.
//  Copyright © 2017 malcolm tivelius. All rights reserved.
//

#include "Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0.0f;
    
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

}
Animation::~Animation(){
    
}

void Animation::Update(int row, float deltaTime, bool faceRight) {
    
    currentImage.y = row;
    totalTime += deltaTime;
    
    if(totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;
        
        if(currentImage.x >= imageCount.x) {
            currentImage.x = 0;
        }
    }
    
    uvRect.top = currentImage.y * uvRect.height;
    
    if(faceRight) {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }else{
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
    
    
}
