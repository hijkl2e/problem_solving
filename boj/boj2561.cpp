#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

bool solve() {
	for (int i = 0; i < N; ++i) {
		if (A[i] != i + 1) {
			return false;
		}
	}
	return true;
}

void print(int x, int y, int z) {
	if (z) {
		cout << N - y << " " << N - x << "\n";
	} else {
		cout << x + 1 << " " << y + 1 << "\n";
	}
}

bool solve(int a, int b) {
	reverse(A.begin() + a, A.begin() + b + 1);
	if (solve()) {
		print(a, b, 0);
		print(0, 0, 0);
		print(0, 0, 0);
		return true;
	}
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N; ++i) {
			if (A[i] == i + 1) {
				continue;
			}
			int x = find(A.begin(), A.end(), i + 1) - A.begin();
			reverse(A.begin() + i, A.begin() + x + 1);
			if (solve()) {
				print(a, b, 0);
				print(i, x, k);
				print(0, 0, 0);
				return true;
			}
			for (int j = i + 1; j < N; ++j) {
				if (A[j] == j + 1) {
					continue;
				}
				int y = find(A.begin(), A.end(), j + 1) - A.begin();
				reverse(A.begin() + j, A.begin() + y + 1);
				if (solve()) {
					print(a, b, 0);
					print(i, x, k);
					print(j, y, k);
					return true;
				}
				reverse(A.begin() + j, A.begin() + y + 1);
				break;
			}
			reverse(A.begin() + i, A.begin() + x + 1);
			break;
		}
		reverse(A.begin(), A.end());
		for (int j = 0; j < N; ++j) {
			A[j] = N - A[j] + 1;
		}
	}
	reverse(A.begin() + a, A.begin() + b + 1);
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	if (solve(0, 0)) {
		return 0;
	}
	vector<int> B;
	for (int i = 0, j = 1; i < N; i = j++) {
		B.push_back(i);
		while (j < N && abs(A[j] - A[j - 1]) == 1) {
			++j;
		}
	}
	B.push_back(N);
	for (int i = 0; i < B.size(); ++i) {
		for (int j = i + 1; j < B.size(); ++j) {
			if (solve(B[i], B[j] - 1)) {
				i = B.size();
				break;
			}
		}
	}
	return 0;
}
