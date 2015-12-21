//
//  SkillEffect.cpp
//  Test
//
//  Created by LRH on 15-12-4.
//
//

#include "SkillEffect.h"
#include "math.h"

const float PI = 3.141592f;

SkillEffect::SkillEffect()
{
    
}

SkillEffect::~SkillEffect()
{
    
}

SkillEffect* SkillEffect::create()
{
    SkillEffect* effect = new SkillEffect();
    if(effect)
    {
        effect->autorelease();
        return effect;
    }
    else
    {
        delete effect;
        effect = NULL;
        return NULL;
    }
}

void SkillEffect::init(int type)
{
    effectid = type;
    switch (type) {
        case 1:
        {
            //使用texturePacker打包精灵对象，帧加载
            SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/effect1/effect1.plist");
            Vector<SpriteFrame*> animFrames;//3.0Vector代替CCArray
            firstPngName = "1000.png";
            effectName = "effect1";
            char str[64] = {0};
            for(int i =0; i< 6; ++i)
            {
                sprintf(str, "100%d.png", i);
                SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
                animFrames.pushBack(frame);
            }
            Animation* animation = Animation::createWithSpriteFrames(animFrames,0.1);
            AnimationCache::getInstance()->addAnimation(animation,effectName.c_str());
        }
         break;
        case 2:
        {
            //单独加载精灵对象，直接从文件添加帧动画
            auto animation = Animation::create();
            firstPngName = "res/effect2/1.png";
            effectName = "effect2";
            char str[64] = {0};
            for(int i =1; i< 46; ++i)
            {
                sprintf(str, "res/effect2/%d.png", i);
                animation->addSpriteFrameWithFile(str);
            }            
            animation->setDelayPerUnit(0.1);
            AnimationCache::getInstance()->addAnimation(animation,effectName.c_str());
        }
            break;
        case 3:
        {
            //一次加载，使用精灵帧
            firstPngName = "res/effect3/1.png";
            effectName = "effect3";
            Vector<SpriteFrame*> animFrames;
            char str[64] = {0};
            for(int i =1; i< 46; ++i)
            {
                sprintf(str, "res/effect2/%d.png", i);
                auto texTure = Director::getInstance()->getTextureCache()->addImage(str);
                SpriteFrame* frame0 = SpriteFrame::createWithTexture(texTure, Rect(0,0,500,500));
                animFrames.pushBack(frame0);
            }            
            Animation* animation = Animation::createWithSpriteFrames(animFrames,0.1);
            AnimationCache::getInstance()->addAnimation(animation,effectName.c_str());
        }
            break;
        default:
            break;
    }
}

void SkillEffect::explode(cocos2d::Node *parent, cocos2d::Vec2 from, cocos2d::Vec2 pos)
{
    if(effectid == 1)
    {
        pt = pos;
        //第一帧
        SpriteFrame* pFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(firstPngName.c_str());
        Sprite* explosion  = Sprite::createWithSpriteFrame(pFrame);
        parent->addChild(explosion);
        explosion->setPosition(pos);
        // 完成之后的回调
        CallFuncN *removeFunc = CallFuncN::create(std::bind(&SkillEffect::killSprite, this, explosion));
        // 爆炸动画
        Animation *animation = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        explosion->runAction(Sequence::create(Animate::create(animation),removeFunc, NULL));
        
        //移动
        Sprite* explosion1  = Sprite::createWithSpriteFrame(pFrame);
        parent->addChild(explosion1);
        explosion1->setPosition(from);
        float angle = CalDirection(from.x,from.y,pos.x,pos.y);
        explosion1->setRotation(angle);
        CallFuncN *removeFunc1 = CallFuncN::create(std::bind(&SkillEffect::killSprite,this,explosion1));
        ActionInterval* moveTo = MoveTo::create(0.5, pos);
        Animation* animation1 = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        explosion1->runAction(Sequence::create(Animate::create(animation1),moveTo,removeFunc1, NULL));
    }
    else if(effectid == 2)
    {
        Sprite* explosion  = Sprite::create(firstPngName);
        parent->addChild(explosion);
        explosion->setPosition(pos);
        
        CallFuncN *removeFunc = CallFuncN::create(std::bind(&SkillEffect::killSprite, this, explosion));
        Animation *animation = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        auto action = Animate::create(animation);
        explosion->runAction(Sequence::create(action,removeFunc, NULL));
        
        //移动
        Sprite* explosion1  = Sprite::create(firstPngName);
        parent->addChild(explosion1);
        explosion1->setPosition(from);
        //float angle = CalDirection(from.x,from.y,pos.x,pos.y);
        //explosion1->setRotation(angle);
        CallFuncN *removeFunc1 = CallFuncN::create(std::bind(&SkillEffect::killSprite,this,explosion1));
        ActionInterval* moveTo = MoveTo::create(0.5, pos);
        Animation* animation1 = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        explosion1->runAction(Sequence::create(Animate::create(animation1),moveTo,removeFunc1, NULL));
        
    }
    else if(effectid == 3)
    {
        pt = pos;
        //第一帧
        SpriteFrame* pFrame = SpriteFrame::createWithTexture(Director::getInstance()->getTextureCache()->addImage(firstPngName.c_str()), Rect(0,0,500,500));
        Sprite* explosion  = Sprite::createWithSpriteFrame(pFrame);
        parent->addChild(explosion);
        explosion->setPosition(pos);
        // 完成之后的回调
        CallFuncN *removeFunc = CallFuncN::create(std::bind(&SkillEffect::killSprite, this, explosion));
        // 爆炸动画
        Animation *animation = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        explosion->runAction(Sequence::create(Animate::create(animation),removeFunc, NULL));
        
        //移动
        Sprite* explosion1  = Sprite::createWithSpriteFrame(pFrame);
        parent->addChild(explosion1);
        explosion1->setPosition(from);
        //float angle = CalDirection(from.x,from.y,pos.x,pos.y);
        //explosion1->setRotation(angle);
        CallFuncN *removeFunc1 = CallFuncN::create(std::bind(&SkillEffect::killSprite,this,explosion1));
        ActionInterval* moveTo = MoveTo::create(0.5, pos);
        Animation* animation1 = AnimationCache::getInstance()->getAnimation(effectName.c_str());
        explosion1->runAction(Sequence::create(Animate::create(animation1),moveTo,removeFunc1, NULL));
    }

    else return ;
    
}

void SkillEffect::killSprite(Node *pSender)
{
    if(pSender)
        pSender->removeFromParentAndCleanup(true);
}

float SkillEffect::CalDirection(float xStart, float yStart, float xEnd, float yEnd)
{
    double accDir=0;
    float vecX = xEnd - xStart;
    float vecY = yEnd - yStart;
    
    if(abs(vecX) < 0.00001f)
    {
        if(vecY > 0)
        {
            accDir = 0;
        }
        else if(vecY < 0)
        {
            accDir = PI;
        }
    }
    else
    {
        accDir = atan(vecY / vecX);
        
        if(vecX >=0)
        {
            accDir = PI*0.5 - accDir;
        }
        else
        {
            accDir = PI*1.5 - accDir;
        }
    }
    
    return (float)(accDir * 180.0f / PI);
}

void SkillEffect::MotionStreakEffect(cocos2d::Node *parent)
{
    star = Sprite::create("hurt.png");
    star->setPosition(Vec2(100,100));
    parent->addChild(star);
    
    streak = MotionStreak::create(0.5f,50,30,Color3B::WHITE,"steak.jpg");
    streak->setPosition(star->getPosition());
    parent->addChild(streak);
    
    ActionInterval* action = MoveTo::create(2.0, Vec2(300,300));
    runAction(action);
}
