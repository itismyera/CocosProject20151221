//
//  TipsForStory.h
//  Test
//
//  Created by LRH on 15-12-14.
//
//

#ifndef __Test__TipsForStory__
#define __Test__TipsForStory__

#include <stdio.h>
#include <iostream>
#include "cocos2d.h"

using namespace std;
USING_NS_CC;

class TipsForStory : public cocos2d::Sprite
{
public:
    int nowflag;
    bool overtodoflag;
    Sprite* story_tip;
    ActionInterval* act_move_storytip;
    
    //TipsForStory(Layer* layer,Point basepoint,__String* imgurl,int zOrder,Vector<string*> npclist, Vector<string* >talkstory_name,Vector<string*> talkstory_npcflag,Vector<string* >talkstory_about,Vector<string* >talkstory_todo,Vector<string* >talkstory_progress);
    TipsForStory(Layer* layer,Point basePoint,__String* imgurl,int zOrder);
    ~TipsForStory(void);
    
    void addStroys(int nowid,int zOrder);
    void totobutton(Ref* pSender);
private:
    /*
    Vector<string* >this_npclist;
    Vector<string* >this_talkstory_name;
    Vector<string* >this_talkstory_npcflag;
    Vector<string* >this_talkstory_about;
    Vector<string* >this_talkstory_todo;
    Vector<string* >this_talkstory_progress;
    */
};

#endif /* defined(__Test__TipsForStory__) */

