#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{}, C{}, P{};
	cin >> N >> T >> C >> P;
	int ans = (N - 1) / T * C * P;
	cout << ans << "\n";
	return 0;
}
