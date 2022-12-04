#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

vector<is> roman{
	{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
	{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};

string to_roman(int x) {
	string ret;
	for (auto &p : roman) {
		while (x >= p.first) {
			ret += p.second;
			x -= p.first;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(1000);
	for (int i = 1; i < 1000; ++i) {
		A[i] = to_roman(i);
	}
	sort(A.begin(), A.end());
	int V_idx = lower_bound(A.begin(), A.end(), "V") - A.begin();
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		string s = to_roman(N % 1000);
		int idx = lower_bound(A.begin(), A.end(), s) - A.begin();
		if (s[0] < 'M') {
			idx += N / 1000 * V_idx;
		} else {
			idx -= 1000;
			idx -= N / 1000 * (1000 - V_idx);
		}
		cout << idx << "\n";
	}
	return 0;
}
