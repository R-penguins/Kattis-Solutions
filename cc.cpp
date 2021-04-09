#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using LL = long long;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

constexpr LL MAXN = 2000000000000000005LL;
LL n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
inline LL ls(LL x)
{
    return x<<1;
}
inline LL rs(LL x)
{
    return x<<1|1;
}
void scan()
{
    cin>>n>>m;
    for(LL i=1;i<=n;i++)
    scanf("%LLd",&a[i]);
}
inline void push_up(LL p)
{
    ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(LL p,LL l,LL r)
{
    tag[p]=0;
    if(l==r){ans[p]=a[l];return ;}
    LL mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);
} 
inline void f(LL p,LL l,LL r,LL k)
{
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}
inline void push_down(LL p,LL l,LL r)
{
    LL mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}
inline void update(LL nl,LL nr,LL l,LL r,LL p,LL k)
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;
        return ;
    }
    push_down(p,l,r);
    LL mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}
LL query(LL q_x,LL q_y,LL l,LL r,LL p)
{
    LL res=0;
    if(q_x<=l&&r<=q_y)return ans[p];
    LL mid=(l+r)>>1;
    push_down(p,l,r);
    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
    return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nuLLptr);

  return 0;
}
