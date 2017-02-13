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
    static BlockView* create();
    bool initWithModel(Block* block);
    
    
private:
    String mappingImage(int imageIndex);
    Block* m_block;
    
 };

#endif /* BlockView_hpp */
