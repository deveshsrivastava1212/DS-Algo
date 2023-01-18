#include<iostream>
using namespace std;

//Function to take input elements in array
void Input(int n, int A[])
{
    int i;
    cout<<"\n";
    for(i=0;i<n;i++)
      {
          cout<<i+1<<"th : ";
          cin>>A[i];
      }
}

//Function to display the array
void Display(int n, int A[])
{
    cout<<"[ ";
    for(int i =0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<" ]";
}

//Function to sort the array by bubble technique
int Sort(int n, int A[])
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if( A[j] > A[j+1] )
            {
               temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
            }
        }
    }
    return A[j];
}

//Main Function
int main()
{
    int n,Arr[100];
    cout<<"Enter the Size of array: ";
    cin>>n;
    cout<<"\nInput the elements : ";
    Input(n, Arr);
    cout<<"\nYour Array is: ";
    Display(n, Arr);
    cout<<"\nNow the sorted array is: ";
    Sort(n,Arr);
    Display(n,Arr);
    return 0;
}
