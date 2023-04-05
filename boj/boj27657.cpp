#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<deque<int>> A(2);
	A[0].resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[0][i];
	}
	vector<int> B(12);
	B[0] = 1;
	for (int i = 1; i < 12; ++i) {
		B[i] = 3 * B[i - 1];
	}
	vector<int> C(10);
	C[0] = 2, C[1] = 1;
	for (int i = 2; i < 10; ++i) {
		C[i] = 9 * C[i - 2] + 4;
	}
	deque<bool> D(33334);
	for (int i = 0; i < 10; ++i) {
		for (int j = C[i]; j < D.size(); j += B[i + 1]) {
			D[j] = true;
		}
	}
	vector<int> E;
	for (int i = 0; i < 11; ++i) {
		int k = i % 2;
		for (int j = 0; j < N; ++j) {
			int x = A[k].front();
			A[k].pop_front();
			int y = x / B[i] % 3;
			int z = x / B[i + 1];
			if (y == (D[z] ? 0 : 2)) {
				A[k].push_back(x);
				E.push_back(k ^ 2);
			} else if (y == 1) {
				A[k ^ 1].push_front(x);
				E.push_back(k);
			} else {
				A[k ^ 1].push_back(x);
				E.push_back(k);
				E.push_back(k ^ 3);
			}
		}
		while (A[k].size()) {
			A[k ^ 1].push_front(A[k].front());
			A[k].pop_front();
			E.push_back(k);
		}
	}
	for (int i = 0; i < N; ++i) {
		E.push_back(1);
	}
	vector<string> op{"PP 0 1", "PP 1 0", "RO 0", "RO 1"};
	cout << E.size() << "\n";
	for (int x : E) {
		cout << op[x] << "\n";
	}
	return 0;
}
