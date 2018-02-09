#include <sys/mman.h>
#include <iostream>
#include <cstdio>

namespace
{
    inline char read(){
        static long long fsize = 1 << 63;
        cout << fsize << endl;
    }
}

int main()
{
    read();
}
