#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(101);
	vector<int> B(101);
	vector<int> C(101);
	vector<int> D(101);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		++A[x];
		++B[y];
		int ans{};
		copy(A.begin(), A.end(), C.begin());
		copy(B.begin(), B.end(), D.begin());
		for (int i = 1, j = 100; i < 101;) {
			int minv = min(C[i], D[j]);
			if (minv) {
				ans = max(ans, i + j);
				C[i] -= minv;
				D[j] -= minv;
			}
			i = C[i] ? i : (i + 1);
			j = D[j] ? j : (j - 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
