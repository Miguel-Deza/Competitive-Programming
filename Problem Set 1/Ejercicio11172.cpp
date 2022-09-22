#include<stdio.h>
 
int main()
{
    int t, a, b,i;
    while(scanf("%d",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%d%d",&a,&b);
            if(a<b)
                printf("<\n");
            else if(a>b)
                printf(">\n");
            else
                printf("=\n");
        }
    }
    return 0;
}