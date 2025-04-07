#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int idx = max_element(B.begin(), B.end()) - B.begin();
	A[idx] = 0;
	sort(A.rbegin(), A.rend());
	vector<ii> ans;
	for (int i = 0; i < N; ++i) {
		if (A[i]) {
			ans.push_back({idx + 1, A[i]});
		}
	}
	for (int i = 0; i < N; ++i) {
		if (idx == i || B[i] == 0) {
			continue;
		}
		ans.push_back({i + 1, B[i]});
	}
	cout << ans.size() << "\n";
	for (auto &p : ans) {
		cout << "+ " << p.first << " " << p.second << "\n";
	}
	return 0;
}
