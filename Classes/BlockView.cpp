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
    //this->initWithFile(imageResource);
    this->cocos2d::Sprite::create(imageResource);
    this->initWithFile(imageResource);
    //this->setAnchorPoint(Vec2(0,0));
    //this->setPosition(Vec2(bXCol*this->getContentSize().width, bYRow*this->getContentSize().height+Director::getInstance()->getVisibleSize().height/2-this->getContentSize().height*3));
    //TODO: init the block view
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
        return "block01.jpg";
    }
    if(imageIndex == 2)
    {
        return "block02.jpg";
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
