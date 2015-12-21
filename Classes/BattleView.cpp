//
//  BattleView.cpp
//  Test
//
//  Created by LRH on 15-12-18.
//
//

#include "BattleView.h"

BattleView::BattleView()
{
    
}

BattleView::~BattleView()
{
    
}

bool BattleView::init()
{
    if(!Layer::init())
        return false ;
    Size winSize = Director::getInstance()->getWinSize();
    
    Sprite* sp = Sprite::create("scene_battle_bg_1.jpg");
    sp->setPosition(Vec2(winSize.width/2,winSize.height/2));
    sp->setScale(winSize.width/640, winSize.height/960);
    this->addChild(sp);
    
    MenuItemImage* item = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(BattleView::beginFight, this));
    Menu* pMenu = Menu::create(item,NULL);
    pMenu->setPosition(Vec2(40,30));
    this->addChild(pMenu,1);
    return true ;
}

void BattleView::beginFight(Ref* pSender)
{
    
}