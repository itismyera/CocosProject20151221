//
//  RollLabel.cpp
//  Test
//
//  Created by LRH on 15-11-24.
//
//

#include "RollLabel.h"

RollLabel::RollLabel()
:strContents(NULL)
,flag(0)
{
    
}

RollLabel::~RollLabel()
{
    
}

/*
Scene* RollLabel::createScene()
{
    auto scene = Scene::create();
    auto layer = RollLabel::create();
    scene->addChild(layer);
    return scene;
}
*/
bool RollLabel::init()
{
    bool Ref = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        drawArea();
        Ref = true;
    }while (0);

    return Ref;
}

void RollLabel::drawArea()
{
    strContents = Label::createWithTTF("I have given all your submissions a try and picked a few I’d like to share. While I make time to install and try out every app you submit, I never have time to write about them all so don’t miss out on the Honorable Mentions below as well. The apps I’ve picked to write about are merely a sample of what the community has been building.", "res/fonts/arial.ttf", 30);//此处，字体文件不加载就中断（还不能默认为空串）
    strContents->setDimensions(200, 0);
    strContents->setPosition(Vec2(100,-120));
    
    //绘制裁剪区域
    
    DrawNode* shape = DrawNode::create();
    Point point[4] = {Point(0,0),Point(200,0),Point(200,200),Point(0,200)};
    shape->drawPolygon(point, 4, Color4F(355, 255, 255, 255), 2, Color4F(255, 255, 255, 255));
    
    Sprite* shape2 = Sprite::create("res/tutu.png");
    //SpriteFrame* shapeFrame = SpriteFrame::create("res/toast_bg.png", Rect(0,0,200,200));
    //ui::Scale9Sprite* shape1 =ui::Scale9Sprite::createWithSpriteFrame(shapeFrame);
    Node* shape1 = Node::create();
    shape1->addChild(shape2,1);
    shape1->addChild(strContents,2);
    ClippingNode* cliper = ClippingNode::create();
    cliper->setStencil(shape);
    cliper->setAnchorPoint(Vec2(.5,.5));
    cliper->setPosition(Vec2(100,20));
    addChild(cliper);
    //把要滚动的文字加入到裁剪区域
    //cliper->addChild(strContents);
    cliper->addChild(shape1);
    
    //文字滚动，超出范围后从新开始
    schedule(schedule_selector(RollLabel::verticalScrolling));
    //scheduleOnce(schedule_selector(HelloWorld::rollText),1.0f);
}

void RollLabel::verticalScrolling(float t)
{  
    if(strContents->getPositionY()>300)
    {
        flag = 1;
    }
    else strContents->setPositionY(strContents->getPositionY()+1);
    
    if (flag == 1)
    {
        unschedule(schedule_selector(RollLabel::verticalScrolling));
        strContents->setVisible(false);
        //setButton();
    }
}

void RollLabel::horizontalScrolling(float t)
{
    if(strContents->getPositionX()<-100)
    {
        flag = 1;
    }
    else strContents->setPositionY(strContents->getPositionX()-1);
    
    if (flag == 1)
    {
        unschedule(schedule_selector(RollLabel::horizontalScrolling));
        strContents->setVisible(false);
        //setButton();
    }
}

void RollLabel::onEnter()
{
    Layer::onEnter();
}

void RollLabel::onExit()
{
    Layer::onExit();
}