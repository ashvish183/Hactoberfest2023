#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool restArray=isSorted(arr+1,n-1);
    return restArray;
}

int main(){
    int arr[]={1,2,3,5,6,7};
    cout<<isSorted(arr,6)<<endl;
    return 0;
}
