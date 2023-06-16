#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{};
	while (cin >> N >> a >> b, N) {
		vector<int> A(N);
		vector<int> B(N);
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			cin >> C[i] >> A[i] >> B[i];
		}
		vector<int> D;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < C[i]; ++j) {
				D.push_back(A[i] - B[i]);
			}
		}
		sort(D.begin(), D.end());
		int ans{};
		for (int i = 0; i < N; ++i) {
			ans += C[i] * A[i];
		}
		a -= accumulate(C.begin(), C.end(), 0);
		while (a < 0 || (b > 0 && D.size() && D.back() > 0)) {
			ans -= D.back();
			D.pop_back();
			++a, --b;
		}
		cout << ans << "\n";
	}
	return 0;
}
