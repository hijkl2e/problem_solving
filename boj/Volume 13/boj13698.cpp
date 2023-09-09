#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(5);
	A[1] = 1, A[4] = 2;
	for (char c : S) {
		int x = c == 'F' ? 3 : c > 'C' ? 2 : 1;
		int y = c == 'A' ? 2 : c == 'B' || c == 'D' ? 3 : 4;
		swap(A[x], A[y]);
	}
	cout << find(A.begin(), A.end(), 1) - A.begin() << "\n";
	cout << find(A.begin(), A.end(), 2) - A.begin() << "\n";
	return 0;
}
