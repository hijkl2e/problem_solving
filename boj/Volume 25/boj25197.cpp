#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	double ans = N * (N - 1) / 2.0 / K;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
