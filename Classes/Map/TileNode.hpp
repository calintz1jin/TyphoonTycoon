//
//  TileNode.hpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 10..
//

#ifndef TileNode_hpp
#define TileNode_hpp

#include "../Include/Include.h"

//! @class TileNode
//! @brief 타일 클래스입니다. 타일의 타입과 정보를 갖고 있습니다.

class TileNode : public Node
{
public:
    virtual bool init(TAG_TILE_TYPE tile_type);
    static TileNode* create(TAG_TILE_TYPE tile_type)
    {
        TileNode *pRet = new(std::nothrow) TileNode();
        if (pRet && pRet->init(tile_type))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }
    
public:
    //! @brief 타일 이미지를 보여줄지 말지.
    void setVisibleTile(bool is_visible);
    //! @brief 타일 상태를 보여주리
    void setVisibleTileState(bool is_visible);
    
private:
    //! @brief 타일 이미지를 생성합니다.
    void createTileImage();
    //! @brief 상태 이미지를 생성합니다.
    void createStateImage();
    
    //! @brief 업데이트 펑션
    void update(float dt);

private:
    //! @brief 타일의 타입입니다.
    CC_SYNTHESIZE(int, type, Type);
    //! @brief 타일의 상태입니다.
    CC_SYNTHESIZE(int, state, State);
    //! @brief 타일의 이미지입니다. 타입에 따라 다르게 보여줍니다.
    Sprite* sprTile;
    //! @brief 현재 타일의 상태를 나타내는 이미지입니다.
    Sprite* sprState;
    
    //! @brief 데미지
    float damage;
    
public:
    TileNode();
    virtual ~TileNode();
};

#endif /* TileNode_hpp */
