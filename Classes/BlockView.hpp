//
//  BlockView.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/23.
//
//

#ifndef BlockView_hpp
#define BlockView_hpp

#include <stdio.h>
#include "Block.hpp"

#include "common.h"


class BlockView : public Sprite
{
public:
    bool initWithModel(Block* block);
    
    CREATE_FUNC(BlockView);
private:
    Block* m_block;
 };

#endif /* BlockView_hpp */
