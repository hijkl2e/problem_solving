#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	mt19937 gen(random_device{}());
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B;
	for (int k = 0; k < 20; ++k) {
		int z = gen() % N;
		int x = A[z];
		vector<int> C;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i) {
				continue;
			}
			while (x % i == 0) {
				x /= i;
			}
			C.push_back(i);
		}
		if (x > 1) {
			C.push_back(x);
		}
		for (int p : C) {
			B.clear();
			for (int i = 0; i < N && B.size() < (N + 1) / 2; ++i) {
				if (A[i] % p == 0) {
					B.push_back(A[i]);
				}
			}
			if (B.size() == (N + 1) / 2) {
				k = 20;
				break;
			}
		}
	}
	if (B.size() == (N + 1) / 2) {
		cout << "YES\n";
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}
