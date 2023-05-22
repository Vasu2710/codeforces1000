
/*
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥
 
    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,
 
    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to
   inaction
*/
#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

#define ll long long int
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define MOD 998244353
// cout <<setprecision(15)
#define NEED_FOR_SPEED      \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL);                    \
      cout.tie(NULL)

using namespace __gnu_pbds;
using namespace std;

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_sub(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b) % mod) + mod) % mod;
}
int poww(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}
int count; 
class DisjointSet{
        vector<ll> rank,parent,size;
        public:
        DisjointSet(ll n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)parent[i]=i;
        }
        
        ll findUpar(ll node)
        {
            if(node==parent[node]) return node;
            return parent[node]=findUpar(parent[node]);
        }
        
        void urank(ll u, ll v)
        {
            ll ulp_u=findUpar(u);
            ll ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return;
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u])
            {
                parent[ulp_v]=ulp_u;
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void usize(ll u, ll v)
        {
            ll ulp_u=findUpar(u);
            ll ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                 parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
                
        }
    };
void solve()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<int>pref, suf;
   set<char>st1;
   for(int i=0;i<n;i++)
   {
        st1.insert(s[i]);
        pref.push_back(st1.size());

   }
   set<char>st2;
   for(int i=n-1;i>=0;i--)
   {
        st2.insert(s[i]);
        suf.push_back(st2.size());
   } 
   reverse(suf.begin(), suf.end());
   int ans=0;
   for(int i=0;i<n-1;i++)
   {
    ans=max(ans, pref[i]+suf[i+1]);
   }
   cout << ans << "\n";
 //   for(int i=0;i<pref.size();i++)
 //     cout << pref[i] << " ";
 // cout << "\n";
 // for(int i=0;i<suf.size();i++)
 //    cout << suf[i] << " ";
 // cout << "\n";
   

}
signed main()
{
      NEED_FOR_SPEED;

      // cout << setprecision(15);
      int t=1;
      cin >> t;
      while (t--)
      {
            solve();
            // cout << endl;
      }
}
