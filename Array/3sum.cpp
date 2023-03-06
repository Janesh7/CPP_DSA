#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > Threesum(vector<int>arr,int n,int s)
{
    vector< vector <int> > ans;
    sort(arr.begin(),arr.end());
    for (int i = 0;i<n-2;i++)
    {
        // && not(count(a.begin(),a.end(),arr[i])) && not(count(a.begin(),a.end(),arr[k]))
        int j=i+1,k=i+2;
        // while (arr[i]+arr[j]+arr[k]<=s )
        while (j<n)
        {
            if (arr[i]+arr[j]+arr[k]>s)
            {
                k=++j+1;
                continue;
            }
            else if (arr[i]+arr[j]+arr[k]==s)
            {
                vector<int> a;
                a.push_back(arr[i]);
                a.push_back(arr[j]);
                a.push_back(arr[k]);
                ans.push_back(a);
                break;
            }
            else if (k<n)
            {
                k++;
            }
            else 
                k=++j+1;

        }
    }
    if (ans.size() == 0)
        cout<<-1;
    else 
    {
        for (int i=0; i<ans.size();i++)
        {
            for (int j=0;j<3;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
        return ans;
    }
}

int main()
{
    vector<int> ar = {-26 ,32 ,4 ,17, -16, 18, 1, 8, 6, 8, 3, -13 };
    vector < vector<int> > a = Threesum(ar,12,10);
    return 0;
}