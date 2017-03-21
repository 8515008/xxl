//
//  GameBoardModel.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/23.
//
//

#include "GameBoardModel.hpp"
#include "math.h"


GameBoardModel::GameBoardModel()
{
    m_lastpos.x = -1;
    m_lastpos.y = -1;
}

GameBoardModel::~GameBoardModel()
{
/*
    for(const auto& Yaxis : m_vtblockMaps)
    {
        for(const auto& item : Yaxis)
        {
            item->release();
        }
    }
 */
}

bool GameBoardModel::init(int row, int col)
{
    for(int i=0; i<col; ++i)
    {
        std::vector<Block*> vectBlocks;
        for(int t=0; t<row; ++t)
        {
            Block* block = Block::create();
            //block->retain();
            
            block->setX(t);
            block->setY(i);
            this->retain();
            vectBlocks.push_back(block);
        }
        
        m_vtblockMaps.push_back(vectBlocks);
    }
    
    
    for(const auto& Yaxis : m_vtblockMaps)
    {
        for(const auto& item : Yaxis)
        {
            while(1)
            {
                item->setType(getRandType());
                XXL_Position pos {item->getX(), item->getY() };
                
                /*if(!canExplode(pos))
                {
                    break;
                }*/
                break;
            }
        }
    }
    
    return true;
}

void GameBoardModel::selectBlock(XXL_Position pos)
{
    XXL_Position lastpos = this->m_lastpos;
    
    auto delta = abs(pos.x-lastpos.x) + abs(pos.y-lastpos.y);
    
    if(delta != 1)
    {
        this->m_lastpos = pos;
        return;
    }
    
    swapBlock(lastpos, pos);
    
    std::list<Block*> listXsameimg;
    std::list<Block*> listYsameimg;
    
    std::list<Block*> listXlastsameimg;
    std::list<Block*> listYlastsameimg;
    
    getXNeighbor(pos, listXsameimg);
    getYNeighbor(pos, listYsameimg);
    
    getXNeighbor(lastpos, listXlastsameimg);
    getYNeighbor(lastpos, listYlastsameimg);
    
    if(listXsameimg.size() >=3 || listYsameimg.size() >= 3 ||
       listXlastsameimg.size() >= 3 || listYlastsameimg.size() >= 3)
    {
        
    }else
    {
        //if can't be explode, swap back
        //swapBlock(lastpos, pos);
    }
    
    this->m_lastpos = pos;
}

void GameBoardModel::getYNeighbor(XXL_Position pos, std::list<Block*> &listSameImage)
{
    
}
void GameBoardModel::getXNeighbor(XXL_Position pos, std::list<Block*> &listSameImage)
{
    
}

void GameBoardModel::swapBlock(XXL_Position lastpos, XXL_Position pos)
{
    auto lastblock = m_vtblockMaps[lastpos.y][lastpos.x];
    auto curblock = m_vtblockMaps[pos.y][pos.x];
    
    XXL_CMD lastblockcmd {XXL_ACTION::moveto, 0.5, pos }, curblockcmd {XXL_ACTION::moveto, 0.5, lastpos};
 
    lastblock->pushCmd(lastblockcmd);
    curblock->pushCmd(curblockcmd);
    //should add code to update block new x and y, otherwise we will get an erro
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
