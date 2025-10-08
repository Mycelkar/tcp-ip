//
// Created by 33441 on 2025/10/8.
//
#include "sys_plat.h"
#include "dbg.h"
#include <stdarg.h>
void dbg_print(int m_level, int s_level, const char * file, const char * func, int line, const char * fmt, ...){
    static const char* title[] = {
            [DBG_LEVEL_NONE] = "NONE ",
            [DBG_LEVEL_ERROR] = DBG_STYLE_ERROR"ERROR ",
            [DBG_LEVEL_WARNING] = DBG_STYLE_WARNING"WARNING ",
            [DBG_LEVEL_INFO] = "INFO "
    };
    if(m_level < s_level){
        return;
    }
    const char * end = file + plat_strlen(file);
    while(end >= file){
        if((*end == '\\') || (*end == '/')){
            break;
        }
        end--;
    }
    end++;
    plat_printf("%s(%s - %s - %d) : " , title[s_level], end, func, line);
    char str_buf[128];
    va_list args;
    va_start(args,fmt);
    plat_vsprintf(str_buf,fmt,args);
    plat_printf("%s\n"DBG_STYLE_RESET,str_buf);\
    va_end(args);
}