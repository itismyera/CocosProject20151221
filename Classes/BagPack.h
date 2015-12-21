//
//  BagPack.h
//  Test
//
//  Created by LRH on 15-11-30.
//
//

#ifndef __Test__BagPack__
#define __Test__BagPack__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class BagPack
:public Layer
{
public:
    CREATE_FUNC(BagPack);
    BagPack();
    virtual ~BagPack();
    virtual bool init();
    
    void tab1Callback(Ref* sender, ui::Widget::TouchEventType eventType);
    void tab2Callback(Ref* sender, ui::Widget::TouchEventType eventType);
    void tab3Callback(Ref* sender, ui::Widget::TouchEventType eventType);
    void tab4Callback(Ref* sender, ui::Widget::TouchEventType eventType);
    void tab5Callback(Ref* sender, ui::Widget::TouchEventType eventType);
    
    void onEnter();
    void onExit();
protected:
    void clearLayer(int tab);
private:
    Node* rootNode;
    int curTab;    
};

#endif /* defined(__Test__BagPack__) */
