#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<ii> B(N);
		for (int i = 0; i < N; ++i) {
			B[i] = {A[i], i};
		}
		sort(B.begin(), B.end());
		set<int> S;
		for (int i = 0; i < N; ++i) {
			S.insert(S.end(), i);
		}
		bool yes = true;
		for (int i = 0; i < N - 1; ++i) {
			auto it = S.find(B[i].second);
			it = S.erase(it);
			if (B[i].first == B[i + 1].first && (it == S.end() || *it != B[i + 1].second)) {
				yes = false;
				break;
			}
		}
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
