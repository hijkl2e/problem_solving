#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

bool solve(int x) {
	return A[x] == B[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int cnt{};
	for (int i = 0; i < N; ++i) {
		if (A[i] != B[i]) {
			++cnt;
		}
	}
	bool yes = cnt == 0;
	for (int i = 1; i < N; ++i) {
		int j = i;
		int val = A[i];
		while (j && val < A[j - 1]) {
			cnt += solve(j);
			A[j] = A[j - 1];
			cnt -= solve(j);
			if (cnt == 0) {
				yes = true;
				i = N;
				break;
			}
			--j;
		}
		if (i != j) {
			cnt += solve(j);
			A[j] = val;
			cnt -= solve(j);
			if (cnt == 0) {
				yes = true;
				break;
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
