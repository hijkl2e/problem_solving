#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, string> tab{
		{100, "A+"}, {96, "A"}, {89, "B+"}, {86, "B"}, {79, "C+"},
		{76, "C"}, {69, "D+"}, {66, "D"}, {59, "F"}
	};
	int N{};
	cin >> N;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x;
		cout << s << " " << tab.lower_bound(x)->second << "\n";
	}
	return 0;
}
