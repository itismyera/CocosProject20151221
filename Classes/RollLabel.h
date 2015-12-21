//
//  RollLabel.h
//  Test
//
//  Created by LRH on 15-11-24.
//
//

#ifndef __Test__RollLabel__
#define __Test__RollLabel__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"//用到了Scale9Sprite
USING_NS_CC;
USING_NS_CC_EXT;

class RollLabel : public Layer
{
public:
    CREATE_FUNC(RollLabel);
    RollLabel();
    ~RollLabel();
    virtual bool init();
    static Scene* createScene();
    
    void drawArea();
    void verticalScrolling(float t);
    void horizontalScrolling(float t);
    
    virtual void onEnter();
    virtual void onExit();
protected:
private:
    Label* strContents;
    int flag;
};

#endif /* defined(__Test__RollLabel__) */
