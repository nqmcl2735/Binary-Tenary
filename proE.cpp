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
#define maxn 1000010
#define MOD
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, k;
ll c[maxn];
bool check(ll x)
{
    ll cnt = 0;
    for (ll i = 2; i <= 2 * n * k; i ++)
    {
        if (i > 2 * cnt * k + 2) return 0;
        else if (c[i] - c[i - 1] <= x)
        {
            i ++;
            cnt ++;
        }
        if (cnt == n) return 1;
    }
    return (cnt == n);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> k;
    for (ll i = 1; i <= 2 * n * k; i ++) cin >> c[i];
    sort (c + 1, c + 2 * n * k + 1);
    ll l = -2000000000;
    ll r = 2000000000;
    while (r - l > 1)
    {
        ll mid = (l + r) /2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}
