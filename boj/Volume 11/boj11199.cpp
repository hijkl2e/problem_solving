#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.rbegin(), A.rend());
	vector<int> B(T);
	for (int i = 0; i < N; ++i) {
		for (int j = A[i].second; j >= 0; --j) {
			if (B[j] == 0) {
				B[j] = A[i].first;
				break;
			}
		}
	}
	int ans = accumulate(B.begin(), B.end(), 0);
	cout << ans << "\n";
	return 0;
}
