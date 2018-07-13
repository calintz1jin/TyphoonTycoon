//
//  LogoScene.hpp
//  TyphoonTycoon-mobile
//
//  Created by calintz1jin on 2018. 7. 9..
//

#ifndef LogoScene_hpp
#define LogoScene_hpp

#include "../Include/Include.h"

//! @Class LogoScene
//! @brief 게임 시작시 제일 처음 등장하는 로고 씬입니다.

class LogoScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(LogoScene);
    
private:
    void createLogo();
    
    void nextSceneAction();
    
public:
    LogoScene();
    virtual ~LogoScene();
};

#endif /* LogoScene_hpp */
