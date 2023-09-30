#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		vector<string> A(N);
		map<string, int> B;
		vector<string> C(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			B[s] = i;
		}
		for (int i = 0; i < N; ++i) {
			cin >> C[i];
		}
		for (int i = 0; i < N; ++i) {
			cout << C[B[A[i]]] << (i == N - 1 ? "\n" : " ");
		}
	}
	return 0;
}
