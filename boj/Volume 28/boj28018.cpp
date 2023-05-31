#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(1000005);
	while (N--) {
		int s{}, e{};
		cin >> s >> e;
		++A[s], --A[e + 1];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int Q{};
	cin >> Q;
	while (Q--) {
		int t{};
		cin >> t;
		cout << A[t] << "\n";
	}
	return 0;
}
