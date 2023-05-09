#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	int s{}, e{}, ans{};
	for (auto &p : A) {
		if (e < p.first) {
			e = p.second;
			++ans;
		} else {
			e = min(e, p.second);
		}
		s = p.first;
	}
	cout << ans << "\n";
	return 0;
}
