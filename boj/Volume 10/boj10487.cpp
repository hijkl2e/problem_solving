#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, string> n2e{
		{256, "***"}, {68, "**+"}, {60, "**-"}, {32, "*+*"}, {24, "*++"},
		{17, "*+/"}, {16, "+++"}, {15, "*-/"}, {9, "++/"}, {8, "*/+"}, {7, "+-/"},
		{4, "+//"}, {2, "/+/"}, {1, "*//"}, {0, "*-*"}, {-1, "--/"}, {-4, "//-"},
		{-7, "/--"}, {-8, "+-*"}, {-15, "/-*"}, {-16, "--*"}, {-60, "-**"}
	};
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		auto it = n2e.find(N);
		if (it == n2e.end()) {
			cout << "no solution\n";
		} else {
			auto &s = it->second;
			cout << "4 " << s[0] << " 4 " << s[1] << " 4 " << s[2] << " 4 = " << N << "\n";
		}
	}
	return 0;
}
