#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(4);
	for (int i = 0; i < 4; ++i) {
		cin >> A[i];
	}
	vector<int> B(4);
	for (int i = 0; i < M - 1; ++i) {
		++B[S[i] == 'A' ? 0 : S[i] == 'C' ? 1 : S[i] == 'G' ? 2 : 3];
	}
	int ans{};
	for (int i = M - 1; i < N; ++i) {
		++B[S[i] == 'A' ? 0 : S[i] == 'C' ? 1 : S[i] == 'G' ? 2 : 3];
		bool yes = true;
		for (int j = 0; j < 4; ++j) {
			if (A[j] > B[j]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
		int k = i - M + 1;
		--B[S[k] == 'A' ? 0 : S[k] == 'C' ? 1 : S[k] == 'G' ? 2 : 3];
	}
	cout << ans << "\n";
	return 0;
}
