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
            
            vectBlocks.push_back(block);
        }
        
        m_vtblockMaps.push_back(vectBlocks);
    }
    
    for(const auto& vtRow : m_vtblockMaps)
    {
        for(const auto& item : vtRow)
        {
            
        }
    }
    
    return true;
}

std::vector<std::vector<Block*>> GameBoardModel::getBlocks()
{
    return m_vtblockMaps;
}
