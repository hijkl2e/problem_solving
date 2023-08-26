#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		cout << *min_element(A.begin(), A.end()) << " ";
		cout << *max_element(A.begin(), A.end()) << "\n";
	}
	return 0;
}
