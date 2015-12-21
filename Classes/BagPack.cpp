//
//  BagPack.cpp
//  Test
//
//  Created by LRH on 15-11-30.
//
//

#include "BagPack.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define  LAYER_OPTIONS_TAG  10001
#define  LAYER_STATUS_TAG   10002
#define  LAYER_GOODS_TAG    10003
#define  LAYER_MAGICS_TAG   10004
#define  LAYER_SYSTEM_TAG   10005

BagPack::BagPack()
:curTab(1),
rootNode(NULL)
{
    
}

BagPack::~BagPack()
{
    
}

void BagPack::onEnter()
{
    Layer::onEnter();
}

void BagPack::onExit()
{
    Layer::onExit();
}

bool BagPack::init()
{
    bool pet =false;
    do{
        if ( !Layer::init() )
        {
            return false;
        }
        rootNode = CSLoader::createNode("BagPack.csb");
        
        //RollLabel* roll = RollLabel::create();
        //layer->addChild(roll);
        //rootNode->addChild(roll);
        addChild(rootNode);
        
        ui::Button* tab1 = (ui::Button*)rootNode->getChildByName("options");
        ui::Button* tab2 = (ui::Button*)rootNode->getChildByName("status");
        ui::Button* tab3 = (ui::Button*)rootNode->getChildByName("goods");
        ui::Button* tab4 = (ui::Button*)rootNode->getChildByName("magics");
        ui::Button* tab5 = (ui::Button*)rootNode->getChildByName("system");
        
        tab1->addTouchEventListener(CC_CALLBACK_2(BagPack::tab1Callback,this));
        tab2->addTouchEventListener(CC_CALLBACK_2(BagPack::tab2Callback,this));
        tab3->addTouchEventListener(CC_CALLBACK_2(BagPack::tab3Callback,this));
        tab4->addTouchEventListener(CC_CALLBACK_2(BagPack::tab4Callback,this));
        tab5->addTouchEventListener(CC_CALLBACK_2(BagPack::tab5Callback,this));
        
        pet = true;
    }while(0);
    return pet;
}

void BagPack::tab1Callback(Ref*, ui::Widget::TouchEventType)
{
    //LayerMenu* menu = LayerMenu::create();
    //addChild(menu);
    if(curTab == 1) return;
    curTab = 1;
    clearLayer(curTab);
    
    
}

void BagPack::tab2Callback(Ref*, ui::Widget::TouchEventType type)
{
    if(curTab == 2)return;
    curTab = 2;
}

void BagPack::tab3Callback(Ref*, ui::Widget::TouchEventType)
{
    if(curTab == 3)return;
    curTab = 3;
}

void BagPack::tab4Callback(Ref*, ui::Widget::TouchEventType)
{
    if(curTab == 4)return;
    curTab = 4;
}

void BagPack::tab5Callback(Ref*, ui::Widget::TouchEventType)
{
    if(curTab == 5)return;
    curTab = 5;
}

void BagPack::clearLayer(int tab)
{
    switch(tab)
    {
       case 1:
            break;
       default:
            break;
        
    }
}






