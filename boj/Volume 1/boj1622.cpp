#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	while (getline(cin, A)) {
		getline(cin, B);
		vector<int> C(26);
		vector<int> D(26);
		for (char c : A) {
			++C[c - 'a'];
		}
		for (char c : B) {
			++D[c - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			char c = 'a' + i;
			cout << string(min(C[i], D[i]), c);
		}
		cout << "\n";
	}
	return 0;
}
