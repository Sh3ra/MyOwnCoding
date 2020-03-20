#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[56];
    int n;
    scanf("%d ",&n);
    gets(s);
    int i=0;
    int k=0;
    while(s[i]!='\0')
    {
        i=i+k;
        printf("%c",s[i]);
        i++;
        k++;

    }
    return 0;
}
