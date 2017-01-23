//
//  Block.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#include "Block.hpp"

Block* Block::create()
{
    auto block = new Block();
    
    block->autorelease();
    
    return block;
}
