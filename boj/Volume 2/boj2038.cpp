#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> dp{0};
	int sum{}, j = 1, k{};
	while (sum < N) {
		dp.push_back(j);
		sum += j;
		if (++k == dp[j]) {
			++j, k = 0;
		}
	}
	cout << dp.size() - 1 << "\n";
	return 0;
}
