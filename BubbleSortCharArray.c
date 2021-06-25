//SORT CHAR ARRAY USING BUBBLE SORT

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    char arr[n];
    for(int i=0;i<=n;i++){
        scanf("%c",&arr[i]);
    }
     for (int i = 0; i <= n-1; i++)
     for (int j = 0; j <= n-i-1; j++){
        if (arr[j] > arr[j+1]){
            char temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
     }
     for(int i=0;i<=n;i++){
        printf("%c ",arr[i]);
    }
    return 0;
}
