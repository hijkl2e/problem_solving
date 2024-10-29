#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<double> A{9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
	vector<double> B{26.7, 75, 1.5, 42.5, 210, 3.8, 254};
	vector<double> C{1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
	int T{};
	cin >> T;
	while (T--) {
		vector<int> P(7);
		for (int i = 0; i < 7; ++i) {
			cin >> P[i];
		}
		int ans{};
		for (int i = 0; i < 7; ++i) {
			int x = A[i] * pow(abs(B[i] - P[i]), C[i]);
			ans += x;
		}
		cout << ans << "\n";
	}
	return 0;
}
