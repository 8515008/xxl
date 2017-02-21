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
    
};

struct XXL_CMD
{
    XXL_ACTION action;
    float playtime;
};

struct XXL_Position
{
    int x;
    int y;
    int xDirection;
    int yDirection;
};


#endif /* Common_h */



