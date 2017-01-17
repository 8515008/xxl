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

using namespace cocos2d;

class GameBoardToSceneDelegate
{
public:
    virtual void ccTouchesBegan2(CCSet* touches, CCEvent* event)=0;
    virtual void ccTouchesEnded2(CCSet* touches, CCEvent* event)=0;
};

#endif /* Common_h */



