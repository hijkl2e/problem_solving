#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{}, R{};
	while (cin >> F >> R) {
		vector<int> A(F);
		vector<int> B(R);
		for (int i = 0; i < F; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < R; ++i) {
			cin >> B[i];
		}
		vector<double> C;
		for (int i = 0; i < F; ++i) {
			for (int j = 0; j < R; ++j) {
				C.push_back(B[j] * 1.0 / A[i]);
			}
		}
		sort(C.begin(), C.end());
		double ans{};
		for (int i = 1; i < C.size(); ++i) {
			ans = max(ans, C[i] / C[i - 1] + EPS);
		}
		cout << fixed << setprecision(2);
		cout << ans << "\n";
	}
	return 0;
}
