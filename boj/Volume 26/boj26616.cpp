#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	++N, ++K;
	vector<int> A(N + 1, INF);
	A[K] = 0;
	vector<int> B(N + 1);
	vector<int> C;
	for (int i = 2; i <= K; ++i) {
		C.clear();
		int k = K;
		while (k) {
			C.push_back(k % i);
			k /= i;
		}
		k = *max_element(C.begin(), C.end()) + 1;
		while (true) {
			int x{};
			for (int j = C.size() - 1; j >= 0; --j) {
				x = k * x + C[j];
			}
			if (x > N || (C.size() == 2 && B[x] == C[1])) {
				break;
			}
			A[x] = min(A[x], i + k++);
			B[x] = C.size() == 2 ? C[1] : 0;
		}
	}
	ll ans = accumulate(A.begin() + 2, A.end(), 0LL);
	cout << ans << "\n";
	return 0;
}
