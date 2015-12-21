//
//  SkillEffect.h
//  Test
//
//  Created by LRH on 15-12-4.
//
//

#ifndef __Test__SkillEffect__
#define __Test__SkillEffect__

#include "cocos2d.h"
USING_NS_CC;

class SkillEffect : public Node
{
public:
    static SkillEffect* create();
    void init(int type);
    SkillEffect();
    ~SkillEffect();
    
    int effectid;
    std::string firstPngName;
    std::string effectName;
    Vec2 pt;
    
    //释放精灵
    void killSprite(Node* pSender);
    //动画演示
    void explode(Node* parent,Vec2 from, Vec2 pos);
    static void sharedExplosion();
    //计算两个精灵之间的角度
    float CalDirection(float xStart, float yStart, float xEnd, float yEnd);
    
    void MotionStreakEffect(cocos2d::Node *parent);
private:
    Sprite* m_spr;
    Sprite* star;
    MotionStreak* streak;
};

#endif /* defined(__Test__SkillEffect__) */
