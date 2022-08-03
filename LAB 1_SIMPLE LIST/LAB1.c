#include<stdio.h>
main()
{
    int arr[50];
    int n;
    int i;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    printf("\n\nEnter %d elements: ", n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n\nThe data in the list is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    int j;
    printf("\nEnter the position of data to delete: ");
    scanf("%d",&j);
    while(j<n)
    {
        arr[j-1]=arr[j];
        j++;
    }
    n-=1;
    printf("\n\nThe data left in the list after deletion is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n\n");
    return 0;
}
