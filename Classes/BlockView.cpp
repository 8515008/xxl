//
//  BlockView.cpp
//  xiaoxiaole
//
//  Created by Andrew on 2017/1/23.
//
//

#include "BlockView.hpp"

bool BlockView:: initWithModel(Block* block)
{
    int bImageIndex = block->getType();
    std::string imageResource = mappingImage(bImageIndex);
    this->initWithSpriteFrameName(imageResource);
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
    int newX, newY;
    if(nullptr != m_block)
    {
        auto vtcmd = m_block->getCmd();
        if(vtcmd.size() > 0)
        {
            auto firstcmd = vtcmd.begin();
            switch((*firstcmd).action)
            {
                case XXL_ACTION::moveto:{
                    newX = m_block->getX();
                    newY = m_block->getY();
                    auto moveBy = MoveBy::create(0.5, Vec2(this->getContentSize().width, this->getContentSize().height));
                    this->runAction(moveBy);
                }
                    break;
                case XXL_ACTION::explode:{
                    
                }
                    break;
                default:
                    break;
            }

        }
    }
    else
    {
        
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
    addChild(circleSprite, 10);
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
    addChild(particleStars, 20);
}

void BlockView::actionEndCallback(Node *node)
{
    node->removeFromParent();
}

void BlockView::scheduleUpdate(float data)
{
    update(data);
}
