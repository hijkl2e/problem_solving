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
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (A[j] > A[j + 1]) {
				cnt += solve(j) + solve(j + 1);
				swap(A[j], A[j + 1]);
				cnt -= solve(j) + solve(j + 1);
				if (cnt == 0) {
					yes = true;
					break;
				}
			}
		}
	}
	cout << yes << "\n";
	return 0;
}
