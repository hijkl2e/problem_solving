#include <bits/stdc++.h>

using namespace std;

using ss = pair<string, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ss> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end(), [](ss &p1, ss &p2) {
		return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
	});
	for (auto &p : A) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
