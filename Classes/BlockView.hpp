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
    CC_SYNTHESIZE(bool, m_isExploded, IsExploded);

public:
    CREATE_FUNC(BlockView);
    
    bool initWithModel(Block* block);
    int getBlockX();
    int getBlockY();
    void scheduleUpdate(float data);
    
private:
    Block* m_block;
    
    std::string mappingImage(int imageIndex);
    void explode();
    void actionEndCallback(Node *node);
    void moveDistance(XXL_Direction direction, int&x, int&y);
    
protected:
    virtual void update(float data);
 };

#endif /* BlockView_hpp */
