#include<iostream>
#include<vector>

using namespace std;

vector<int> Reverse(vector<int> A)
{
    int n = A.size();
    vector<int> A2;
    for (int i=n-1;i>=0;i--)
        A2.push_back(A[i]);
    return A2;
}

int main()
{
   vector<int> Arr;
   int i;
    cout<<"Enter the elements= ";
    for(i=0;i<Arr.size();i++)
    {
        Arr.push_back(i);
    }
    cout<<"\nYour Array is: ";
    for(i=0;i<Arr.size();i++)
    {
        cout<< Arr[i];
    }
    cout<<"\nYour Reversed array is: ";
    Reverse(Arr);
    return 0;
}

