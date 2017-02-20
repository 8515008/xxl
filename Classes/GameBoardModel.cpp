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
            block->setCol(t);
            block->setRow(i);
            //block->setImgIndex(0);
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
                item->setImgIndex(getRandType());
                XXL_Position pos {item->getCol(), item->getRow() };
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
    return 0;
}

std::vector<std::vector<Block*>> GameBoardModel::getBlocks()
{
    return m_vtblockMaps;
}
