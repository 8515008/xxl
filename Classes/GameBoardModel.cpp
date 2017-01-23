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
    return true;
}

Vector<Vector<Block*>> GameBoardModel::getBlocks()
{
    return m_vtblockMaps;
}
