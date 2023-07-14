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
	int t{};
	for (int i = 0; i < N; ++i) {
		t = max(t, A[i].first) + A[i].second;
	}
	cout << t << "\n";
	return 0;
}
