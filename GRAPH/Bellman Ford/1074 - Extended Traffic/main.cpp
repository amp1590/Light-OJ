#include <bits/stdc++.h>

#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define db              double
#define ft              float
#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define sz(x)           x.size()
#define qu              queue
#define pqu             priority_queue
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
#define stlloop(x)     for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)       __gcd(a, b)
#define lcm(a, b)       ((a)*((b)/gcd(a,b)))
#define case(z,x)       cout<<"Case "<<i<<": "<<x<<endl
#define case(z)         cout<<"Case "<<z<<": "
#define PI              3.14159265358979323846264338328
#define valid(tx,ty)    tx>=0 && tx<r && ty>=0 && ty<c
#define MAX             300
#define inf             10000000

/*---------------------------Graph Moves-----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------------------------*/

using namespace std;

int dis[MAX],parent[MAX];
vector<int>gu,gv,cost;
int node,edge;
map <int, int> mp;

bool bellman_ford()
{
    loop0(i,MAX) dis[i]=inf;
    dis[1]=0;
    loop1(i,node)
    {
        bool change=0;
        loop0(j,edge)
        {
            int u=gu[j];
            int v=gv[j];
            if(dis[u]+cost[j]<dis[v])
            {
                change=1;
                dis[v]=dis[u]+cost[j];
            }
        }
        if(change==0) return 1;
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n_cost,t;
    cin>>t;
    loop1(z,t)
    {
        cin>>node;
        loop1(i,node)
        {
            cin>>n_cost;
            mp[i]=n_cost;
        }
        cin>>edge;
        loop0(i,edge)
        {
            int from,to,w;
            cin>>from>>to;
            gu.pb(from);
            gv.pb(to);
            w=mp[to]-mp[from];
            cost.pb(w*w*w);
        }
        int q,n;
        cin>>q;
        cout<<"Case "<<z<<":"<<endl;
        int a=bellman_ford();
        loop0(i,q)
        {
            cin>>n;
            if(dis[n]<3 || dis[n]>100000) cout<<"?"<<endl;
            else cout<<dis[n]<<endl;
        }
        gu.clear();
        gv.clear();
        cost.clear();
        mp.clear();
    }
    return 0;
}
//
///*
//         +-+ +-+ +-+
//         |R| |.| |S|
//         +-+ +-+ +-+
// */
//
//#include <bits/stdc++.h>
//
//#define pii             pair <int,int>
//#define sc              scanf
//#define pf              printf
//#define Pi              2*acos(0.0)
//#define ms(a,b)         memset(a, b, sizeof(a))
//#define pb(a)           push_back(a)
//#define MP              make_pair
//#define db              double
//#define ll              long long
//#define EPS             10E-10
//#define ff              first
//#define ss              second
//#define sqr(x)          (x)*(x)
//#define D(x)            cout<<#x " = "<<(x)<<endl
//#define VI              vector <int>
//#define DBG             pf("Hi\n")
//#define MOD             100007
//#define MAX             202
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sff(a,b)        scanf("%d%d",&a,&b)
//#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
//#define loop(i,n)       for(int i=0;i<n;i++)
//#define REP(i,a,b)      for(int i=a;i<b;i++)
//#define TEST_CASE(t)    for(int z=1;z<=t;z++)
//#define PRINT_CASE      printf("Set #%d\n",z)
//#define all(a)          a.begin(),a.end()
//#define intlim          2147483648
//#define inf             1000000
//#define ull             unsigned long long
//
//using namespace std;
//
//int n,m;
//int weight[MAX], d[MAX];
//vector<int>u,v,cost,graph[MAX];
//void allclear()
//{
//    loop(i,n+1)
//    {
//        weight[i]=0;
//        d[i]=inf;
//    }
//    d[1]=0;
//    u.clear();
//    v.clear();
//    cost.clear();
//}
//
//int main()
//{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    int t;
////    sf(t);
////    TEST_CASE(t)
//int z=0;
//    while(sf(n)==1)
//    {
//        z++;
//
//        allclear();
//        for(int i=1;i<=n;i++) sf(weight[i]);
//        sf(m);
//        int x,y;
//        loop(i,m)
//        {
//            sff(x,y);
//            u.pb(x);
//            v.pb(y);
//            int xx=weight[y]-weight[x];
//            cost.pb(xx*sqr(xx));
//        }
//
//        for(int i=1;i<=n;i++)
//        {
//            bool update=0;
//            loop(i,m)
//            {
//                int x=u[i];
//                int y=v[i];
//                if(d[x]+cost[i]<d[y])
//                {
//                    update=1;
//                    d[y]=d[x]+cost[i];
//                }
//            }
//            if(update==0)
//                break;
//        }
//        PRINT_CASE;
//        int p,q;
//        sf(q);
//        loop(i,q)
//        {
//            sf(p);
//            if(d[p]<3 ||d[p]>100000)
//                pf("?\n");
//            else
//                pf("%d\n",d[p]);
//        }
//    }
//    return 0;
//}
