#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<is> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	stable_sort(A.begin(), A.end(), [](const is &a, const is &b) {
		return a.first < b.first;
	});
	for (auto &p : A) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
