#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;
int cache[101];

int tiling(int width) {
    if (width <= 1)
        return 1;

    int &ret = cache[width];
    if (ret != -1)
        return ret;

    return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}

int solve(int width) {
    if (width % 2 == 1)
        return (tiling(width) - tiling(width / 2) + MOD) % MOD;

    int ret = tiling(width);
    ret = (ret - tiling(width / 2) + MOD) % MOD;
    ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int c;
    for (cin >> c; c--;) {
        cin >> n;

        memset(cache, -1, sizeof(cache));
        
        cout << solve(n) << '\n';
    }
}
