#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0, k = 1; j < L; j = k++) {
			if (A[i][j] == '0') {
				continue;
			}
			while (k < L && A[i][k] == '1') {
				++k;
			}
			++B[i];
		}
	}
	int maxv = *max_element(B.begin(), B.end());
	int cnt = count(B.begin(), B.end(), maxv);
	cout << maxv << " " << cnt << "\n";
	return 0;
}
