//
//  GameScene.cpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 9..
//

#include "GameScene.hpp"

#include "../Util/VisibleRect.hpp"
#include "../Layer/TileLayer.hpp"
#include "../Layer/TouchLayer.hpp"
#include "../Manager/GameManager.hpp"

GameScene::GameScene()
: typhoonNode(nullptr)
{
    
}

GameScene::~GameScene()
{
    
}

bool GameScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    
    
    
    auto label = Label::createWithTTF("Game Scene ~ !", "fonts/Marker Felt.ttf", 50);
    label->setTextColor(Color4B::BLACK);
    label->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    label->setPosition(Vec2(VisibleRect::center().x, VisibleRect::top().y));
    this->addChild(label, 1);
    
    
    auto spr_tile = Sprite::create("Tile/tile_rect.png");
    this->addChild(spr_tile);
    
    // tile layer
    auto tile_layer = TileLayer::create();
    if(tile_layer == nullptr) return false;
    tile_layer->setAnchorPoint(Vec2::ZERO);
    tile_layer->setPosition(Vec2::ZERO);
    this->addChild(tile_layer);
    
    typhoonNode = Node::create();
    if(typhoonNode == nullptr) return false;
    typhoonNode->setAnchorPoint(Vec2::ZERO);
    typhoonNode->setPosition(Vec2::ZERO);
    this->addChild(typhoonNode);
    
    
    auto touch_layer = TouchLayer::create();
    if(touch_layer == nullptr) return false;
    touch_layer->setAnchorPoint(Vec2::ZERO);
    touch_layer->setPosition(Vec2::ZERO);
    this->addChild(touch_layer);
    
    
    
    return true;
}

Scene* GameScene::createScene()
{
    return GameScene::create();
}

void GameScene::addTyphoon(Node* typhoon)
{
    if(typhoonNode == nullptr) return;
    if(typhoon == nullptr) return;
    
    typhoonNode->addChild(typhoon);
}

void GameScene::removeTyphoon()
{
    if(typhoonNode == nullptr) return;
    
    typhoonNode->removeAllChildrenWithCleanup(true);
}
