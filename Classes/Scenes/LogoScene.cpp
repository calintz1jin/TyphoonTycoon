//
//  LogoScene.cpp
//  TyphoonTycoon-mobile
//
//  Created by calintz1jin on 2018. 7. 9..
//

#include "LogoScene.hpp"
#include "../Util/VisibleRect.hpp"

#include "GameScene.hpp"

LogoScene::LogoScene()
{
    
}

LogoScene::~LogoScene()
{
    
}

bool LogoScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    createLogo();
    
    nextSceneAction();
    
    return true;
}

Scene* LogoScene::createScene()
{
    return LogoScene::create();
}

void LogoScene::createLogo()
{
    auto label = Label::createWithTTF("Logo Scene ~ !", "fonts/Marker Felt.ttf", 50);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(VisibleRect::center().x, VisibleRect::top().y - 200));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
}

void LogoScene::nextSceneAction()
{
    auto delay = DelayTime::create(0.1f);
    auto callfunc = CallFunc::create([=](){
        auto scene = GameScene::createScene();
        Director::getInstance()->replaceScene(scene);
    });
    auto seq = Sequence::create(delay, callfunc, nullptr);
    
    this->runAction(seq);
}
