#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(26);
	int ans{};
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			fill(B.begin(), B.end(), 0);
			for (int k = 0; k < N; k += K) {
				for (int l = 0; l < M; l += K) {
					++B[A[k + i][l + j] - 'A'];
				}
			}
			int p = max_element(B.begin(), B.end()) - B.begin();
			for (int k = 0; k < N; k += K) {
				for (int l = 0; l < M; l += K) {
					if (A[k + i][l + j] == 'A' + p) {
						continue;
					}
					A[k + i][l + j] = 'A' + p;
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
