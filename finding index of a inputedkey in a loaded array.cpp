#include <iostream>
using namespace std;
int find(int arr[], int len, int key)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == key) 
        return i;
    }
    return -1;
}
int main(){
    int size;
    cin>>size;
    int arr[size]; 
    for (int i = 0; i < size; i++) { 
        cout << "Enter a number: "; 
        cin >> arr[i]; 
    } 
    cout << "The array elements are: "; 
    for (int i = 0; i < size; i++) { 
        cout << arr[i] << " "; 
    } 
    cout<<endl;
    cout<<"enter the key to get its index:";
    int y;
    cin>>y;
    cout<<"the key index is"<<endl;
    int x = find(arr,size,y);
    cout << x << endl;    
}
