#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A(26, -1);
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		fill(A.begin(), A.end(), S.size());
		bool yes = true;
		for (int i = 0; i < S.size(); ++i) {
			int x = S[i] - 'a';
			if (A[x] < i - 1) {
				yes = false;
				break;
			}
			A[x] = i;
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
