//
//  TileLayer.cpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 11..
//

#include "TileLayer.hpp"
#include "../Util/VisibleRect.hpp"

#include "../Map/TileNode.hpp"

enum TAG_TILE_LAYER
{
    TTL_MAP_IMAGE = 0,      // 맵 이미지.
    TTL_TILE_NODE,          // 타일노드.
    
    TTL_END
};

TileLayer::TileLayer()
: rootNode(nullptr)
, rootTile(nullptr)
{
    
}

TileLayer::~TileLayer()
{
    
}

bool TileLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    rootNode = Node::create();
    if(rootNode == nullptr) return false;
    rootNode->setAnchorPoint(Vec2::ZERO);
    rootNode->setPosition(Vec2::ZERO);
    this->addChild(rootNode);
    
    rootTile = Node::create();
    if(rootTile == nullptr) return false;
    rootTile->setAnchorPoint(Vec2::ZERO);
    rootTile->setPosition(Vec2::ZERO);
    rootNode->addChild(rootTile, TTL_TILE_NODE, TTL_TILE_NODE);
    
    // 맵 배경 생성.
    createMapImage();
    
    // 타일 생성.
    createTile();
    
    return true;
}

void TileLayer::createMapImage()
{
    if(rootNode == nullptr) return;
    
    auto spr_map = Sprite::create("Tile/world_map.png");
    if(spr_map == nullptr) return;
    
    spr_map->setAnchorPoint(Vec2::ZERO);
    spr_map->setPosition(Vec2::ZERO);
    
    spr_map->setScaleX(VisibleRect::getVisibleRect().getMaxX() / spr_map->getContentSize().width);
    spr_map->setScaleY(VisibleRect::getVisibleRect().getMaxY() / spr_map->getContentSize().height);
    
    rootNode->addChild(spr_map, TTL_MAP_IMAGE, TTL_MAP_IMAGE);
}

void TileLayer::createTile()
{
    int tile_count_x = VisibleRect::getVisibleRect().getMaxX() / TILE_WIDTH;
    int tile_count_y = VisibleRect::getVisibleRect().getMaxY() / TILE_HEIGHT;
    
    for(int y = 0; y < tile_count_y; ++y)
    {
        for(int x = 0; x < tile_count_x; ++x)
        {
            Vec2 tile_pos = Vec2(TILE_WIDTH * x, TILE_HEIGHT * y);
            
            auto tile_node = TileNode::create(TTT_NONE);
            if(tile_node == nullptr) continue;
            
            tile_node->setAnchorPoint(Vec2::ZERO);
            tile_node->setPosition(tile_pos);
            
            int index = x + (tile_count_x * y);
            
            rootTile->addChild(tile_node, index, index);
        }
    }
}
