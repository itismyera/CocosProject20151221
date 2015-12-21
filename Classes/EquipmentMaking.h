//
//  EquipmentMaking.h
//  Test
//
//  Created by LRH on 15-12-11.
//
//

#ifndef __Test__EquipmentMaking__
#define __Test__EquipmentMaking__

#include "cocos2d.h"
USING_NS_CC;

class EquipmentMaking
{
public:
    static EquipmentMaking* getInstance();
    //CREATE_FUNC(EquipmentMaking);
    bool init();
    EquipmentMaking();
    ~EquipmentMaking();
    void makeMagicStone(int type);
    void setView();
    
};

#endif /* defined(__Test__EquipmentMaking__) */
