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
    //PlayScene* controller;
    //controller = m_controller;
    //std::vector<BlockView*> blockView;
    //blockView = blocks;
    /*
    m_listener->onTouchBegan = [](Touch* touch, Event* event)
    {
        return true;
    };
    
    m_listener->onTouchMoved = [blockView, controller](Touch* touch, Event* event)
    {
        XXL_Position pos;
        for(auto& item : blockView)
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
    */
    return true;
}

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    //Vec2 startPoint = Vec2(bXCol*this->getContentSize().width, bYRow*this->getContentSize().height+Director::getInstance()->getVisibleSize().height/2-this->getContentSize().height*3);
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
    
    m_listener->onTouchBegan = [blocks](Touch* touch, Event* event)
    {
        
        for(auto& item : blocks)
        {
            Point posi = Director::getInstance()->convertToGL(touch->getLocationInView());
            int x = posi.x;
            int y = posi.y;
            Rect MinX = item->getTextureRect();
            Rect MaxX = item->getTextureRect();
            //Rect::containsPoint(item->getBoundingBox(), )
            Rect a = item->getBoundingBox();
            Size b = item->getContentSize();
            Rect c = item->getTextureRect();
            if(item->getBoundingBox().containsPoint(Director::getInstance()->convertToGL(touch->getLocationInView())))
            {
                return true;
            }
        }
        
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

