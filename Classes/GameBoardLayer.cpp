//
//  GameBoardLayer.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#include "cocos2d.h"
#include "GameBoardLayer.hpp"

using namespace cocos2d;

GameBoardLayer::GameBoardLayer()
{
    
}

GameBoardLayer::~GameBoardLayer()
{
    
}

bool GameBoardLayer::init()
{
    return false;
}

GameBoardLayer* GameBoardLayer::createGameBoardLayer(GameBoardToSceneDelegate* delegate)
{
    auto layer = new GameBoardLayer();
    layer->viewDelegate = delegate;
    
    return layer;
}
