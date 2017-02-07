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
#include "BlockView.hpp"

USING_NS_CC;

class GameBoardLayer : public Layer
{
public:
    GameBoardLayer();
    virtual ~GameBoardLayer();
    
    virtual bool init();
    bool initWithBlockModels(std::vector<std::vector<Block*>>);
    CREATE_FUNC(GameBoardLayer);
    
protected:
    virtual void update(float dt);
    
public:
    static GameBoardLayer* createGameBoardLayer(GameBoardToSceneDelegate* delegate);

private:
    GameBoardToSceneDelegate* viewDelegate;
    std::vector<BlockView*> bViews;
    
};

#endif /* GameBoardLayer_hpp */
