//
//  BattleView.h
//  Test
//
//  Created by LRH on 15-12-18.
//
//

#ifndef __Test__BattleView__
#define __Test__BattleView__

#include "cocos2d.h"
USING_NS_CC;

class BattleView : public Layer
{
public:
    virtual bool init();
    BattleView();
    ~BattleView();
    void beginFight(Ref* pSender);
};

#endif /* defined(__Test__BattleView__) */
