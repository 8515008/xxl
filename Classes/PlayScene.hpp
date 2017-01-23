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

#include "GameBoardLayer.hpp"
#include "GameBoardModel.hpp"
#include "common.h"

class PlayScene : public Layer, public GameBoardToSceneDelegate
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    virtual void ccTouchesBegan2(CCSet* touches, CCEvent* event){}
    virtual void ccTouchesEnded2(CCSet* touches, CCEvent* event){}
    
    CREATE_FUNC(PlayScene);
    
private:
    CC_SYNTHESIZE(GameBoardLayer*, m_gameboardLayer, GameBoardLayer);
    CC_SYNTHESIZE(GameBoardModel*, m_gameboardModel, GameBoardModel);
};

#endif /* PlayScene_hpp */
