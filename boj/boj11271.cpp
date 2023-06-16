#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(), A.end());
	multiset<int> S;
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (S.size() < K || *S.begin() <= A[i].second) {
			if (S.size() && *S.begin() <= A[i].second) {
				auto it = --S.upper_bound(A[i].second);
				S.erase(it);
			}
			S.insert(A[i].first);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
