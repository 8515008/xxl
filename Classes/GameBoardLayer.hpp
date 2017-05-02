//
//  GameBoardLayer.hpp
//  xiaoxiaole
//
//  Created by Andrew Feng on 2017/1/17.
//
//

#ifndef GameBoardLayer_hpp
#define GameBoardLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "common.h"
#include "Block.hpp"
#include "BlockView.hpp"
#include "PlayScene.hpp"

USING_NS_CC;

class PlayScene;
class GameBoardLayer : public Layer
{
    CC_SYNTHESIZE(PlayScene*, m_controller, Controller);
    
public:
    GameBoardLayer();
    virtual ~GameBoardLayer();
    
public:
    CREATE_FUNC(GameBoardLayer);
    
    virtual bool init();
    bool initWithBlockModels(std::vector<std::vector<Block*>>);
    
protected:
    virtual void update(float dt);
    
private:
    std::vector<BlockView*> m_vtBlockViews;
    EventListenerTouchOneByOne* m_listener;
    //std::vector<BlockView*> blocks;
    
    std::string mappingImage(int imageIndex);
    void createAndDropBlocks(BlockView* block);
    Point positionOfItem(BlockView* block);
    //int i;
    
};

#endif /* GameBoardLayer_hpp */
