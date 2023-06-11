#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> ans{
		-1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768,
		10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537
	};
	int N{};
	cin >> N;
	cout << ans[N] << "\n";
	return 0;
}
