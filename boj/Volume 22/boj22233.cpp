#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	sort(A.begin(), A.end());
	deque<bool> B(N, true);
	int ans = N;
	while (M--) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		while (getline(iss, s, ',')) {
			int p = lower_bound(A.begin(), A.end(), s) - A.begin();
			if (p < N && s == A[p] && B[p]) {
				B[p] = false;
				--ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
