//
//  GameManager.hpp
//  TyphoonTycoon-mobile
//
//  Created by calintz1jin on 2018. 7. 9..
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include "../Include/Include.h"

//! @class GameManager
//! @brief 게임메니저 클래스입니다. 싱글톤으로 구현됩니다.

class Typhoon;
class GameManager
{
public:
    void createTyphoon(const Vec2& create_pos);
    void removeTyphoon();
    
private:
    CC_SYNTHESIZE(Typhoon*, typhoonObject, TyphoonObject);
    
    
    
    // --- SingleTone --- //
public:
    static GameManager* instance;
    
public:
    static GameManager* getInstance()
    {
        if(!instance)
        {
            instance = new GameManager();
        }
        
        return instance;
    }
    
private:
    GameManager();
public:
    virtual ~GameManager();
};

#endif /* GameManager_hpp */
