//
//  TileNode.cpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 10..
//

#include "TileNode.hpp"
#include "../Manager/GameManager.hpp"
#include "../Typhoon/Typhoon.hpp"

TileNode::TileNode()
: type(TTT_NONE)
, state(0)
, sprTile(nullptr)
, sprState(nullptr)
, damage(0)
{
    
}

TileNode::~TileNode()
{
    
}

bool TileNode::init(TAG_TILE_TYPE tile_type)
{
    type = tile_type;
    
    createTileImage();
    
    // 업데이트 함수.
    schedule(schedule_selector(TileNode::update), 0.5f);
    
    return true;
}

void TileNode::setVisibleTile(bool is_visible)
{
    if(sprTile == nullptr) return;
    
    sprTile->setVisible(is_visible);
}

void TileNode::setVisibleTileState(bool is_visible)
{
    if(sprState == nullptr) return;
    
    sprState->setVisible(is_visible);
}

void TileNode::createStateImage()
{
    if(!sprState)
        sprState = Sprite::create("Tile/tile_white.png");
    
    switch (state) {
        case TTS_NORMAL:
            sprState->setColor(Color3B(255, 255, 255));
            break;
        case TTS_DAMAGED_25:
            sprState->setColor(Color3B(255, 255, 127));
            break;
        case TTS_DAMAGED_50:
            sprState->setColor(Color3B(255, 255, 0));
            break;
        case TTS_DAMAGED_75:
            sprState->setColor(Color3B(255, 127, 0));
            break;
        case TTS_DAMAGED_100:
            sprState->setColor(Color3B(255, 0, 0));
            break;
            
        default:
            sprState->setColor(Color3B(255, 255, 255));
            break;
    }
    
    if(sprState)
    {
        if(!this->getChildByTag(22))
        {
            sprState->setAnchorPoint(Vec2::ZERO);
            sprState->setPosition(Vec2::ZERO);
            sprState->setTag(22);
            this->addChild(sprState);
        }
        
        if(state == TTS_NORMAL)
        {
            sprState->setVisible(false);
        }
        else
        {
            sprState->setVisible(true);
        }
    }
}

void TileNode::createTileImage()
{
    if(sprTile)
    {
        sprTile->removeFromParentAndCleanup(true);
        sprTile = nullptr;
    }
    
    __String* str_file_name = nullptr;
    
    switch (type) {
        case TTT_NONE:
            str_file_name = __String::create("Tile/tile_rect.png");
            break;
        case TTT_LAND:
            str_file_name = __String::create("Tile/tile_land.png");
            break;
        case TTT_WATER:
            str_file_name = __String::create("Tile/tile_water.png");
            break;
            
        default:
            break;
    }
    
    if(str_file_name)
        sprTile = Sprite::create(str_file_name->getCString());
    
    if(sprTile)
    {
        sprTile->setVisible(false);
        sprTile->setAnchorPoint(Vec2::ZERO);
        sprTile->setPosition(Vec2::ZERO);
        this->addChild(sprTile);
    }
}

void TileNode::update(float dt)
{
    auto typhoon = GameManager::getInstance()->getTyphoonObject();
    if(typhoon == nullptr) return;
    float rad = typhoon->getRadius();
    Vec2 pos = typhoon->getPosition();
    
    
    Vec2 my_pos = this->getPosition();
    float my_rad = 5.f;
    float distance = my_pos.getDistance(pos);
    
    if(distance < (rad + my_rad))
    {
        // 충돌.
        damage += 10.f;
    }
    else
        damage -= 10.f;
    
    if(damage > 100)
        damage = 100.f;
    
    if(damage < 0.f)
        damage = 0.f;
    
    if(damage < 25)
    {
        state = TTS_NORMAL;
    }
    else if(damage < 50)
    {
        state = TTS_DAMAGED_25;
    }
    else if(damage < 75)
    {
        state = TTS_DAMAGED_50;
    }
    else if(damage < 100)
    {
        state = TTS_DAMAGED_75;
    }
    else
    {
        state = TTS_DAMAGED_100;
    }
    
    createStateImage();
    
}
