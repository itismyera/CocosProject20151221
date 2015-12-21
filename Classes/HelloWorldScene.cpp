#include "HelloWorldScene.h"
#include "RollLabel.h"
#include "SkillEffect.h"
#include "TipsForStory.h"

using namespace cocostudio::timeline;
static const char* TEXT_ATLAS = "%&'()*+,-./0123456789:;";//~符号用-来代替，否则不显示

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    //RollLabel* roll = RollLabel::create();
    //layer->addChild(roll);
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //画三角形
   // this->setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
    
    
    ui::Button* btn = ui::Button::create("btn-play-down.png");
    btn->setScale(0.5);
    btn->setPosition(Vec2(800,450));
    btn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::btnPress,this));
    btn->setTag(2015);
    this->addChild(btn);

     
   
    return true;
}

/*
 **
 3.0新的回调方法
void bind()
{
    //方法1
    CallFunc::create(CC_CALLBACK_0(HelloWorld::callback0, this));
    CallFuncN::create(CC_CALLBACK_1(HelloWorld::callback1, this));
    CallFuncN::create(CC_CALLBACK_1(Helloworld::callback2,this,0.5));
    //方法2
    CallFuncN::create(std::bind(&HelloWorld::callback0,this));
    CallFuncN::create(std::bind(&HelloWorld::callback1,this,sprite));
    CallFuncN::create(std::bind(&HelloWorld::callback2,this,sprite,0.5));
    //回调函数
    void HelloWorld::callback0(){}
    void HelloWorld::callback1(Node* node){}
    void HelloWorld::callback2(Node* node,float a){}
}

 **
 */

void HelloWorld::btnPress(cocos2d::Ref *sender,cocos2d::ui::Widget::TouchEventType type)
{
    //ui::Button* button = dynamic_cast<ui::Button*>(sender);
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            //showAnimation();
            //showScollText();
            //showMotionStreak();
            //showNPCDialog();
            //drawElement();
            capture(this);
            break;
        default:
            break;
    }
}

void HelloWorld::showAnimation()
{
    SkillEffect* effect = SkillEffect::create();
    /**
    effect->init(1);
    effect->explode(this, Vec2(100,100), Vec2(500,500));
     **/
    effect->init(3);
    effect->explode(this, Vec2(100,100), Vec2(500,100));
    
    addSprite = Sprite::create("res/hurt.png");
    this->addChild(addSprite);
    CallFuncN* removeFunc = CallFuncN::create(std::bind(&HelloWorld::addFont,this,addSprite));
    float time = 5.0;
    Sequence* seq = Sequence::create(DelayTime::create(time),removeFunc,NULL);
    runAction(seq);
}

void HelloWorld::showScollText()
{
     //滚动字幕
     auto rootNode = CSLoader::createNode("MainScene.csb");
     RollLabel* roll = RollLabel::create();
     rootNode->addChild(roll);
     addChild(rootNode);
}


void HelloWorld::addFont(Ref* sender)
{
    int hp = -500;
    Vec2 pt = Vec2(300,300);
    //三种方式创建charMap(2.0是LabelAtlas，显示数字用的)
    //使用png创建
    Label* label1 = Label::createWithCharMap("res/fonts/number_style_0.png", 20, 31, '%');
    label1->setString(TEXT_ATLAS);
    
    //使用Texture2D创建
    //TextureCache::getInstance弃用了，改为Director::getInstance()->getTextureCache()
    Texture2D* texture = Director::getInstance()->getTextureCache()->addImage("res/fonts/number_style_0.png");
    Label* label2 = Label::createWithCharMap(texture, 20 , 31, '%');
    label2->setString(TEXT_ATLAS);
    
    //使用plist创建，先配置plist
    Label* label3 = Label::createWithCharMap("res/fonts/digit.plist");
    label3->setString (TEXT_ATLAS);
    
    ///针对不同label测试
    this->addChild(label3,2,2);
    label3->setPosition(pt);
    
    char str[32]={0};
    sprintf(str,"%d",hp);
    label3->setString(str);
    
    ActionInterval* fade = FadeOut::create(1.0f);
    ActionInterval* fade2 = FadeOut::create(1.0f);
    Sequence* seq = Sequence::create(fade, NULL);
    label3->runAction(seq);
    
    addSprite->setPosition(Vec2(pt.x-20,pt.y));
    addSprite->setAnchorPoint(Vec2(0,0));
    Sequence* seq2 = Sequence::create(fade2,NULL);
    addSprite->runAction(seq2);
    
    //addSprite->release();
    //label1->release();
}

void HelloWorld::showMotionStreak()//拖曳效果未重现
{
    SkillEffect* effect = SkillEffect::create();
    effect->MotionStreakEffect(this);
}


//画三角形
/*
void HelloWorld::visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t parentFlags)
{
    Layer::visit(renderer, transform, parentFlags);
    
    _command.init(_globalZOrder);
    _command.func = CC_CALLBACK_0(HelloWorld::onDraw, this);
    Director::getInstance()->getRenderer()->addCommand(&_command);
}

void HelloWorld::onDraw()
{
    auto glProgram = getGLProgram();
    glProgram->use();
    
    glProgram->setUniformsForBuiltins();
    auto size = Director::getInstance()->getWinSize();
    
    float vertercies [] = {0,0,
                           size.width,0,
                           size.width/2, size.height};
    float color [] = {0,1,0,1,
                      1,0,0,1,
                      0,0,1,1};
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertercies);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, color);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    CHECK_GL_ERROR_DEBUG();
}
*/

void HelloWorld::showNPCDialog()
{
    TipsForStory* storyTips_part1;
    //TipsForStory* storyTips_part2;
    
    //故事对话框
    storyTips_part1 = new TipsForStory(this,Point(300,300),CCString::create("res/tutu.png"),2);
    
}

void HelloWorld::drawElement()
{
    //屏幕尺寸
    //Size mysize = Director::getInstance()->getVisibleSize();
    //点
    
    //OpenGl的绘图原语 DrawPrimitives ,2.0使用，在3.0一些参数设置的方法变化了，而且3.3后被弃用
    /*
    //一个点
    ccPointSize(10);
    ccDrawColor4B(255, 25, 200, 250);
    ccDrawPoint(mysize/2);
    
    //多个点
    ccPointSize(30);
    ccDrawColor4B(255, 0, 0, 100);
    CCPoint Pointarray[] = {ccp(200, 150), ccp(200, 200), ccp(280, 150), ccp(280, 200)};
    ccDrawPoints(Pointarray, 4);
    
    //直线
    glLineWidth(3);
    ccDrawColor4B(255, 255, 255, 130);
    ccDrawLine(ccp(10, 300), ccp(200, 300) );
    
    //圆
    glLineWidth(3);
    ccDrawColor4B(255, 255, 100, 190);
    ccDrawCircle(ccp(50, 250), 40, 3.14/2, 360, true, 1, 0.5);
    
    //矩形
    //空心
    glLineWidth(5);
    ccDrawColor4B(24, 25, 200, 140);
    ccDrawRect(ccp(10, 150), ccp(110, 200));
    
    //实心
    ccDrawSolidRect(ccp(10, 90), ccp(100, 140), ccc4f(255, 255, 255, 0.5f));
    
    //多边形
    //空心
    glLineWidth(10);
    ccDrawColor4B(240, 225, 100, 130);
    CCPoint Polyarray[] = {ccp(20, 20), ccp(50, 0), ccp(250, 100), ccp(300, 100), ccp(250, 50)};
    ccDrawPoly(Polyarray, 5, 1);
    
    //实心
    CCPoint Polyarray2[] = {ccp(250,30), ccp(280,300), ccp(450,0), ccp(410,130), ccp(420,50)};
    ccDrawSolidPoly(Polyarray2, 5, ccc4f(142, 245, 70, 0.3f));
    
    //贝赛尔曲线
    //平面
    glLineWidth(5);
    ccDrawColor4B(100, 100, 100, 255);
    ccDrawQuadBezier(ccp(0,320), ccp(160,100), ccp(480,320), 100);
    
    //立体
    glLineWidth(5);
    ccDrawColor4B(200, 200, 200, 255);
    ccDrawCubicBezier(ccp(0,0), ccp(160,300), ccp(320,20), ccp(480,320), 100);
     */
    
    DrawNode* drawNode = DrawNode::create();
    this->addChild(drawNode);
    /**
    //圆点      ('位置' , '圆点半径' , '填充颜色')
    void drawDot(const Vec2 &pos, float radius, const Color4F &color);
    //线段          ('起点' , '终点' , '半线宽' , '填充颜色')
    void drawSegment(const Vec2 &from, const Vec2 &to, float radius, const Color4F &color);
    //三角形         ('顶点1' , '顶点2' , '顶点3' , '填充颜色')
    void drawTriangle(const Vec2 &p1, const Vec2 &p2, const Vec2 &p3, const Color4F &color);
    //多边形        ('顶点数组' , '顶点个数' , '填充颜色' , '轮廓粗细' , '轮廓颜色')
    void drawPolygon(Vec2 *verts, int count, const Color4F &fillColor, float borderWidth, const Color4F &borderColor);
    //二次贝塞尔图形 ('起点' , '控制点' , '终点' , '分段数' , '填充颜色')
    void drawQuadraticBezier(const Vec2& from, const Vec2& control, const Vec2& to, unsigned int segments, const Color4F &color);
    //三次贝塞尔图形    ('起点' , '控制点1' , '控制点2' , '终点' , '分段数' , '填充颜色')
    void drawCubicBezier(const Vec2& from, const Vec2& control1, const Vec2& control2, const Vec2& to, unsigned int segments, const Color4F &color);
     
    //清除所画图形
     drawNode->clear();
     **/
    
    //圆点
    drawNode->drawDot(Vec2(50,50), 10, Color4F::RED);
    
    //线段
    drawNode->drawSegment(Vec2(20,100), Vec2(100,100), 5, Color4F(0,1,0,1));
    drawNode->drawSegment(Vec2(20, 150), Vec2(100, 150), 10, Color4F(0, 0, 1, 1));
    
    //三角形
    drawNode->drawTriangle(Vec2(20, 250), Vec2(100, 300), Vec2(50, 200), Color4F(1, 1, 0, 1));
    
    //实心多边形
    Vec2 point1[4];
    point1[0] = Vec2(150, 50);
    point1[1] = Vec2(150, 150);
    point1[2] = Vec2(250, 150);
    point1[3] = Vec2(250, 50);
    drawNode->drawPolygon(point1, 4, Color4F(1, 0, 0, 1), 1, Color4F(0, 1, 0, 1));
    
    //空心多边形
    Vec2 point2[4];
    point2[0] = Vec2(150, 200);
    point2[1] = Vec2(150, 300);
    point2[2] = Vec2(250, 300);
    point2[3] = Vec2(250, 200);
    drawNode->drawPolygon(point2, 4, Color4F(1, 0, 0, 0), 1, Color4F(0, 1, 0, 1));
    
    //二次贝塞尔
    Vec2 from1 = Vec2(300, 20);
    Vec2 to1 = Vec2(450, 20);
    Vec2 control = Vec2(360, 100);
    drawNode->drawQuadraticBezier(from1, control, to1, 100, Color4F::ORANGE);
    
    //三次贝塞尔
    Vec2 from2 = Vec2(300, 100);
    Vec2 to2 = Vec2(450, 100);
    Vec2 control1 = Vec2(350, 0);
    Vec2 control2 = Vec2(400, 200);
    drawNode->drawCubicBezier(from2, control1, control2, to2, 100, Color4F::YELLOW);
    
    
    //颜色混合测试
    BlendFunc bl = { GL_ONE, GL_ONE };
    drawNode->setBlendFunc(bl);
    
    drawNode->drawSegment(Vec2(300, 250), Vec2(450, 250), 10, Color4F::GREEN);
    drawNode->drawTriangle(Vec2(300, 200), Vec2(400, 300), Vec2(450, 150), Color4F::RED);
}

void HelloWorld::capture(cocos2d::Ref *sender)
{
    utils::captureScreen(CC_CALLBACK_2(HelloWorld::afterCapture, this),"ScreenShot.png");
}

void HelloWorld::afterCapture(bool succeed, const std::string &outputFile)
{
    Size winSize = Director::getInstance()->getWinSize();
    if(succeed)
    {
        CCLOG("%s",outputFile.c_str());
        //显示截图
        Sprite* sp = Sprite::create(outputFile);
        sp->setPosition(winSize/2);
        this->addChild(sp);
        sp->setScale(0.25);
    }
    else
    {
        CCLOG("Capture screen failed");
    }
}


