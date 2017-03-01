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
    m_listener->setSwallowTouches(false);
    return true;
}

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    float ySize = blockMetrics.size();
    float xSize = (*blockMetrics.begin()).size();
    std::vector<std::vector<Block*>>::iterator rows;
    std::vector<BlockView*> blocks;
    PlayScene* controller;
    float x=0, y=0;
    float screenHeight = Director::getInstance()->getVisibleSize().height;
    float screenWidth = Director::getInstance()->getVisibleSize().width;
    float yTemp;
    for (auto& rows : blockMetrics)
    {
        for(auto& row : rows)
        {
            BlockView* block = BlockView::create();
            row->retain();
            block->initWithModel(row);
            if(yTemp != y)
            {
                yTemp = y;
                x = 0;
            }
            float xWidth = block->getContentSize().width;
            float yHeight = block->getContentSize().height;
            block->setAnchorPoint(Vec2(0,0));
            float blockX = screenWidth/2+(x-xSize/2)*xWidth;
            float blockY = screenHeight/2+(y-ySize/2)*yHeight;
            block->setPosition(Vec2(blockX, blockY));
            this->addChild(block);
            bViews.push_back(block);
            ++x;
        }
        ++y;
    }

    blocks = bViews;
    
    controller = m_controller;
    
    m_listener->onTouchBegan = [](Touch* touch, Event* event)
    {
        auto target = static_cast<GameBoardLayer*>(event->getCurrentTarget());
        
        return true;
    };
    
    m_listener->onTouchMoved = [blocks, controller](Touch* touch, Event* event)
    {

        
        XXL_Position pos;
        Vec2 touchPoints = Director::getInstance()->convertToGL(touch->getLocationInView());
        for(auto& item : blocks)
        {
            if(item->getBoundingBox().containsPoint(touchPoints))
            {
                pos.x = item->getBlockX();
                pos.y = item->getBlockY();
            }
        }
        controller->selectBlock(pos);
        return true;
    };
    
    m_listener->onTouchEnded = [](Touch* touch, Event* event)
    {
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

    return true;
}

void GameBoardLayer::update(float dt)
{
    //TODO: add your code here to update the whole view
}

