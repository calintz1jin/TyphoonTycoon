//
//  TouchLayer.hpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 12..
//

#ifndef TouchLayer_hpp
#define TouchLayer_hpp

#include "../Include/Include.h"

class TouchLayer : public Layer {
public:
    virtual bool init();
    static TouchLayer* create()
    {
        TouchLayer *pRet = new(std::nothrow) TouchLayer();
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
    
     virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) ;
     virtual void onTouchMoved(Touch *pTouch, Event *pEvent) ;
     virtual void onTouchEnded(Touch *pTouch, Event *pEvent) ;
     virtual void onTouchCancelled(Touch *pTouch, Event *pEvent) ;
public:
    TouchLayer();
    virtual ~TouchLayer();
    
};

#endif /* TouchLayer_hpp */
