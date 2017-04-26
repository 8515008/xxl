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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sushi.plist");
    scheduleUpdate();
    return true;
}

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> blockMetrics)
{
    //TODO: draw the matrixs according to the model data
    float ySize = blockMetrics.size(); // 获取二维数组的Y值
    float xSize = (*blockMetrics.begin()).size(); // 获取二维数组的X值
    //std::vector<std::vector<Block*>>::iterator rows;
    float x=0, y=0; //重新创建数组的x和y
    Size winSize = Director::getInstance()->getWinSize();

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
            
            float blockX = winSize.width/2 + block->getContentSize().width * (x+(1-xSize)/2);
            float blockY = winSize.height/2 + block->getContentSize().height * (y+(1-ySize)/2);
            Point endPosition = Point(blockX, blockY);
            Point startPosition = Point(endPosition.x, endPosition.y + winSize.height*3 / 4);
            block->setPosition(Vec2(startPosition.x, startPosition.y));
            
            this->addChild(block);
            
            float speed = startPosition.y / (1.5 * winSize.height);
            block->runAction(MoveTo::create(speed, endPosition));
            bViews.push_back(block);
            ++x;
        }
        ++y;
    }
    
    m_listener->onTouchBegan = [this](Touch* touch, Event* event)
    {
        return true;
    };
    
    m_listener->onTouchMoved = [this](Touch* touch, Event* event)
    {
        for (int i = 0; i < bViews.size(); i++) {
            BlockView *item = bViews[i];
            if (item->getNumberOfRunningActions() > 0) {
                return true;
            }
        }
        if(CountMoving == 0)
        {
            XXL_Position pos;
            Vec2 touchPoints = Director::getInstance()->convertToGL(touch->getLocationInView());
            for(auto& item : bViews)
            {
                if(item->getBoundingBox().containsPoint(touchPoints))
                {
                    pos.x = item->getBlockX();
                    pos.y = item->getBlockY();
                }
            }
            m_controller->selectBlock(pos);
        }
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
    for(Vector<BlockView*>::iterator iter = bViews.begin(); iter != bViews.end(); iter++)
    {
        if((*iter)->getIsBoom())
        {
            (*iter)->removeFromParent();
            (*iter)->release();
            bViews.erase(iter);
        }
        else
        {
            (*iter)->scheduleUpdate(dt);
        }
    }
}

