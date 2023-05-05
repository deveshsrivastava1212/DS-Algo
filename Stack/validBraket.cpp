#include<iostream>
#include<stack>
using namespace std;

bool validCheck(string s)
{
    stack<int> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        
        else  
            if(!st.empty())
            {
                char c = st.top();
                if(
                    s[i] == ')' && c == '(' ||
                    s[i] == ']' && c == '[' ||
                    s[i] == '}' && c == '{'
                )
                st.pop();
                else
                    return false;
            }
            else   
                return false;
    }

    if(st.empty())
        return true;
    else    
        return false;
}

int main()
{
    string s = "[{([()[)}]";
    cout<<validCheck(s);
}