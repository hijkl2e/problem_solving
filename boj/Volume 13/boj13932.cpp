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
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	sort(A.rbegin(), A.rend());
	int sum{};
	for (auto &p : A) {
		sum += p.first;
	}
	if (sum < 2 * A[0].first) {
		cout << "impossible\n";
	} else {
		for (int i = 0; i < N; ++i) {
			cout << A[i].second << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
