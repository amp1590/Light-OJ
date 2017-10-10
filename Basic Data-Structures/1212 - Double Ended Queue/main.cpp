#include <bits/stdc++.h>

#define pf              printf
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
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
#define dqu             deque
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
#define intlim          2147483648
#define MAX             2000
#define inf             10000000

/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;

dqu<int> dq;

int main()
{
    CIN;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    loop1(z,t)
    {
        int n,m;
        cin>>n>>m;
        cout<<"Case "<<z<<":"<<endl;
        dq.clear();
        loop0(i,m)
        {
            string s;
            cin>>s;
            if(s=="pushLeft")
            {
                int x;
                cin>>x;
                if(dq.size()!=n)
                {
                    dq.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            if(s=="pushRight")
            {
                int x;
                cin>>x;
                if(dq.size()!=n)
                {
                    dq.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            if(s=="popLeft")
            {
                if(!dq.empty())
                {
                    cout<<"Popped from left: "<<dq.front()<<endl;
                    dq.pop_front();
                }
                else cout<<"The queue is empty"<<endl;
            }
            if(s=="popRight")
            {
                if(!dq.empty())
                {
                    cout<<"Popped from right: "<<dq.back()<<endl;
                    dq.pop_back();
                }
                else cout<<"The queue is empty"<<endl;
            }
        }

    }

    return 0;
}
