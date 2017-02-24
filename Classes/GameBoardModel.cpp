//
//  GameBoardModel.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/23.
//
//

#include "GameBoardModel.hpp"


GameBoardModel::GameBoardModel()
{}

GameBoardModel::~GameBoardModel()
{}

bool GameBoardModel::init(int row, int col)
{
    for(int i=0; i<row; ++i)
    {
        std::vector<Block*> vectBlocks;
        for(int t=0; t<col; ++t)
        {
            Block* block = Block::create();
            block->setX(t);
            block->setY(i);
            vectBlocks.push_back(block);
        }
        
        m_vtblockMaps.push_back(vectBlocks);
    }
    
    for(const auto& vtRow : m_vtblockMaps)
    {
        for(const auto& item : vtRow)
        {
            while(1)
            {
                item->setType(getRandType());
                XXL_Position pos {item->getX(), item->getY() };
                if(!canExplode(pos))
                {
                    break;
                }
            }
        }
    }
    
    return true;
}

void GameBoardModel::selectBlock(XXL_Position pos)
{
    
}

bool GameBoardModel::canExplode(XXL_Position pos)
{
    return false;
}

int GameBoardModel::getRandType()
{
    return int(random(0, BLOCKTYPE_NUM));
}

std::vector<std::vector<Block*>> GameBoardModel::getBlocks()
{
    return m_vtblockMaps;
}
