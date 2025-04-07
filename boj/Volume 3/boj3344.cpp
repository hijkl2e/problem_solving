#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int r = N % 6;
	vector<int> A;
	for (int i = r == 3 ? 4 : 2; i <= N; i += 2) {
		A.push_back(i);
	}
	if (r == 3) {
		A.push_back(2);
	}
	if (r == 2) {
		A.push_back(3);
		A.push_back(1);
	}
	for (int i = r == 2 ? 7 : r == 3 ? 5 : 1; i <= N; i += 2) {
		A.push_back(i);
	}
	if (r == 2) {
		A.push_back(5);
	} else if (r == 3) {
		A.push_back(1);
		A.push_back(3);
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
