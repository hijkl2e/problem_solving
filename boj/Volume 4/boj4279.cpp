#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		bool canada{};
		vector<vector<int>> A(N, vector<int>(3));
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < 3; ++j) {
				cin >> A[i][j];
			}
			if (s == "Canada") {
				swap(A[i], A[0]);
				canada = true;
			}
		}
		vector<int> B(N);
		bool yes{};
		for (int i = 1; i < 10001; i *= 100) {
			for (int j = 1; j < 10001; j *= 100) {
				for (int k = 1; k < 10001; k *= 100) {
					for (int l = 0; l < N; ++l) {
						B[l] = i * A[l][0] + j * A[l][1] + k * A[l][2];
					}
					yes |= B[0] == *max_element(B.begin(), B.end());
				}
			}
		}
		yes &= canada;
		cout << "Canada " << (yes ? "wins!" : "cannot win.") << "\n";
	}
	return 0;
}
