//
//  BlockView.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/23.
//
//

#include "BlockView.hpp"

bool BlockView:: initWithModel(Block* block)
{
    int bImageIndex = block->getType();
    std::string imageResource = mappingImage(bImageIndex);
    this->cocos2d::Sprite::initWithSpriteFrameName(imageResource);
    Rect* rec = new Rect();
    rec->setRect(0, 0, 200, 200);
    this->Sprite::create(imageResource, *rec);
    this->initWithFile(imageResource);
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
    
}
