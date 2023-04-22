#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> A(1000001);
	for (int i = 1; i < A.size(); ++i) {
		for (int j = i; j < A.size(); j += i) {
			A[j] += i;
		}
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cout << A[N] << "\n";
	}
	return 0;
}
