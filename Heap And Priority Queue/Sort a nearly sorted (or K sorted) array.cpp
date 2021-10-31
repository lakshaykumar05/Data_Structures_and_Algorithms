#include <bits/stdc++.h>
using namespace std;

//insertion sort based approach (intuitive)
//Time complexity : O( n * k)
//Space complexity : O(1)
void sortk(vector<int>&v , int k)
{
    int len = v.size();
    for(int i  =0 ; i < len ; i++)
    {
        int maxi = i + k;
        for(int j = i ; j < maxi; j++)
        {
            if(j>=len)
                break;
            if(v[j] < v[i])
            {
                swap(v[i] , v[j]);
                break;
            }
        }
    }
    for(auto i : v)
        cout<<i<<" ";
    cout<<"\n";

}
//heap based approach
//time complexity = O(k) + O(n-k) * log(k)
//space complexity = O(k)
int sortK_heap(vector<int>&v , int k)
{
    int len = v.size();
    int size=(len==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < size; i++) {
        pq.push(v[i]);
    }
    for(int i = size ; i < len ; i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
        pq.push(v[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n"; 

}
int main() {
	int t ; cin>>t;
    while(t--)
    {
	    int len , k ; cin>>len>>k;
	    vector<int>res , v;
	    for(int i =0 ; i < len ; i++)
	    {
	        int ele; cin>>ele;
	        v.push_back(ele);
	    }
        // sortk(v,k);
        sortK_heap(v,k);
    }
	return 0;
}