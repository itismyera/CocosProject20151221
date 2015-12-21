#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    void btnPress(Ref* sender,cocos2d::ui::Widget::TouchEventType type);
    //显示动画
    void showAnimation();
    //添加字体
    void addFont(Ref* sender);
    //滚动字体
    void showScollText();
    //显示拖尾效果
    void showMotionStreak();
    
    //渲染中的画图效果
    //void onDraw();
    //virtual void visit(Renderer* renderer, const Mat4& transform, uint32_t parentFlags)override;
    
    //npc对话框效果
    void showNPCDialog();
    
    //画图的一些函数
    void drawElement();
    
    //屏幕截图
    void capture(Ref* sender);
    void afterCapture(bool succeed, const std::string& outputFile);
private:
    Sprite* addSprite;
    CustomCommand _command;
    
};

#endif // __HELLOWORLD_SCENE_H__
