//Program to delete an element from the array
#include<iostream>
using namespace std;

void del(int a[], int s, int p){
    if(p<0)
        cout<<"wrong position";
    else{
        for(int i=p-1;i<=s-1;i++){
            a[i] = a[i+1];
        }
        s = s-1;
        cout<<"\nYour new array: ";
        for(int i=0;i<s;i++)
            cout<<a[i]<<" ";
    }
}

int main(){
    int arr[100], size, pos;
    cout<<"\nEnter the size of array: ";
    cin>>size;
    cout<<"\nEnter the elements: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<"\nYour array is: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\nEnter the position from which you want to delete : ";
    cin>>pos;
    del(arr, size,pos);
    return 0;
}