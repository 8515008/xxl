//
//  GameBoardModel.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/23.
//
//

#ifndef GameBoardModel_hpp
#define GameBoardModel_hpp

#include <stdio.h>

#include "Common.h"
#include "Block.hpp"

class GameBoardModel : public cocos2d::Ref
{
public:
    GameBoardModel();
    ~GameBoardModel();
    
    bool init() { return true;}
    
    CREATE_FUNC(GameBoardModel);
    
    bool init(int row, int col);
    std::vector<std::vector<Block*>> getBlocks();
public:
    void selectBlock(XXL_Position pos);
private:
    bool canExplode(XXL_Position pos);
    int getRandType();
    
private:
    const int BLOCKTYPE_NUM = 5;
    std::vector<std::vector<Block*>> m_vtblockMaps;
    
};

#endif /* GameBoardModel_hpp */
