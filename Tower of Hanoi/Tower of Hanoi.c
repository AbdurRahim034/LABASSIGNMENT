#include<stdio.h>
void hanoi(int n, char from, char to, char aux)
{
    if (n==1)
    {
        printf("\nMove disk 1 from stack %c to stack %c", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("\nMove disk %d from stack %c to stack %c", n, from, to);
    hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter disk numbers: ");
    scanf("%d",&n);
    hanoi(n, 'a', 'b', 'c');
    printf("\n\n");
    return 0;
}
