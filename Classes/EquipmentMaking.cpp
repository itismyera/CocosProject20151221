//
//  EquipmentMaking.cpp
//  Test
//
//  Created by LRH on 15-12-11.
//
//

#include "EquipmentMaking.h"

static EquipmentMaking* equipmentmaking = NULL;

EquipmentMaking::EquipmentMaking()
{
    
}

EquipmentMaking::~EquipmentMaking()
{
    
}

EquipmentMaking* EquipmentMaking::getInstance()
{
   if(!equipmentmaking)
       equipmentmaking = new EquipmentMaking();
    return equipmentmaking;
}

bool EquipmentMaking::init()
{
    bool pet = false ;
    return pet;
    
}

void EquipmentMaking::makeMagicStone(int type)
{
    switch (type) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        default:
            break;
    }
}

