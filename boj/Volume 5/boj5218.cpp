#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> A(s1.size());
		for (int i = 0; i < A.size(); ++i) {
			A[i] = (s2[i] - s1[i] + 26) % 26;
		}
		cout << "Distances: ";
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
