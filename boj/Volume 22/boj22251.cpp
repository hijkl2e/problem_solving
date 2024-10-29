#include <bits/stdc++.h>

using namespace std;

vector<int> A{0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int N, K, P, X;
vector<int> B;
int cnt, ans;

int func() {
	int ret{};
	for (int i = 0; i < K; ++i) {
		ret = 10 * ret + B[i];
	}
	return ret;
}

void solve(int d) {
	if (d == K) {
		int x = func();
		if (1 <= x && x <= N && cnt) {
			++ans;
		}
		return;
	}
	for (int i = 0; i < 10; ++i) {
		int x = __builtin_popcount(A[B[d]] ^ A[i]);
		if (cnt + x <= P) {
			int tmp = B[d];
			B[d] = i;
			cnt += x;
			solve(d + 1);
			B[d] = tmp;
			cnt -= x;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K >> P >> X;
	B.resize(K);
	for (int i = K - 1; i >= 0; --i) {
		B[i] = X % 10;
		X /= 10;
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}
