#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(13);
	A[0] = "-";
	for (int i = 1; i < 13; ++i) {
		A[i] = A[i - 1] + string(A[i - 1].size(), ' ') + A[i - 1];
	}
	int N{};
	while (cin >> N) {
		cout << A[N] << "\n";
	}
	return 0;
}
