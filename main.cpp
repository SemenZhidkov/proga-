#if 0
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map>
#include <chrono>
#include <set>
#include <stack>
#include <vector>
#include <time.h>
#include <random>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long, long>
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a < b) ? b : a)
#define ALL(a) a.begin(), a.end()
#define sp << " "
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void smax(int& a, int b) { if (b > a)a = b; }
inline void smin(int& a, int b) { if (b < a)a = b; }
inline void smax(ll& a, ll b) { if (b > a)a = b; }
inline void smin(ll& a, ll b) { if (b < a)a = b; }



using namespace std;

const std::string DIGITS = "0123456789";
const std::string ALPH = "abcdefghijklmnopqrstuvwxyz";
std::uniform_int_distribution<int>uid(-1e9, 1e9);
const double PI = 2 * acos(0.0);
constexpr ll LLINF = ll(2e18) + 13;
constexpr int INF = int(1e9) + 7;
constexpr int SIZE = 1e6 + 10;

bool cmp(ll a, ll b) {
    ll cnt_f = 0, cnt_s = 0;
    while (a % 2 == 0) {
        cnt_f += 1;
        a /= 2;
    }
    while (b % 2 == 0) {
        cnt_s += 1;
        b /= 2;
    }
    return cnt_f > cnt_s;
}

void solve() {
    vector<ll> ar;
    ll n, k;
    ull vr, sch = 0, ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> vr;
        while (vr % 2 == 0) {
            sch += 1;
            vr /= 2;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        ar.push_back(i);
    }
    sort(ALL(ar), cmp);
    for (int i = 0; i <= n / 2; ++i) {
        if (sch < n) {
            k = ar[i];
            while (k % 2 == 0) {
                sch += 1;
                k /= 2;
            }
            ans += 1;
        }
        else {
            break;
        }
    }
    if (sch < n) {
        std::cout << -1 << std::endl;
        return;
    }
    std::cout << ans << std::endl;
}

signed main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
#ifdef _DEBUG
    freopen("r", stdin);
	freopen("w", stdout);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}