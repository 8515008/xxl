//
//  BlockView.cpp
//  xiaoxiaole
//
//  Created by Andrew Feng on 2017/1/23.
//
//

#include "BlockView.hpp"


bool BlockView:: initWithModel(Block* block)
{
    int nBlockImageIndex = block->getType();
    std::string stImageResource = mappingImage(nBlockImageIndex);
    this->initWithSpriteFrameName(stImageResource);
    m_block = block;
    return true;
}


std::string BlockView::mappingImage(int imageIndex)
{
    if(imageIndex == 0)
    {
        return "sushi_1n.png";
    }
    if(imageIndex == 1)
    {
        return "sushi_2n.png";
    }
    if(imageIndex == 2)
    {
        return "sushi_3n.png";
    }
    if(imageIndex == 3)
    {
        return "sushi_4n.png";
    }
    if(imageIndex == 4)
    {
        return "sushi_5n.png";
    }
    if(imageIndex == 5)
    {
        return "sushi_6n.png";
    }
    return "";
}

void BlockView::update(float data)
{
    if(this->getNumberOfRunningActions() > 0) return;
    
    if(nullptr != m_block)
    {
        auto vtcmd = m_block->getCmd();
        if(vtcmd.size() > 0)
        {
            auto firstcmd = (*vtcmd.begin());
            switch(firstcmd.action)
            {
                case XXL_ACTION::moveto:{
                    int x = 0, y = 0;
                    moveDistance(firstcmd.direction,x,y);
                    auto moveBy = MoveBy::create(0.3, Vec2(x*this->getContentSize().width, y*this->getContentSize().height));
                    this->runAction(Sequence::create(moveBy,NULL));
                    
                    //g_nCountMoving--;
                }
                    break;
                case XXL_ACTION::explode:{
                    explode();
                }
                    break;
                default:
                    break;
            }
            
            m_block->removebegin();
        }
    }
    else
    {
        
    }
}

void BlockView::moveDistance(XXL_Direction direction, int&x, int&y)
{
    switch (direction) {
        case up:
            y = 1;
            break;
            
        case down:
            y = -1;
            break;
            
        case right:
            x = 1;
            break;
            
        case left:
            x = -1;
            break;
            
        default:
            break;
    }
}

int BlockView::getBlockX()
{
    return m_block->getX();
}

int BlockView::getBlockY()
{
    return m_block->getY();
}

void BlockView::explode()
{
    float time = 0.3;
    
    // 1. action for sushi
    this->runAction(Sequence::create(
                                      ScaleTo::create(time, 0.0),
                                      CallFuncN::create(CC_CALLBACK_1(BlockView::actionEndCallback, this)),
                                      NULL));
    
    // 2. action for circle
    auto circleSprite = Sprite::create("circle.png");
    this->getParent()->addChild(circleSprite, 10);
    circleSprite->setPosition(this->getPosition());
    circleSprite->setScale(0);// start size
    circleSprite->runAction(Sequence::create(ScaleTo::create(time, 1.0),
                                             CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, circleSprite)),
                                             NULL));
    
    // 3. particle effect
    auto particleStars = ParticleSystemQuad::create("stars.plist");
    particleStars->setAutoRemoveOnFinish(true);
    particleStars->setBlendAdditive(false);
    particleStars->setPosition(this->getPosition());
    particleStars->setScale(0.3);
    this->getParent()->addChild(particleStars, 20);
    
    //this->m_block->release();
}

void BlockView::actionEndCallback(Node *node)
{
    m_isExploded = true;
    //node->removeFromParent();
}

void BlockView::scheduleUpdate(float data)
{
    update(data);
}
