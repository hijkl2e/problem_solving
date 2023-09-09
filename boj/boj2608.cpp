#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

string solve(int x) {
	static vector<is> A{
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
		{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
	};
	string ret;
	for (auto &[u, v] : A) {
		while (x >= u) {
			x -= u;
			ret += v;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	vector<string> A(4001);
	for (int i = 1; i < A.size(); ++i) {
		A[i] = solve(i);
	}
	int x = find(A.begin(), A.end(), s1) - A.begin();
	int y = find(A.begin(), A.end(), s2) - A.begin();
	int sum = x + y;
	cout << sum << "\n";
	cout << A[sum] << "\n";
	return 0;
}
