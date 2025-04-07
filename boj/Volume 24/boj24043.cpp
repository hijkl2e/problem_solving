#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> vst(1 << 20);
	int x{};
	vst[0] = true;
	vector<int> B;
	for (int i = 0; i < N; ++i) {
		int y = x ^ A[i];
		if (vst[y]) {
			continue;
		}
		vst[y] = true;
		x = y;
		B.push_back(i + 1);
		i = -1;
	}
	cout << B.size() << "\n";
	for (int x : B) {
		cout << x << "\n";
	}
	return 0;
}
