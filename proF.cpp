//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 1000005
#define MOD
#define Task "proF"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll d[maxn];
ll suf[maxn];
ll n, m, k;
bool check(ll x)
{
    ll cnt = 0;
    ll j = m * m;
    for (int i = 1; i <= n * n; i ++){
        while (c[i] + d[j] >= x && j) j --;
        cnt += m * m - j;
    }
    return (cnt >= k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    fi >> n >> m >> k;
    for (int i = 1; i <= n; i ++) fi >> a[i];
    for (int i = 1; i <= m; i ++) fi >> b[i];
    ll cnt = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            c[++ cnt] = a[i] + a[j];
        }
    sort(c + 1, c + cnt + 1);
    for (int i = 1; i <= cnt; i ++) suf[i] = c[i] + suf[i - 1];
    cnt = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= m; j ++)
            d[++ cnt] = b[i] + b[j];
    sort(d + 1, d + cnt + 1);
    ll l = -oo;
    ll r = oo;
    while(r - l > 1)
    {
        ll mid = (r + l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    ll res = 0;
    cnt = 0;
    for (int i = 1; i <= m * m; i ++)
    {
        int pos = upper_bound(c + 1, c + n * n + 1, l - d[i]) - c - 1;
        res += suf[n * n] - suf[pos] + d[i] * (n * n - pos);
        cnt += n * n - pos;
    }
    res += (k - cnt) * l;
    fo << res;
}
