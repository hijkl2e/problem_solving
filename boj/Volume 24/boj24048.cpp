#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

bool solve(int x) {
	return A[x] == B[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> C(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		C[i] = i;
	}
	vector<int> D;
	int cnt{};
	for (int i = 0; i < N; ++i) {
		if (A[i] != B[i]) {
			++cnt;
		}
	}
	bool yes = cnt == 0;
	while (C.size()) {
		for (int x : C) {
			if (A[x] > A[x + 1]) {
				cnt += solve(x) + solve(x + 1);
				swap(A[x], A[x + 1]);
				cnt -= solve(x) + solve(x + 1);
				yes |= cnt == 0;
				if (yes || --K == 0) {
					D.clear();
					break;
				}
				if (x) {
					D.push_back(x - 1);
				}
			}
		}
		swap(C, D);
		D.clear();
	}
	cout << yes << "\n";
	return 0;
}
