//
//  PlayScene.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#include "PlayScene.hpp"

Scene* PlayScene::createScene()
{
    auto scene = PlayScene::create();
    
    auto layer = GameBoardLayer::createGameBoardLayer(scene);
    
    scene->addChild(layer);
    
    return (Scene*)scene;
}
