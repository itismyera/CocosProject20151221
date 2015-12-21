//
//  FontChina.h
//  Test
//
//  Created by LRH on 15-12-15.
//
//

#ifndef __Test__FontChina__
#define __Test__FontChina__

class FontChina
{
public:
    FontChina();
    ~FontChina();
    static void WStrToUTF8(std::string& dest,const std::wstring& src);
    static std::string G2U(const std::wstring& str);
};

#endif /* defined(__Test__FontChina__) */
