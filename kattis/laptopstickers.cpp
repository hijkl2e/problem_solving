#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, H{}, K{};
	cin >> L >> H >> K;
	vector<string> A(H, string(L, '_'));
	for (int k = 0; k < K; ++k) {
		int l{}, h{}, a{}, b{};
		cin >> l >> h >> a >> b;
		for (int i = 0; i < h && b + i < H; ++i) {
			for (int j = 0; j < l && a + j < L; ++j) {
				A[b + i][a + j] = 'a' + k;
			}
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
