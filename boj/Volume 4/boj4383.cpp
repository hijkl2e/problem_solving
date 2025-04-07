#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		deque<bool> vst(N);
		for (int i = 0; i < N - 1; ++i) {
			vst[abs(A[i + 1] - A[i])] = true;
		}
		bool yes = true;
		for (int i = 1; i < N; ++i) {
			yes &= vst[i];
		}
		cout << (yes ? "Jolly" : "Not jolly") << "\n";
	}
	return 0;
}
