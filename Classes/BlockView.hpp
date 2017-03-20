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
    int getBlockX();
    int getBlockY();
    void scheduleUpdate(float data);
    
    CREATE_FUNC(BlockView);
    
private:
    std::string mappingImage(int imageIndex);
    void explode();
    void actionEndCallback(Node *node);
    
    Block* m_block;
    
protected:
    virtual void update(float data);
 };

#endif /* BlockView_hpp */
