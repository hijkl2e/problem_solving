#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	string ans;
	for (int i = 0; i < N; ++i) {
		if (A[i].find('S') != -1) {
			ans = A[i];
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
