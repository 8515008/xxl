//
//  PlayScene.cpp
//  xiaoxiaole
//
//  Created by test on 2017/1/17.
//
//

#include "PlayScene.hpp"
#include "editor-support/cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* PlayScene::createScene()
{
    auto scene = PlayScene::create();
    
    
    auto model = new GameBoardModel();
    model->init(6,6);
    
    scene->setGameBoardModel(model);
    
    auto layer = GameBoardLayer::createGameBoardLayer(scene);
    layer->initWithBlockModels(model->getBlocks());
    
    scene->setGameBoardLayer(layer);
    
    scene->addChild(scene->getGameBoardLayer());

    return (Scene*)scene;
}

bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    
    addChild(rootNode);
    
    return true;
}
