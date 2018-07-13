//
//  TileLayer.hpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 11..
//

#ifndef TileLayer_hpp
#define TileLayer_hpp

#include "../Include/Include.h"


//! @class TileLayer
//! @brief 타일 레이어입니다. 해당 레이어에서 타일을 그립니다.

class TileLayer : public Layer
{
public:
    virtual bool init();
    static TileLayer* create()
    {
        TileLayer *pRet = new(std::nothrow) TileLayer();
        if (pRet && pRet->init())
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
    
private:
    //! @brief 맵의 배경을 생성합니다.
    void createMapImage();
    
    //! @brief 타일을 생성합니다.
    void createTile();
    
private:
    //! @brief 모든 자식의 루트.
    Node* rootNode;
    //! @brief 타일의 부모. 이 노드는 rootNode로 들어감.
    Node* rootTile;
    
    
    
    // constructor, destructor.
public:
    TileLayer();
    virtual ~TileLayer();
};

#endif /* TileLayer_hpp */
