//
//  Typhoon.cpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 11..
//

#include "Typhoon.hpp"

Typhoon::Typhoon()
: radius(86.f)
, sprTyphoon(nullptr)
{
    
}

Typhoon::~Typhoon()
{
    
}

bool Typhoon::init()
{
    createTyphoonImage();
    
    return true;
}

void Typhoon::createTyphoonImage()
{
    if(sprTyphoon) return;
    
    sprTyphoon = Sprite::create("Tile/typhoon.png");
    if(sprTyphoon == nullptr) return;
    
    sprTyphoon->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    sprTyphoon->setPosition(Vec2::ZERO);
    
    this->addChild(sprTyphoon);
    
    auto rotate = RotateTo::create(0.5f, 360);
    auto repeat = RepeatForever::create(rotate);
    
    sprTyphoon->runAction(repeat);
}
