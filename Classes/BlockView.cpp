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
    String imageResource = mappingImage(bImageIndex);
    this = cocos2d::Sprite::create(imageResource);
    this->setPosition(cocos2d::Vec2(bXCol*)
    //TODO: init the block view
    m_block = block;
                          
    return true;
}

String BlockView::mappingImage(int imageIndex)
{
    
}
