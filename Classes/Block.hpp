//
//  Block.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include "Common.h"

class Block : public cocos2d::Ref
{
public:
    static Block* create();
    
    Block() {};
    ~Block() {};
private:
    CC_SYNTHESIZE(int, m_row, Row);
    CC_SYNTHESIZE(int, m_col, Col);
    CC_SYNTHESIZE(int, m_imgIndex, ImgIndex);
};

#endif /* Block_hpp */
