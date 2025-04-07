#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<is> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first >> A[i].second;
		}
		cout << max_element(A.begin(), A.end())->second << "\n";
	}
	return 0;
}
