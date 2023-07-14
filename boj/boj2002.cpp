#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	map<string, int> B;
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		string S;
		getline(cin, S);
		B[S] = i;
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		int x = B[A[i]];
		for (int j = 0; j < i; ++j) {
			if (B[A[j]] > x) {
				++ans;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
