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
    int bXCol = block->getCol();
    int bYRow = block->getRow();
    int bImageIndex = block->getImgIndex();
    std::string imageResource = mappingImage(bImageIndex);
    this->initWithFile(imageResource);
    this->setPosition(Vec2(bXCol*this->getContentSize().width, bYRow*this->getContentSize().height));
    //TODO: init the block view
    m_block = block;
    return true;
}



std::string BlockView::mappingImage(int imageIndex)
{
    return "";
}

void BlockView::update(float data)
{
    int newXCol, newYRow;
    if(m_block!=NULL)
    {
        newXCol = m_block->getCol();
        newYRow = m_block->getRow();
        auto moveBy = MoveBy::create(0.5, Vec2(this->getContentSize().width, this->getContentSize().height));
        this->runAction(moveBy);
    }
    else
    {
        
    }
}
