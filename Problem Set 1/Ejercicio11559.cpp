#include<stdio.h>
 
int main()
{
    long int n, b, h, w, p[20], a[20], cost, i,j;
    while(scanf("%ld%ld%ld%ld",&n, &b,&h, &w)==4)
    {
        cost=b+5;
        for(i=1;i<=h;i++)
        {
            scanf("%ld",&p[i]);
            for(j=1;j<=w;j++)
            {
                scanf("%ld",&a[j]);
                if(a[j]>=n && (p[i]*n)<cost)
                    cost=p[i]*n;
            }
        }
        if(cost<=b)
            printf("%ld\n",cost);
        else
            printf("stay home\n");
    }
    return 0;
}