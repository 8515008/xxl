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

class GameBoardModel
{
public:
    GameBoardModel();
    ~GameBoardModel();
    
    bool init(int row, int col);
    std::vector<std::vector<Block*>> getBlocks();
    
private:
    std::vector<std::vector<Block*>> m_vtblockMaps;
    
};

#endif /* GameBoardModel_hpp */
