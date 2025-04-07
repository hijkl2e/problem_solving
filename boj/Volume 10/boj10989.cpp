#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(10001);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x];
	}
	for (int i = 0, j = 0; i < N; ++i) {
		while (A[j]-- == 0) {
			++j;
		}
		cout << j << "\n";
	}
	return 0;
}
