#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		A.resize(unique(A.begin(), A.end()) - A.begin());
		for (int x : A) {
			cout << x << " ";
		}
		cout << "$\n";
	}
	return 0;
}
