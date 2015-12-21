//
//  GameData.cpp
//  Test
//
//  Created by LRH on 15-12-4.
//
//

#include "GameData.h"

static GameData* game = NULL;

GameData::GameData()
{
    
}

GameData::~GameData()
{
    
}

GameData* GameData::getInstance()
{
    if(!game)
    {
        game = new GameData();
    }
    return game;
}

string GameData::readLoaclData(string pFileName)
{
    //第一获取文件的路径
    string result = "";
    string path = FileUtils::getInstance()->fullPathForFilename(pFileName.c_str());
    
    CCLOG("path = %s",path.c_str());
    FILE* file = fopen(path.c_str(),"r");
    if(file)
    {
        char* buf ;//要获取的字符串
        int len;  //获取的长度
        //获取长度
        fseek(file, 0, SEEK_END);  //移到尾部
        len = ftell(file);        //提取长度
        rewind(file);             //回归原位
        
        //分配buf空间
        buf = (char*)malloc(sizeof(char)* len +1);
        if(!buf)
        {
            return NULL;
        }
        //读取文件
        result = buf;
        fclose(file);
        free(buf);
        return result;
    }
    else{
        result = "nofile";
    }
    return result;
}

bool GameData::saveDefault(char* pContent,string pFileName)
{
    string path = FileUtils::getInstance()->getWritablePath() + pFileName;
    
    //创建一个文件指针
    //路径和模式
    FILE* file = fopen(path.c_str(),"w");
    if(file)
    {
        fputs(pContent, file);
        fclose(file);
    }
    else
        CCLOG("save file error.");
    return false;
}

//字符串分割函数
std::vector<std::string> GameData::splist(string str, string pattern)
{
    std::string::size_type pos;
    std::vector<std::string>result;
    str += pattern; //扩展字符串以方便操作
    int size = str.size();
    for(int i = 0;i < size; i++)
    {
        pos = str.find(pattern, i);
        if(pos < size)
        {
            std::string s = str.substr(i,pos - i);
            result.push_back(s);
            i = pos+pattern.size()-1;
        }
    }
    return result;
}
void GameData::readJson()
{
    
}




