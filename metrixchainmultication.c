#include<stdio.h>
#include<stdlib.h>
# define size 100

int MatrixChainOrder(int p[], int n)
{
 
   
    int m[n][n];
 
    int i, j, k, L, q;
 
    
    for (i=1; i<n; i++)
        m[i][i] = 0;
 
 
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = 0;
            for (k=i; k<=j-1; k++)
            {
               
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n-1];
}
 
int main()
{
        int arr[size],n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        }
    printf("%d ",MatrixChainOrder(arr, size));
 
   
    return 0;
}
