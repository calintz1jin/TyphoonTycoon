//
//  GameManager.cpp
//  TyphoonTycoon-mobile
//
//  Created by calintz1jin on 2018. 7. 9..
//

#include "GameManager.hpp"
#include "../Typhoon/Typhoon.hpp"
#include "../Scenes/GameScene.hpp"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
: typhoonObject(nullptr)
{
    
}

GameManager::~GameManager()
{
    
}

void GameManager::createTyphoon(const Vec2& create_pos)
{
    auto typhoon = Typhoon::create();
    if(typhoon == nullptr) return;
    
    typhoon->setAnchorPoint(Vec2::ZERO);
    typhoon->setPosition(create_pos);
    
    auto cur_scene = Director::getInstance()->getRunningScene();
    auto game_scene = dynamic_cast<GameScene*>(cur_scene);
    if(game_scene == nullptr) return;
    
    game_scene->addTyphoon(typhoon);
    
    typhoonObject = typhoon;
}

void GameManager::removeTyphoon()
{
    auto cur_scene = Director::getInstance()->getRunningScene();
    auto game_scene = dynamic_cast<GameScene*>(cur_scene);
    if(game_scene == nullptr) return;
    
    game_scene->removeTyphoon();
    typhoonObject = nullptr;
}
