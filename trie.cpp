#include<bits/stdc++.h>
using namespace std;
const int SIZE=26;
struct node{
    bool end; // To check if it is end of word.
    node *arr[SIZE];
    int cnt;
};
node *getnode()
{
    node *n= new node;
    n->end=false;
    n->cnt=0;
    for(int i=0;i<SIZE;i++)
    {
        n->arr[i]=NULL;
    }
    return n;
}
void insert(node *root, string st) // returns number of words having st as a prefix
{
    node *tmp= root;
    for(int i=0;i<st.length();i++)
    {
        int index=st[i]-'a';
        if(tmp->arr[index]==NULL)
        tmp->arr[index]=getnode();
        
        tmp=tmp->arr[index];
        tmp->cnt=tmp->cnt+1;
    }
    tmp->end=true;
}

int search(node *root, string st)
{
    node *tmp = root;
    int ans=0;
    for(int i=0;i<st.length();i++)
    {
        int index=st[i]-'a';
        if(tmp->arr[index]==NULL)
        {
            ans=0;
            break;
        }
        
        tmp=tmp->arr[index];
        ans=tmp->cnt;
    }
    return ans;
}
int main()
{
    int n,q;
    cin>>n>>q;
    string st;
    node *root=getnode();
    for(int i=0;i<n;i++)
    {
        cin>>st;
        insert(root,st);
    }
    while(q--)
    {
        cin>>st;
        cout<<search(root,st)<<endl;
    }
    
    return 0;
}