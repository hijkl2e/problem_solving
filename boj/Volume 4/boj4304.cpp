#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s), s != "0") {
		istringstream iss(s);
		iss >> s;
		int N = stoi(s.substr(0, s.size() - 1));
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			iss >> A[i];
		}
		vector<int> B(N);
		for (int i = 0; i < N; ++i) {
			B[A[i]] = i;
		}
		bool yes = true;
		for (int i = 0; i < N; ++i) {
			for (int k = i + 2; k < N; k += 2) {
				int j = (i + k) / 2;
				if ((B[i] < B[j]) ^ (B[j] > B[k])) {
					yes = false;
				}
			}
		}
		cout << (yes ? "yes" : "no") << "\n";
	}
	return 0;
}
