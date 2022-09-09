#include<stdio.h>
int main()
{
    int i, j, m, n;
    printf("Enter number of row and column: ");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
            {
                if(arr[i][j] != 0)
                {
                    printf("Row: %d, Column: %d, Value: %d\n", i, j, arr[i][j]);
                }
            }
    }

    return 0;
}

