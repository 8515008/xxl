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
#include "common.h"
#include "Block.hpp"

USING_NS_CC;

class GameBoardLayer : public Layer
{
public:
    GameBoardLayer();
    virtual ~GameBoardLayer();
    
    virtual bool init();
    bool initWithBlockModels(Vector<Vector<Block*>>);
    CREATE_FUNC(GameBoardLayer);
    
protected:
    virtual void update(float dt);
    
public:
    static GameBoardLayer* createGameBoardLayer(GameBoardToSceneDelegate* delegate);

private:
    GameBoardToSceneDelegate* viewDelegate;
    
};

#endif /* GameBoardLayer_hpp */
