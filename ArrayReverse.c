//REVERSE OF ARRAY

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int first=0,last=n-1,temp;
    while(first<=last){
        temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;

        first++;
        last--;
    }
    printf("\nReversed Array is : ");
    for(int i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
    return 0;
}
