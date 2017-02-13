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
    m_listener = EventListenerTouchOneByOne::create();
    return false;
}

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    std::vector<std::vector<Block*>>::iterator rows;
    for (auto& rows : blockMetrics)
    {
        for(auto& row : rows)
        {
            BlockView* block = BlockView::create();
            block->initWithModel(row);
            this->addChild(block);
            bViews.push_back(block);
        }
    }
    m_listener->onTouchBegan = [](Touch* touch, Event* event)
    {
        return true;
    };
    
    m_listener->onTouchMoved = [](Touch* touch, Event* event)
    {
        
        return true;
    };
    
    m_listener->onTouchEnded = [](Touch* touch, Event* event)
    {
        return true;
    };

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
