#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int x = N;
	while (x && A[x - 1] == B[x - 1]) {
		--x;
	}
	int y = -1;
	for (int i = 0; i < x - 1; ++i) {
		if (B[i] == B[i + 1]) {
			y = i;
			break;
		}
	}
	bool yes{};
	if (y == -1) {
		sort(A.begin(), A.begin() + x);
		yes = A == B;
	} else {
		sort(A.begin(), A.begin() + x - 1);
		for (int i = y + 1; i < x - 1; ++i) {
			B[i] = B[i + 1];
		}
		B[x - 1] = A[x - 1];
		yes = A[x - 1] < B[y] && A == B;
	}
	cout << yes << "\n";
	return 0;
}
