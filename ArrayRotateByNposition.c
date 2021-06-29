//ROTATE ARRAY FROM Nth POSITION

#include<stdio.h>
void main()
{
    int n,l;
    printf("Enter length and rotate posn : ");
    scanf("%d %d",&l,&n);

    int a[l];
    printf("Enter array elements : ");
    for(int i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }

    int temp,k;
    for(int i=0;i<n;i++)
    {
        temp = a[0];
        for(int j=0;j<l-1;j++)
        {
            k=j+1;

            a[j] = a[k];
        }
        a[l-1] = temp;
    }
    for(int i=0;i<l;i++)
    {
        printf("\t%d",a[i]);
    }
}
