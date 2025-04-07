#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		istringstream iss(S);
		vector<string> A;
		while (iss >> S) {
			A.push_back(S);
		}
		rotate(A.begin(), A.begin() + 2, A.end());
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
