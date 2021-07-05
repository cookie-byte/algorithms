#include<stdio.h>

void spiralPrint(int m, int n, int a[][n])
{
    int i,  k = 0, l = 0;
    m--, n--;

    while(k <= m && l <= n)
    {
        for(i = l; i <= n; ++i)
        {
            printf("%d ", a[k][i]);
        }

        k++;
        for(i = k; i <= m; ++i)
        {
            printf("%d ", a[i][n]);
        }

        n--;
        if(m >= k)
        {
            for(i = n; i >= l; --i)
            {
                printf("%d ", a[m][i]);
            }
            m--;
        }

        // Print the column bottom to top
        for(i = m; i >= k; --i)
        {
            printf("%d ", a[i][l]);
        }

        l++;
    }

    printf("\n");
}

int main(void)
{
    int m,n,i,j;
    printf("enter size ");
    scanf("%d%d",&m,&n);

    int arr[m][n] ;
    printf("enter elements ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",arr[i][j] );
        }
    printf("\n");
    }
    printf("\n");
    spiralPrint(m, n, arr);

    return 0;
}
