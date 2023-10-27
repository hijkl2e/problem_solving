#include <bits/stdc++.h>

using namespace std;

vector<int> solve(deque<int> &A) {
	int N = A.size();
	deque<int> B;
	vector<int> C;
	for (int i = 0, p = 1;; ++i, p *= 3) {
		int k = i % 2;
		if (p >= N) {
			if (k) {
				reverse(A.begin(), A.end());
				for (int i = 0; i < N; ++i) {
					C.push_back(1);
				}
			}
			break;
		}
		for (int j = 0; j < N; ++j) {
			int x = A.front();
			A.pop_front();
			int y = x / p % 3;
			if (y == 0) {
				A.push_back(x);
				C.push_back(k ^ 2);
			} else if (y == 1) {
				B.push_front(x);
				C.push_back(k);
			} else {
				B.push_back(x);
				C.push_back(k);
				C.push_back(k ^ 3);
			}
		}
		while (A.size()) {
			B.push_front(A.front());
			A.pop_front();
			C.push_back(k);
		}
		swap(A, B);
	}
	return C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i;
	}
	solve(B);
	for (int i = 0; i < N; ++i) {
		A[i] = B[A[i] - 1];
	}
	vector<int> C = solve(A);
	vector<string> op{"PP 0 1", "PP 1 0", "RO 0", "RO 1"};
	cout << C.size() << "\n";
	for (int x : C) {
		cout << op[x] << "\n";
	}
	return 0;
}
