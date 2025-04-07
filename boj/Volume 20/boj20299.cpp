#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, L{};
	cin >> N >> K >> L;
	vector<int> A;
	while (N--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		if (a + b + c >= K && min({a, b, c}) >= L) {
			A.push_back(a);
			A.push_back(b);
			A.push_back(c);
		}
	}
	cout << A.size() / 3 << "\n";
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "" : " ");
	}
	cout << "\n";
	return 0;
}
