#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Returns the index of t in s, and -1 if t is not present in s
int kmp(string s,string t)
{
    int n = s.length(),m = t.length();
    int ps[m];
    ps[0] = 0;
    int i=1,j=0;
    while(i<m)
    {
        if(t[j]==t[i])
        {
            ps[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j==0)
            {
                ps[i] = 0;
                i++;
            }
            else
            {
                j = ps[j];
            }
        }
    }
    i=0,j=0;
    while(i<n)
    {
        if(s[i] == t[j])
        {
            j++;
            i++;
            if(j==m)
                return i-j;
        }
        else
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j = ps[j];
            }
        }
    }
    return -1;
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<kmp(s,t);
    return 0;
}
