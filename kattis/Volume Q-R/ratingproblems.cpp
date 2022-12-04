#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int sum{};
	for (int i = 0; i < K; ++i) {
		int x{};
		cin >> x;
		sum += x;
	}
	double min = (sum - 3.0 * (N - K)) / N;
	double max = (sum + 3.0 * (N - K)) / N;
	cout << fixed << setprecision(10);
	cout << min << " " << max << "\n";
	return 0;
}
