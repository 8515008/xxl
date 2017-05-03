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
    auto model = GameBoardModel::create();
    auto layer = GameBoardLayer::create();
    
    layer->setController(scene);
    model->setController(scene);
    model->init(6,6);
    
    scene->setGameBoardModel(model);
    
    
    layer->initWithBlockModels(model->getBlocks());
    
    
    scene->setGameBoardLayer(layer);
    
    scene->addChild(scene->getGameBoardLayer(),1);
    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Point(0, 1));
    background->setPosition(Point(0, Director::getInstance()->getWinSize().height));
    scene->addChild(background,0);
    
    scene->retain();

    return (Scene*)scene;
}

bool PlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    return true;
}

void PlayScene::selectBlock(XXL_Position pos)
{
    this->getGameBoardModel()->selectBlock(pos);
}

