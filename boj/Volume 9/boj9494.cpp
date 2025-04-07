#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		int p{};
		while (A[0][p] == ' ') {
			++p;
		}
		for (int i = 0; i < N; ++i) {
			while (p < A[i].size() && A[i][p] != ' ') {
				++p;
			}
		}
		cout << p + 1 << "\n";
	}
	return 0;
}
