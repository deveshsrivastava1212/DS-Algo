//show the first -ve integer of every window of size k

#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
    int arr[100], size, k = 3, i=0,j=0;
    vector<int> v;
    list<int> l;
    cout<<"\nEnter the size: ";
    cin>>size;
    cout<<"\nEnter the element: ";
    for(int k=0;k<size;k++){
        cin>>arr[k];
    }
    while(j<size){
        if(arr[j]<0)
            l.push_back(arr[j]);
        if(j-i+1 < k)
            j++;
        else if(j-i+1 ==k)
        {
            if(l.size() == 0)
                v.push_back(0);
            else{
                v.push_back(l.front());
                if(l.front()==arr[i])
                    l.pop_front();
                i++;
                j++;
            }
        }
    }
    cout<< "First -ve integer for every window is: ";
    for(int k =0 ; k<v.size();k++)
        cout<<v[k]<<" ";
    return 0;
}