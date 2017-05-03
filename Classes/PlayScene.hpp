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

class GameBoardLayer;
class GameBoardModel;
class PlayScene : public Scene
{
    CC_SYNTHESIZE(GameBoardLayer*, m_gameboardLayer, GameBoardLayer);
    CC_SYNTHESIZE(GameBoardModel*, m_gameboardModel, GameBoardModel);
    
public:
    CREATE_FUNC(PlayScene);
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    void selectBlock(XXL_Position pos);
};

#endif /* PlayScene_hpp */
