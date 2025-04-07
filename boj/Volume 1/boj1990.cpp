#include <bits/stdc++.h>

using namespace std;

int solve(int x, bool f) {
	string s = to_string(x);
	for (int i = s.size() - f - 1; i >= 0; --i) {
		s += s[i];
	}
	x = stoi(s);
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return -1;
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{5, 7, 11};
	for (int i = 10; i < 10000; ++i) {
		A.push_back(solve(i, true));
		A.push_back(solve(i, false));
	}
	sort(A.begin(), A.end());
	A.resize(unique(A.begin(), A.end()) - A.begin());
	int a{}, b{};
	cin >> a >> b;
	auto beg = lower_bound(A.begin(), A.end(), a);
	auto end = upper_bound(A.begin(), A.end(), b);
	while (beg != end) {
		cout << *beg++ << "\n";
	}
	cout << "-1\n";
	return 0;
}
