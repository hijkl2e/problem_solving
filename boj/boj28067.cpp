#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(3);
	vector<iii> B;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			for (int k = 0; k <= N; ++k) {
				for (int l = 0; l <= M; ++l) {
					if (i == k && j == l) {
						continue;
					}
					for (int m = 0; m <= N; ++m) {
						for (int n = 0; n <= M; ++n) {
							A[0] = (k - i) * (k - i) + (l - j) * (l - j);
							A[1] = (m - k) * (m - k) + (n - l) * (n - l);
							A[2] = (i - m) * (i - m) + (j - n) * (j - n);
							sort(A.begin(), A.end());
							if (sqrt(A[0]) + sqrt(A[1]) > sqrt(A[2]) + EPS) {
								B.push_back({A[0], A[1], A[2]});
							}
						}
					}
				}
			}
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	cout << B.size() << "\n";
	return 0;
}
