//
//  GameBoardLayer.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#include "cocos2d.h"
#include "GameBoardLayer.hpp"

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

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    std::vector<std::vector<Block*>>::iterator rows;
    for(rows = blockMetrics.begin(); rows!=blockMetrics.end(); ++rows)
    {
        BlockView* bv = new BlockView();
        //bv->initWithModel()
        bViews.push_back()
    }
}


void GameBoardLayer::update(float dt)
{
    //TODO: add your code here to update the whole view
}


GameBoardLayer* GameBoardLayer::createGameBoardLayer(GameBoardToSceneDelegate* delegate)
{
    auto layer = new GameBoardLayer();
    layer->viewDelegate = delegate;
    
    return layer;
}
