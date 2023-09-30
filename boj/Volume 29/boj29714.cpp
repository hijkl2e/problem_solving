#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<int, int> A;
	while (N--) {
		int x{};
		cin >> x;
		++A[x];
	}
	int Q{};
	cin >> Q;
	map<int, int> B;
	vector<int> C;
	while (Q--) {
		B.clear();
		int K{};
		cin >> K;
		while (K--) {
			int x{};
			cin >> x;
			++B[x];
		}
		cin >> K;
		C.resize(K);
		for (int i = 0; i < K; ++i) {
			cin >> C[i];
		}
		bool yes = true;
		for (auto &[a, b] : B) {
			if (A[a] < b) {
				yes = false;
				break;
			}
		}
		if (!yes) {
			continue;
		}
		for (auto &[a, b] : B) {
			A[a] -= b;
		}
		for (int i = 0; i < K; ++i) {
			++A[C[i]];
		}
	}
	C.clear();
	for (auto &[a, b] : A) {
		while (b--) {
			C.push_back(a);
		}
	}
	cout << C.size() << "\n";
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
