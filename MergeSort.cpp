#include<iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right - mid;
    int la[n1],ra[n2];
    
    for(int i=0;i<n1;i++){
        la[i] = arr[left+i];
    }
    for(int j=0;j<n2;j++){
        ra[j] = arr[mid+1+j];
    }

    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(la[i]<ra[j])
            arr[k++] = la[i++];
        else
            arr[k++] = ra[j++];
    }
    while(i<n1)
        arr[k++] = la[i++];
    while(j<n2)
        arr[k++] = ra[j++];
}
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}