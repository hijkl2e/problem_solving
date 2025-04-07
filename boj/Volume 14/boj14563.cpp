#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int sum{};
		for (int i = 1; i < N; ++i) {
			if (N % i == 0) {
				sum += i;
			}
		}
		if (sum < N) {
			cout << "Deficient\n";
		} else if (sum > N) {
			cout << "Abundant\n";
		} else {
			cout << "Perfect\n";
		}
	}
	return 0;
}
