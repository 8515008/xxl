//
//  Block.cpp
//  xiaoxiaole
//
//  Created by James Zhou on 2017/1/17.
//
//

#include "Block.hpp"
#include "GameBoardModel.hpp"

int g_nCountMoving;

void Block::moveTo(XXL_Position pos)
{
    //TODO we should lock here?
    
    XXL_CMD cmd;
    cmd.action = XXL_ACTION::moveto;
    cmd.playtime = 1;
    cmd.pos = pos;
    
    m_cmd.push_back(cmd);
}

void Block::pushCmd(XXL_CMD& cmd)
{
    if(cmd.action == XXL_ACTION::moveto)
        g_nCountMoving++;
    
    m_cmd.push_back(cmd);
}

void Block::removebegin()
{
    if(m_cmd.size() > 0)
        m_cmd.erase(m_cmd.begin());
    
    
}


void Block::moveToAndBack(XXL_Position pos)
{
    XXL_CMD cmdback;
    XXL_Position curpos {m_x,m_y};
    cmdback.action = XXL_ACTION::moveto;
    cmdback.playtime = 0.5;
    cmdback.pos = curpos;
    
    XXL_CMD cmdnew;
    cmdnew.action = XXL_ACTION::moveto;
    cmdnew.playtime = 0.5;
    cmdnew.pos = pos;
    
    m_cmd.push_back(cmdnew);
    m_cmd.push_back(cmdback);
}

void Block::toExplode()
{
    XXL_CMD cmd;
    cmd.action = XXL_ACTION::explode;
    cmd.playtime = 0.2;
    m_cmd.push_back(cmd);
}
