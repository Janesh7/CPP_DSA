#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// My approach:
vector< vector<int> > Threesum(vector<int>arr,int n,int s)
{
    vector< vector <int> > ans;
    sort(arr.begin(),arr.end());
    vector<int> a;
    for (int i = 0;i<n-2;i++)
    {
        int j=i+1,k=i+2;
        while (j<n)
        {
            if (arr[i]+arr[j]+arr[k]>s)
            {
                k=++j+1;
                continue;
            }
            else if (arr[i]+arr[j]+arr[k]==s)
            {
                vector<int> temp;
                int flag=1;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                for (int i=0; i<ans.size();i++)
                    if (ans[i][0]==temp[0] && ans[i][1]==temp[1] && ans[i][2]==temp[2])
                    {
                        flag = 0; 

                    }
                if (not(flag)){
                    k++;
                    continue;
                }
                ans.push_back(temp);
                continue;
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
    // vector<int> ar ={9, 5, -20, -70, 2, 1, 82, 1, 4, 8, 55, -100 };
    vector<int> ar = {10 ,5 ,5 ,5 ,2};
    // vector<int> ar = {1,1,2,2,1,1};
    // vector<int> ar = {-26 ,32 ,4 ,17, -16, 18, 1, 8, 6, 8, 3, -13 };
    vector < vector<int> > a = Threesum(ar,5,12);
    return 0;
}