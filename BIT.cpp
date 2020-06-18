#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll BIT[100005],a[100005],n;
void update(ll index, ll delta)// same function can be used to build the tree
{
    for(;index<=n;index+=(index&-index))// x&&-x gives the next element that is affected when value at index is changed
    {
        BIT[index]+=delta;
    }
}
ll query(ll index)
{
    ll sum=0;
    for(;index>0;index-=(index&-index))
    {
        sum+=BIT[index];
    }
    return sum;
}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    //get sum of first 5 element {1,2,3,4,5,6,7,8}
    cout<<query(5)<<"\n";
    // get sum of elements from 2 to 5;
    cout<<query(5)-query(2-1)<<"\n";
}