//
//  GameCore.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#ifndef GameCore_hpp
#define GameCore_hpp

#include <stdio.h>
#include "cocos2d.h"

#endif /* GameCore_hpp */

#include "Block.hpp"

using namespace cocos2d;

class GameCore {
public:
    GameCore(int row, int col);
    ~GameCore();
private:
    Block** mapBlocks;
    
    int nRow;
    int nCol;
};
