#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct high_precision
{
    int length, value[200];
};
void load(high_precision &input)
{
    char string[201];
    scanf("%s", string);
    while (string[0] == '0' && strlen(string) > 0)
        strcpy(string, &string[1]);
    int j = 0;
    input.length = strlen(string);
    for (int i = input.length - 1; i >= 0; --i)
    {
        input.value[j] = string[i] - 48;
        j++;
    }
}
high_precision add(high_precision a, high_precision b)
{
    high_precision c;
    int k = a.length > b.length ? a.length : b.length;
    for (int i = 0; i <= k; ++i)
        c.value[i] = 0;
    for (int j = 0; j <= k; ++j)
    {
        if (j < a.length)
            c.value[j] += a.value[j];
        if (j < b.length)
            c.value[j] += b.value[j];
        //c.value[j]=j<=a.length?a.value[j]:0+j<=b.length?b.value[j]:0;
    }
    for (int l = 0; l < k; ++l)
    {
        c.value[l + 1] += c.value[l] / 10;
        c.value[l] %= 10;
    }
    c.length = k;
    if (c.value[k] > 0)
        c.length += 1;
    return c;
}
int main()
{
    high_precision a, b;
    load(a);
    load(b);
    high_precision c = add(a, b);
    for (int i = c.length - 1; i >= 0; --i)
    {
        cout << c.value[i];
    }
    return 0;
}