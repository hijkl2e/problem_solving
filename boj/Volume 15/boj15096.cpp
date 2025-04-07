#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A;
	A.reserve(N);
	while (N--) {
		int x{};
		cin >> x;
		if (x != -1) {
			A.push_back(x);
		}
	}
	double ans = accumulate(A.begin(), A.end(), 0) * 1.0 / A.size();
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
