//
//  GameBoardLayer.hpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#ifndef GameBoardLayer_hpp
#define GameBoardLayer_hpp

#include <stdio.h>
#include "cocos2d.h"

#endif /* GameBoardLayer_hpp */

using namespace cocos2d;

class GameBoardLayer : public CCLayer
{
public:
    GameBoardLayer();
    virtual ~GameBoardLayer();
    
    virtual bool init();
    CREATE_FUNC(GameBoardLayer);
};
