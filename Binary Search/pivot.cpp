#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find_pivot(vector<int> v) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
}