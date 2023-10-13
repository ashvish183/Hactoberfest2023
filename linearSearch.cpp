#include<iostream>
using namespace std;

int linearSerach(int n,int arr[],int key){
    for(int i=0;i<n;i++){
        if( arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter key element : ";
    cin>>key;
    cout<<"element is at position: "<<linearSerach(n,arr,key);
    return 0;

}
