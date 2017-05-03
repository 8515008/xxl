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
#include "PlayScene.hpp"

class PlayScene;
class GameBoardModel : public cocos2d::Ref
{
public:
    GameBoardModel();
    ~GameBoardModel();
    
    bool init() { return true;}
    
    CREATE_FUNC(GameBoardModel);
    
    bool init(int col, int row);
    std::vector<std::vector<Block*>> getBlocks();
public:
    void selectBlock(XXL_Position pos);
private:
    void getYNeighbor(Block* block, std::list<Block*> &chainList);
    void getXNeighbor(Block* block, std::list<Block*> &chainList);
    void removeChain(std::list<Block*> &chainList);
    bool canExplode(XXL_Position pos);
    void swapBlock(XXL_Position lastpos, XXL_Position pos);
    void fillRemovedBlocks();
    void updateBlockMaps(Block* block, XXL_Position pos);
    CC_SYNTHESIZE(PlayScene*, m_controller, Controller);
    int getRandType();
    
private:
    XXL_Position m_lastpos;
    const int BLOCKTYPE_NUM = 5;
    std::vector<std::vector<Block*>> m_vtblockMaps;
    std::vector<int> m_vtYaxisMoveSteps;
};

#endif /* GameBoardModel_hpp */
