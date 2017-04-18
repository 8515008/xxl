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
    Block() {};
    ~Block() {};
    
    bool init() { return true;}
    
    CREATE_FUNC(Block);
    
public:
    bool isEmpty() {return 0==m_type; }
    void moveTo(XXL_Position pos);
    void moveToAndBack(XXL_Position pos);
    void toExplode();
    void pushCmd(XXL_CMD& cmd);
    void removeall() { m_cmd.clear(); }
    void removebegin();
    
    
    CC_SYNTHESIZE(std::vector<XXL_CMD>, m_cmd, Cmd);
    CC_SYNTHESIZE(int, m_x, X);
    CC_SYNTHESIZE(int, m_y, Y);
    CC_SYNTHESIZE(int, m_type, Type);
    CC_SYNTHESIZE(bool, m_isActionDone, IsActionDone);
};

#endif /* Block_hpp */
