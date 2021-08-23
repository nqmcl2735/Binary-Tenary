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
#define maxn 100005
#define MOD
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
int a[maxn];
int b[maxn];
bool check(int x)
{
    for (int i = 1, j = 1; i <= n; i ++)
    {
        if (a[i] >= x) continue;
        while(a[i] + b[j] < x && j <= m) j ++;
        if(j > m) return 0;
        j ++;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++) cin >> b[i];
     int l = *min_element(a + 1, a + n + 1) - 1;
    int r = *max_element(a + 1, a + n + 1) + *max_element(b + 1, b + m + 1) + 1;
    while (r - l > 1)
    {
        int mid = (l + r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}
