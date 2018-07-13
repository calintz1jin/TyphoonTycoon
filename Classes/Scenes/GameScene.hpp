//
//  GameScene.hpp
//  TyphoonTycoon
//
//  Created by calintz1jin on 2018. 7. 9..
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "../Include/Include.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    //! @brief 태풍을 게임신에 add합니다.
    void addTyphoon(Node* typhoon);
    void removeTyphoon();
    
    
private:
    //! @brief 태풍의 부모노드입니다.
    Node* typhoonNode;
    
public:
    GameScene();
    virtual ~GameScene();
};

#endif /* GameScene_hpp */
