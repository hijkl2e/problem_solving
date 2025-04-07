#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ans{};
	for (int i = 0, j = 0; i < N && j < N;) {
		if (A[i] < B[j]) {
			++i;
		} else if (A[i] > B[j]) {
			++j;
		} else {
			++i, ++j;
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
