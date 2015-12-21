//
//  GameData.h
//  Test
//
//  Created by LRH on 15-12-4.
//
//

#ifndef __Test__GameData__
#define __Test__GameData__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
using namespace std;
USING_NS_CC;

typedef struct Hero
{
    int HeroHP;
    int HeroMP;
    int HeroLevel;
    int HeroAttNum;
    int HeroDefNum;
    std::string HeroName;
    
}Hero;

typedef struct NPC
{
    int NPCHP;
    int NPCMP;
    int NPCLevel;
    std::string NPCName;
    int NPCattNum;
    int NPCdefNum;
    int NPCN_id;
    Vec2 NPCpos;    
}NPC;

typedef struct MagicStrone
{
    int stronenum;
    std::string Stronename;
    int Stronetype;
}MagicStrone;

typedef struct Equipment
{
    std::string EquipmentName;
    int EquipmentType;
    int EquipmentAtt;
    int EquipmentDef;
}Equipment;

typedef struct Medicine
{
    std::string MedicineName;
    int MedicineNum;
    int addMp;
    int addHp;
    int MedicinePrice;
}Medicine;

class GameData
{
public:
    GameData();
    virtual ~GameData();
    //读取本地文件，返回数据
    static string  readLoaclData(string pFileName);
    bool saveDefault(char* pContent, string pFileName);
    static std::vector<std::string>splist(string str,string pattern);
    void readJson();
    
    static GameData* getInstance();
};

#endif /* defined(__Test__GameData__) */
