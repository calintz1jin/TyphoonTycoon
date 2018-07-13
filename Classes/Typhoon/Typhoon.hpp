//
//  Typhoon.hpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 11..
//

#ifndef Typhoon_hpp
#define Typhoon_hpp

#include "../Include/Include.h"


//! @class Typhoon
//! @brief 태풍 클래스입니다.

class Typhoon : public Node
{
public:
    virtual bool init();
    static Typhoon* create()
    {
        Typhoon *pRet = new(std::nothrow) Typhoon();
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
    //! @brief 태풍 이미지 생성.
    void createTyphoonImage();
    
private:
    //! @brief 태풍의 반지름.
    CC_SYNTHESIZE(float, radius, Radius);
    
    //! @brief 태풍 이미지입니다.
    Sprite* sprTyphoon;
    
public:
    Typhoon();
    virtual ~Typhoon();
};

#endif /* Typhoon_hpp */
