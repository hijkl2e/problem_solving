#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(1000001);
	for (int i = 0; i < A.size(); ++i) {
		string s = to_string(i);
		A[i] = count(s.begin(), s.end(), '0');
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		int ans = A[M] - (N ? A[N - 1] : 0);
		cout << ans << "\n";
	}
	return 0;
}
