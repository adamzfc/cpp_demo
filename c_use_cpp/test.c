// http://www.wjdiankong.cn/%E5%A6%82%E4%BD%95%E7%94%A8c%E8%AF%AD%E8%A8%80%E8%B0%83%E7%94%A8c%E5%81%9A%E6%88%90%E7%9A%84%E5%8A%A8%E6%80%81%E9%93%BE%E6%8E%A5%E5%BA%93/
#include "stdio.h"
#include "dlfcn.h"

#define SOFILE "sec.so"
int (*f)();
int main()
{
    void *dp;
    dp = dlopen(SOFILE, RTLD_LAZY);
    f = dlsym(dp, "f");
    f();
    return 0;
}
