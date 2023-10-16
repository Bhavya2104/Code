#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph {
    public:
    unordered_map<T,list<T>> adjl;

    void addedge(T u,T v, bool direction)
    {
        adjl[u].push_back(v);
        if(!direction)
        {
            adjl[v].push_back(u);
        }
    }

    void Printadjl()
    {
        for(auto i:adjl)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>m;
    graph<int> g;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,0);
    }    

    g.Printadjl();
    return 0;
}