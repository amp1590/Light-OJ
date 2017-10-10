#include <bits/stdc++.h>

#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define db              double
#define ft              float
#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define vc              vector
#define vi              vector<int>
#define vll             vector<long long>
#define pii             pair<int,int>
#define pis             pair<int,string>
#define psi             pair<string,int>
#define all(x)          x.begin(),x.end()
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define loop0(i,n)      for(int i=0;i<n;i++)
#define loop1(i,n)      for(int i=1;i<=n;i++)
#define stlloop0(i,x)   for(int i=0;i<x.size();i++)
#define stlloop1(x)     for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       ((a)*((b)/gcd(a,b)))
#define PI              3.14159265358979323846264338328
#define MAX             10001

using namespace std;

vector<int>g[MAX],top;
int indeg[MAX];
map<string,int> mp;

int main()
{
     CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,m;
    cin>>t;
    loop1(z,t)
    {
        cin>>m;
        int c=1;
        ms(indeg,0);
        for(int i=0; i<m; i++)
        {
            string from,to;
            cin>>from>>to;
            if(mp[from]==0)
            {
                mp[from]=c;
                c++;
            }
            if(mp[to]==0)
            {
                mp[to]=c;
                c++;
            }
            g[mp[from]].pb(mp[to]);
            indeg[mp[to]]++;
        }
        for(int i=1; i<=c-1; i++)
        {
            if(indeg[i]==0) top.pb(i);
        }
        for(int i=0; i<top.size(); i++)
        {
            int v=top[i];
            for(int j=0; j<g[v].size(); j++)
            {
                int u=g[v][j];
                indeg[u]--;
                if(indeg[u]==0) top.pb(u);
            }
        }
        if(top.size()==c-1) cout<<"Case "<<z<<": Yes"<<endl;
        else cout<<"Case "<<z<<": No"<<endl;
        loop0(i,MAX) g[i].clear();
        top.clear();
        mp.clear();
    }
    return 0;
}
