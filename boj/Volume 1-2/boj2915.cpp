#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

vector<is> roman{
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
	string B;
	cin >> B;
	string ans;
	for (int i = 1;; ++i) {
		string x = B;
		string y = to_roman(i);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		if (x == y) {
			ans = to_roman(i);
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
