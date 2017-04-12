//
//  Common.h
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#ifndef Common_h
#define Common_h

#include "cocos2d.h"

USING_NS_CC;

enum XXL_ACTION
{
    moveto,
    explode,
    explodeline,
};

struct XXL_Position
{
    int x;
    int y;
};

enum XXL_Direction
{
    up,
    down,
    left,
    right,
};


struct XXL_CMD
{
    XXL_ACTION action;
    float playtime;
    XXL_Position pos;
    XXL_Direction dirction;
};

extern int CountMoving;

#endif /* Common_h */



