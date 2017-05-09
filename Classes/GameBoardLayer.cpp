//
//  GameBoardLayer.cpp
//  xiaoxiaole
//
//  Created by Andrew Feng on 2017/1/17.
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

bool GameBoardLayer::initWithBlockModels(std::vector<std::vector<Block*>> vtBlockMetrics)
{
    float fYSize = vtBlockMetrics.size(); // 获取二维数组的Y值
    float fXSize = (*vtBlockMetrics.begin()).size(); // 获取二维数组的X值
    float fX=0, fY=0,fYTemp; //用于轮询的数组的x，y和中间临时变量
    Size winSize = Director::getInstance()->getWinSize();
    
    for (auto& rows : vtBlockMetrics)
    {
        for(auto& row : rows)
        {
            BlockView* block = BlockView::create();
            row->retain(); //避免Cocos自动释放BlockView
            block->initWithModel(row);
            
            if(fYTemp != fY)
            {
                fYTemp = fY;
                fX = 0;
            }
            
            float fBlockXPos = winSize.width/2 + block->getContentSize().width * (fX+(1-fXSize)/2);
            float fBlockYPos = winSize.height/2 + block->getContentSize().height * (fY+(1-fYSize)/2);
            Point endPosition = Point(fBlockXPos, fBlockYPos);
            Point startPosition = Point(endPosition.x, endPosition.y + winSize.height*3 / 4);
            block->setPosition(Vec2(startPosition.x, startPosition.y));
            
            this->addChild(block);
            
            float fSpeed = startPosition.y / (1.5 * winSize.height);
            block->runAction(MoveTo::create(fSpeed, endPosition));
            m_vtBlockViews.push_back(block);
            ++fX;
        }
        ++fY;
    }
    
    m_listener->onTouchBegan = [this](Touch* touch, Event* event)
    {
        //目前没有特别操作是针对TouchBegan的
        return true;
    };
    
    m_listener->onTouchMoved = [this](Touch* touch, Event* event)
    {
        for (int i = 0; i < m_vtBlockViews.size(); i++) {
            BlockView* pItem = m_vtBlockViews[i];
            if (pItem->getNumberOfRunningActions() > 0) {
                return true;
            }
        }
        
        //if(g_nCountMoving == 0)
        {
            XXL_Position position;
            Vec2 vcTouchPoints = Director::getInstance()->convertToGL(touch->getLocationInView());
            for(auto& item : m_vtBlockViews)
            {
                if(item->getBoundingBox().containsPoint(vcTouchPoints))
                {
                    position.x = item->getBlockX();
                    position.y = item->getBlockY();
                }
            }
            m_controller->selectBlock(position);
        }
        return true;
    };
    
    m_listener->onTouchEnded = [](Touch* touch, Event* event)
    {
        //目前没有特别操作是针对TouchEnded的
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(m_listener, this);

    return true;
}

void GameBoardLayer::update(float dt)
{
    for(Vector<BlockView*>::iterator iter = m_vtBlockViews.begin(); iter != m_vtBlockViews.end(); iter++)
    {
        if((*iter)->getIsExploded())
        {
            (*iter)->removeFromParent();
            (*iter)->release();
            m_vtBlockViews.erase(iter);
        }
        else
        {
            (*iter)->scheduleUpdate(dt);
        }
    }
}

