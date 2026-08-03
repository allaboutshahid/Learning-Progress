#include<stdio.h>
int main()
{
    int a[50],size,i;
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("Enter the elements :\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The elements are :\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}