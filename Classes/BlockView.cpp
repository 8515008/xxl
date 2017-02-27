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
    int bXCol = block->getX();
    int bYRow = block->getY();
    int bImageIndex = block->getType();
    std::string imageResource = mappingImage(bImageIndex);
    this->cocos2d::Sprite::create(imageResource);
    this->initWithFile(imageResource);
    m_block = block;
    return true;
}



std::string BlockView::mappingImage(int imageIndex)
{
    if(imageIndex == 0)
    {
        return "block.jpg";
    }
    if(imageIndex == 1)
    {
        return "block.jpg";
    }
    if(imageIndex == 2)
    {
        return "block.jpg";
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
    Block* b;
    b = this->m_block;
    return b->getX();
}

int BlockView::getBlockY()
{
    return this->m_block->getY();
}
