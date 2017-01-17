//
//  PlayScene.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#ifndef PlayScene_hpp
#define PlayScene_hpp

#include <stdio.h>

#endif /* PlayScene_hpp */
#include "cocos2d.h"
#include "GameBoardLayer.hpp"
#include "common.h"

using namespace cocos2d;

class PlayScene : public CCLayer, public GameBoardToSceneDelegate
{
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual void ccTouchesBegan2(CCSet* touches, CCEvent* event){}
    virtual void ccTouchesEnded2(CCSet* touches, CCEvent* event){}
    
    CREATE_FUNC(PlayScene);
    
private:
    //GameBoardLayer* gameboardLayer;
};
