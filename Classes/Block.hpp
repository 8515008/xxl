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

struct XXL_CMD
{
    std::string action;
};

class Block : public cocos2d::Ref
{
public:
    Block() {};
    ~Block() {};
    
    bool init() { return true;};
    
    CREATE_FUNC(Block);
    
public:
    void moveTo() {};
    
    CC_SYNTHESIZE(std::vector<XXL_CMD>, m_cmd, Cmd);
    CC_SYNTHESIZE(int, m_row, Row);
    CC_SYNTHESIZE(int, m_col, Col);
    CC_SYNTHESIZE(int, m_imgIndex, ImgIndex);
};

#endif /* Block_hpp */
