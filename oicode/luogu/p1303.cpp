#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct high_per
{
    int length;
    int value[1000];
    high_per()
    {
        memset(value, 0, sizeof(value));
    }
};
void load(high_per &value)
{
    char a[1000];
    gets(a);
    value.length = strlen(a);
    for (int i = 0; i < value.length; ++i)
    {
        value.value[value.length - i - 1] = a[i] - '0';
    }
}
high_per digit(high_per a, high_per b)
{
    high_per c;
    for (int i = 0; i < a.length; ++i)
        for (int j = 0; j < b.length; ++j)
        {
            int res = a.value[i] * b.value[j];
            if (res >= 10)
            {
                c.value[i + j + 1] += res / 10;
                c.value[i + j] += res % 10;
            }
            else
                c.value[i + j] += res;
        }
    for (int k = 0; k < a.length; ++k)
    {
        for (int i = 0; i < b.length; ++i)
        {
            if (c.value[k + i] >= 10)
            {
                c.value[k + i + 1] += c.value[k + i] / 10;
                c.value[k + i] %= 10;
            }
        }
    }
    c.length = a.length + b.length + 1;
    while (c.value[c.length - 1] == 0 && c.length > 1)
        --c.length;
    return c;
}
int main()
{
    high_per a, b, c;
    load(a);
    load(b);
    c = digit(a, b);
    for (int i = c.length - 1; i >= 0; --i)
    {
        printf("%d", c.value[i]);
    }
}