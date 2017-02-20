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
    return true;
}

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    std::vector<std::vector<Block*>>::iterator rows;
    std::vector<BlockView*> blocks;
    PlayScene* controller;
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

    blocks = bViews;
    
    controller = m_controller;
 
    m_listener->onTouchBegan = [](Touch* touch, Event* event)
    {
        return true;
    };
    
    m_listener->onTouchMoved = [blocks, controller](Touch* touch, Event* event)
    {
        XXL_Position pos;

        for(auto& item : blocks)
        {
            if(item->getTextureRect().containsPoint(touch->getLocation()))
            {
                auto xMovedLength = touch->getLocation().x-touch->getStartLocation().x;
                auto yMovedLength = touch->getLocation().y-touch->getStartLocation().y;
                MoveBy* moveBy;
                if((std::abs(xMovedLength) > std::abs(yMovedLength)))
                {
                    pos.xDirection = xMovedLength;
                    if(xMovedLength > 0)
                    {
                        moveBy = MoveBy::create(0.5, Vec2(0, item->getContentSize().width));
                    }
                    else
                    {
                        moveBy = MoveBy::create(0.5, Vec2(0, -item->getContentSize().width));
                    }
                }
                else
                {
                    pos.yDirection = yMovedLength;
                    if(yMovedLength > 0)
                    {
                        moveBy = MoveBy::create(0.5, Vec2(item->getContentSize().height,0));
                    }
                    else
                    {
                        moveBy = MoveBy::create(0.5, Vec2(-item->getContentSize().height, 0));
                    }
                }
                item->runAction(moveBy);
                pos.x = (item->getPositionX())/(item->getContentSize().width);
                pos.y = (item->getPositionY()-(Director::getInstance()->getVisibleSize().height/2-item->getContentSize().height*3))/(item->getContentSize().height);
            }
        }
        
        controller->selectBlock(pos);
        return true;
    };
    
    m_listener->onTouchEnded = [](Touch* touch, Event* event)
    {
        return true;
    };
    return true;
}


void GameBoardLayer::update(float dt)
{
    //TODO: add your code here to update the whole view
}

