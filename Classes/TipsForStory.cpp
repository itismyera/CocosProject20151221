//
//  TipsForStory.cpp
//  Test
//
//  Created by LRH on 15-12-14.
//
//

#include "TipsForStory.h"
#include "FontChina.h"

/*
TipsForStory::TipsForStory(Layer* layer,Point basepoint,__String* imgurl,int zOrder,Vector<string*> npclist, Vector<string* >talkstory_name,Vector<string*> talkstory_npcflag,Vector<string* >talkstory_about,Vector<string* >talkstory_todo,Vector<string* >talkstory_progress)
{
    overtodoflag=false;
    this_npclist=npclist;    
    this_talkstory_name=talkstory_name;
    this_talkstory_npcflag=talkstory_npcflag;
    this_talkstory_about=talkstory_about;
    this_talkstory_todo=talkstory_todo;
    this_talkstory_progress=talkstory_progress;
    float center_x,center_y;
    
    Point origin = Director::getInstance()->getVisibleOrigin();
    Size size = Director::getInstance()->getWinSize();
    center_x = size.width/2;
    center_y = size.height/2;
    
    
    act_move_storytip = NULL;
    story_tip = TipsForStory::create(imgurl->getCString());
    story_tip ->setPosition(basepoint);
    
    if(story_tip==NULL)
    {
        CCLOG("图层路径有误，请检查路径");
        return;
    }
    
    int maxlist = talkstory_about.size();
    nowflag = 0 ;
    
    if(maxlist>0)
    {
        addStroys(nowflag,zOrder);
    }
    
    layer->addChild(story_tip,zOrder);
}
 */

/*
 void TipsForStory::addStroys(int nowid,int zOrder)
 {
 __String* playnpcflag = (__String*) this_talkstory_npcflag.at(nowflag);
 
 Sprite * thisnpc = (Sprite *)this_npclist.at(playnpcflag->intValue());
 
 Label* thisnpcname_label = (Label*)thisnpc->getChildByTag(111);
 
 __String* thisnpcname_str = __String::create(thisnpcname_label->getString());
 thisnpc->setPosition(Point(story_tip->getContentSize().width/2-150,story_tip->getContentSize().height/2-9));
 thisnpc->getChildByTag(111)->setVisible(false);
 thisnpc->getChildByTag(112)->setVisible(false);
 story_tip->addChild(thisnpc,zOrder+1,001);
 
 __String* thisnpcname =  (__String*)this_talkstory_name.at(nowflag);
 //NPC名称
 //CCLabelTTF* name_label =  CCLabelTTF::create(FontChina::G2U(thisnpcname->getCString()), "微软雅黑",12);
 Label* name_label = Label::createWithTTF("abcd", "res/fonts/arial.ttf", 30);
 name_label->setColor(Color3B::YELLOW);
 //name_label->setDirty(true);
 name_label->setHorizontalAlignment(TextHAlignment::LEFT);
 name_label->setDimensions(120,50);
 name_label->setPosition(Point(90,95));
 
 //CCLabelTTF* name_label2 =  CCLabelTTF::create(FontChina::G2U(thisnpcname->getCString()), "微软雅黑",12);
 Label* name_label2 = Label::createWithTTF("edfg", "res/fonts/arial.ttf", 30);
 name_label2->setColor(Color3B::BLACK);
 //name_label2->setDirty(true);
 name_label2->setHorizontalAlignment(TextHAlignment::LEFT);
 name_label2->setDimensions(120,50);
 name_label2->setPosition(Point(90+1,95-1));
 story_tip->addChild(name_label,zOrder+4,128);
 story_tip->addChild(name_label2,zOrder+3,129);
 
 //说话内容
 __String* nowabout = (__String*)(this_talkstory_about.at(nowflag));
 //CCLabelTTF* newlabels =  CCLabelTTF::create(FontChina::G2U(nowabout->getCString()), "微软雅黑",12);
 Label* newlabels = Label::createWithTTF("wahahah", "res/fonts/arial.ttf", 30);
 newlabels->setColor(Color3B::WHITE);
 //newlabels->setDirty(true);
 newlabels->setHorizontalAlignment(TextHAlignment::LEFT);
 newlabels->setDimensions(290,200);
 newlabels->setPosition(Point(220,-7));
 
 Label* newlabels2 =Label::createWithTTF("about", "res/fonts/arial.ttf", 30);
 //CCLabelTTF* newlabels2 =  CCLabelTTF::create(FontChina::G2U(nowabout->getCString()), "微软雅黑",12);
 newlabels2->setColor(Color3B::BLACK);
 //newlabels2->setDirty(true);
 newlabels2->setHorizontalAlignment(TextHAlignment::LEFT);
 newlabels2->setDimensions(290,200);
 newlabels2->setPosition(Point(220-1,-7-1));
 story_tip->addChild(newlabels,zOrder+2,100+1);
 story_tip->addChild(newlabels2,zOrder+1,200+1);
 
 ///MenuItemImage在3.0中的创建以及事件绑定
 //2.0版本 MenuItemImage::create("1.png", "2.png", this, menu_selector(TipsForStory::totobutton));
 MenuItemImage *pCloseItem1 = MenuItemImage::create("1.png", "2.png", CC_CALLBACK_1(TipsForStory::totobutton, this));
 //std::bind
 MenuItemImage *pCloseItem2 = MenuItemImage::create("1.png", "2.png", std::bind(&TipsForStory::totobutton, this, std::placeholders::_1));
 MenuItemImage *pCloseItem3 = MenuItemImage::create("butbd.png","butbd.png");
 CallFuncN::create(std::bind(&TipsForStory::totobutton,this,pCloseItem3));
 
 Menu* pMenu = Menu::create(pCloseItem1, NULL);
 pMenu->setPosition(315,32);
 story_tip->addChild(pMenu,zOrder+5,300);
 
 __String* thisnpctodo =  (__String*)this_talkstory_todo.at(nowflag);
 //点击事件
 Label* todo_label = Label::createWithTTF("todo", "res/fonts/arial.ttf", 30);
 //CCLabelTTF* todo_label =  CCLabelTTF::create(FontChina::G2U(thisnpctodo->getCString()), "微软雅黑",10);
 todo_label->setColor(Color3B::YELLOW);
 //todo_label->setDirty(true);
 todo_label->setHorizontalAlignment(TextHAlignment::LEFT);
 todo_label->setDimensions(120,50);
 todo_label->setPosition(Point(365,15));
 
 //CCLabelTTF* todo_label2 =  CCLabelTTF::create(FontChina::G2U(thisnpctodo->getCString()), "微软雅黑",10);
 Label* todo_label2 = Label::createWithTTF("todo2", "res/fonts/arial.ttf", 30);
 todo_label2->setColor(Color3B::BLACK);
 todo_label2->updateContent();
 //todo_label2->setDirty(true);
 todo_label2->setHorizontalAlignment(TextHAlignment::LEFT);
 todo_label2->setDimensions(120,50);
 todo_label2->setPosition(Point(365+1,15-1));
 story_tip->addChild(todo_label,zOrder+6,138);
 story_tip->addChild(todo_label2,zOrder+5,139);
 
 }

 void TipsForStory::totobutton(Ref* pSender)
 {
 __String* thistodo = (__String*)this_talkstory_todo.at(nowflag);
 
 if(thistodo->isEqual(__String::create("continue")))
 {
 nowflag++ ;
 if(nowflag>0)
 {
 story_tip->removeAllChildren();
 addStroys(nowflag,114);
 }
 }
 else if(thistodo->isEqual(CCString::create("finish")))
 {
 story_tip->removeAllChildren();
 story_tip->setVisible(false);
 story_tip->retain();
 __String* thistprogress = (__String*)this_talkstory_progress.at(nowflag);
 //storyplayflag=thistprogress->intValue();
 }
 }

 */

TipsForStory::TipsForStory(Layer* layer,Point basepoint,__String* imgurl,int zOrder)
{
    float center_x,center_y;
    
    Point origin = Director::getInstance()->getVisibleOrigin();
    Size size = Director::getInstance()->getWinSize();
    center_x = size.width/2;
    center_y = size.height/2;
    
    story_tip = TipsForStory::create(imgurl->getCString());
    story_tip ->setPosition(basepoint);
    
    if(story_tip==NULL)
    {
        CCLOG("图层路径有误，请检查路径");
        return;
    }
    nowflag = 0 ;
    addStroys(nowflag,zOrder);
    layer->addChild(story_tip,zOrder);
}

void TipsForStory::addStroys(int nowid,int zOrder)
{
    
    //NPC名称
    Label* name_label = Label::createWithTTF("abcd", "res/fonts/arial.ttf", 30);
    name_label->setColor(Color3B::YELLOW);
    //name_label->setDirty(true);
    name_label->setHorizontalAlignment(TextHAlignment::LEFT);
    name_label->setDimensions(120,50);
    name_label->setPosition(Point(90,95));
    
   
    Label* name_label2 = Label::createWithTTF("edfg", "res/fonts/arial.ttf", 30);
    name_label2->setColor(Color3B::BLACK);
    //name_label2->setDirty(true);
    name_label2->setHorizontalAlignment(TextHAlignment::LEFT);
    name_label2->setDimensions(120,50);
    name_label2->setPosition(Point(90+1,95-1));
    story_tip->addChild(name_label,zOrder+4,128);
    story_tip->addChild(name_label2,zOrder+3,129);
    
    //说话内容
    Label* newlabels = Label::createWithTTF("wahahah", "res/fonts/arial.ttf", 30);
    newlabels->setColor(Color3B::WHITE);
    //newlabels->setDirty(true);
    newlabels->setHorizontalAlignment(TextHAlignment::LEFT);
    newlabels->setDimensions(290,200);
    newlabels->setPosition(Point(220,-7));
    
    Label* newlabels2 =Label::createWithTTF("about", "res/fonts/arial.ttf", 30);
    newlabels2->setColor(Color3B::BLACK);
    //newlabels2->setDirty(true);
    newlabels2->setHorizontalAlignment(TextHAlignment::LEFT);
    newlabels2->setDimensions(290,200);
    newlabels2->setPosition(Point(220-1,-7-1));
    story_tip->addChild(newlabels,zOrder+2,100+1);
    story_tip->addChild(newlabels2,zOrder+1,200+1);
    
    ///MenuItemImage在3.0中的创建以及事件绑定
    //2.0版本 MenuItemImage::create("1.png", "2.png", this, menu_selector(TipsForStory::totobutton));
    MenuItemImage *pCloseItem1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(TipsForStory::totobutton, this));
    //std::bind
    MenuItemImage *pCloseItem2 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", std::bind(&TipsForStory::totobutton, this, std::placeholders::_1));
    MenuItemImage *pCloseItem3 = MenuItemImage::create("CloseNormal.png","CloseSelected.png");
    CallFuncN::create(std::bind(&TipsForStory::totobutton,this,pCloseItem3));
    //1和2能用，3无效
    Menu* pMenu = Menu::create(pCloseItem2, NULL);
    pMenu->setPosition(362,32);
    story_tip->addChild(pMenu,zOrder+5,300);
    
   
    //点击事件
    string mengpo = "孟婆";
    Label* todo_label = Label::createWithTTF(FontChina::G2U(L"孟婆"), "res/fonts/arial.ttf", 30);
    todo_label->setColor(Color3B::YELLOW);
    //todo_label->setDirty(true);
    todo_label->setHorizontalAlignment(TextHAlignment::LEFT);
    todo_label->setDimensions(120,50);
    todo_label->setPosition(Point(362,15));
    
   
    Label* todo_label2 = Label::createWithTTF("todo2", "res/fonts/arial.ttf", 30);
    todo_label2->setColor(Color3B::BLACK);
    todo_label2->updateContent();
    //todo_label2->setDirty(true);
    todo_label2->setHorizontalAlignment(TextHAlignment::LEFT);
    todo_label2->setDimensions(120,50);
    todo_label2->setPosition(Point(35+1,15-1));
    story_tip->addChild(todo_label,zOrder+6,138);
    story_tip->addChild(todo_label2,zOrder+5,139);
    
}

void TipsForStory::totobutton(Ref* pSender)
{
    story_tip->removeAllChildren();
    story_tip->setVisible(false);
    story_tip->retain();
}


TipsForStory::~TipsForStory(void)
{
    
}

