//QUICK SORT

#include<stdio.h>

void swap(int* val1,int* val2){
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int partition(int arr[],int first,int last){
    int pivot = first;
    int i = first,j = last;
    while(i<j){
        while (arr[i] <= arr[pivot] && i <= last){
                i++;
        }
        while (arr[j] > arr[pivot] && j >= first){
                j--;
        }

        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[pivot],&arr[j]);
    return j;
}

void QuickSort(int arr[],int first, int last){
    if(first < last){
        int p = partition(arr,first,last);
        QuickSort(arr,first,p-1);
        QuickSort(arr,p+1,last);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
