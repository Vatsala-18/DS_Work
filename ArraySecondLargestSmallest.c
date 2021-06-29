//SECOND SMALLEST AND SECOND LARGEST

#include<stdio.h>
void main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int large,secLarge,small,secSmall;
    large = secLarge = arr[0];
    small = secSmall = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<small){
            secSmall = small;
            small = arr[i];
        }
        if(arr[i]>large){
            secLarge = large;
            large = arr[i];
        }
        else if (arr[i] < secSmall && arr[i] != small)
            secSmall = arr[i];
        else if (arr[i] > secLarge && arr[i] != large)
            secLarge = arr[i];
    }
    printf("Largest : %d\nSecond Largest : %d\nSmallest : %d\nSecond Smallest : %d",large,secLarge,small,secSmall);

}
