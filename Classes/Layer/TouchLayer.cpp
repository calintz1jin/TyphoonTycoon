//
//  TouchLayer.cpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 12..
//

#include "TouchLayer.hpp"
#include "../Manager/GameManager.hpp"
#include "../Typhoon/Typhoon.hpp"

TouchLayer::TouchLayer()
{
    
}
TouchLayer::~TouchLayer()
{
    
}

bool TouchLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = CC_CALLBACK_2(TouchLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TouchLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(TouchLayer::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(TouchLayer::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

bool TouchLayer::onTouchBegan(Touch *pTouch, Event *pEvent)
{
    return true;
}

void TouchLayer::onTouchMoved(Touch *pTouch, Event *pEvent)
{
    
}

void TouchLayer::onTouchEnded(Touch *pTouch, Event *pEvent)
{
    if(GameManager::getInstance()->getTyphoonObject() == nullptr)
    {
        GameManager::getInstance()->createTyphoon(pTouch->getLocation());
    }
    else
    {
        auto typhoon = GameManager::getInstance()->getTyphoonObject();
        
        auto moveto = MoveTo::create(1.f, pTouch->getLocation());
        typhoon->runAction(moveto);
    }
}

 void TouchLayer::onTouchCancelled(Touch *pTouch, Event *pEvent)
{
    
}
