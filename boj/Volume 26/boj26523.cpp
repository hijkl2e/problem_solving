#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<double> A(5000);
	for (int tc = 0; tc < 100; ++tc) {
		for (int i = 0; i < A.size(); ++i) {
			cin >> A[i];
		}
		int cnt{};
		for (double x : A) {
			if (x < 0.05) {
				++cnt;
			}
		}
		cout << (cnt < 200 ? "B" : "A") << "\n";
	}
	return 0;
}
