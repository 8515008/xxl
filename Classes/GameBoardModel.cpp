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

bool GameBoardModel::init(int col, int row)
{
    for(int i=0; i<row; ++i)
    {
        std::vector<Block*> vectBlocks;
        for(int t=0; t<col; ++t)
        {
            Block* block = Block::create();
            //block->retain();
            
            block->setX(t);
            block->setY(i);
            this->retain();
            vectBlocks.push_back(block);
        }
        
        m_vtblockMaps.push_back(vectBlocks);
        
        m_vtYaxisMoveSteps.push_back(0);
    }
    
    
    for(const auto& Yaxis : m_vtblockMaps)
    {
        for(const auto& item : Yaxis)
        {
            item->setType(getRandType());
            
            std::list<Block*> listXsameimg;
            std::list<Block*> listYsameimg;
            getXNeighbor(item, listXsameimg);
            getYNeighbor(item, listYsameimg);
            
            removeChain(listXsameimg);
            removeChain(listYsameimg);
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
    
    auto destBlock = m_vtblockMaps[pos.y][pos.x];
    auto srcBlock = m_vtblockMaps[lastpos.y][lastpos.x];
    
    getXNeighbor(destBlock, listXsameimg);
    getYNeighbor(destBlock, listYsameimg);
    
    getXNeighbor(srcBlock, listXlastsameimg);
    getYNeighbor(srcBlock, listYlastsameimg);
    
    if(listXsameimg.size() >=3 || listYsameimg.size() >= 3 ||
       listXlastsameimg.size() >= 3 || listYlastsameimg.size() >= 3)
    {
        removeChain(listXsameimg);
        removeChain(listYsameimg);
        removeChain(listYlastsameimg);
        removeChain(listXlastsameimg);
    }else
    {
        //if can't be explode, swap back
        swapBlock(lastpos, pos);
    }
    
    this->m_lastpos = pos;
}

void GameBoardModel::getYNeighbor(Block* block, std::list<Block*> &chainList)
{
    chainList.push_back(block);// add first sushi
    
    int neighborX = block->getX();
    int neighborY = block->getY() - 1;
    while (neighborY >= 0) {
        Block *neighborSushi = m_vtblockMaps[neighborY][neighborX];
        if (neighborSushi
            && (neighborSushi->getType() == block->getType())) {
            chainList.push_back(neighborSushi);
            neighborY--;
        } else {
            break;
        }
    }
    
    neighborY = block->getY() + 1;
    while (neighborY < m_vtblockMaps.size()) {
        Block *neighborSushi = m_vtblockMaps[neighborY][neighborX];
        if (neighborSushi
            && (neighborSushi->getType() == block->getType())) {
            chainList.push_back(neighborSushi);
            neighborY++;
        } else {
            break;
        }
    }
}
void GameBoardModel::getXNeighbor(Block* block, std::list<Block*> &chainList)
{
    chainList.push_back(block);// add first sushi
    
    int neighborX = block->getX() - 1;
    int neighborY = block->getY();
    while (neighborX >= 0) {
        Block *neighborSushi = m_vtblockMaps[neighborY][neighborX];
        if (neighborSushi
            && (neighborSushi->getType() == block->getType())) {
            chainList.push_back(neighborSushi);
            neighborX--;
        } else {
            break;
        }
    }
    
    neighborX = block->getX() + 1;
    while (neighborX < m_vtblockMaps[0].size()) {
        Block *neighborSushi = m_vtblockMaps[neighborY][neighborX];
        if (neighborSushi
            && (neighborSushi->getType() == block->getType())) {
            chainList.push_back(neighborSushi);
            neighborX++;
        } else {
            break;
        }
    }
}

void GameBoardModel::swapBlock(XXL_Position lastpos, XXL_Position pos)
{
    auto lastblock = m_vtblockMaps[lastpos.y][lastpos.x];
    auto curblock = m_vtblockMaps[pos.y][pos.x];
    XXL_Direction lastblockdirection,curblockdirection;
    if(pos.x - lastpos.x > 0)
    {
        lastblockdirection = XXL_Direction::right;
        curblockdirection = XXL_Direction::left;
    }
    else if(pos.x - lastpos.x < 0)
    {
        lastblockdirection = XXL_Direction::left;
        curblockdirection = XXL_Direction::right;
    }
    if(pos.y - lastpos.y >0)
    {
        lastblockdirection = XXL_Direction::up;
        curblockdirection = XXL_Direction::down;
    }
    else if(pos.y - lastpos.y < 0)
    {
        lastblockdirection = XXL_Direction::down;
        curblockdirection = XXL_Direction::up;
    }
    
    XXL_CMD lastblockcmd {XXL_ACTION::moveto, 0.5, pos,lastblockdirection}, curblockcmd {XXL_ACTION::moveto, 0.5, lastpos, curblockdirection};
 
    lastblock->pushCmd(lastblockcmd);
    curblock->pushCmd(curblockcmd);
    
    m_vtblockMaps[lastpos.y][lastpos.x] = curblock;
    m_vtblockMaps[pos.y][pos.x] = lastblock;
    updateBlockMaps(curblock, lastpos);
    updateBlockMaps(lastblock, pos);
}

void GameBoardModel::removeChain(std::list<Block*> &chainList)
{
    if(chainList.size() < 3) return;
    
    XXL_CMD cmd;
    cmd.action = XXL_ACTION::explode;
    for(auto &it : chainList)
    {
        it->pushCmd(cmd);
        
        m_vtYaxisMoveSteps[it->getX()]++;
        
        XXL_CMD cmdDrop;
        cmdDrop.action = XXL_ACTION::moveto;
        cmdDrop.direction = XXL_Direction::down;
        long row = m_vtblockMaps.size();
        
        for(int i=it->getY(); i< row; ++i)
        {
            m_vtblockMaps[i][it->getX()]->pushCmd(cmdDrop);
        }
    }
}

void GameBoardModel::fillRemovedBlocks()
{
    long size = m_vtYaxisMoveSteps.size();
    
    for(long i=0; i<size; ++i)
    {
        int step = m_vtYaxisMoveSteps[i];
        if(step > 0)
        {
            
        }
    }
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

void GameBoardModel::updateBlockMaps(Block *block, XXL_Position pos)
{
    block->setX(pos.x);
    block->setY(pos.y);
}
