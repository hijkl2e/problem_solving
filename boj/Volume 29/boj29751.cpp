#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w{}, h{};
	cin >> w >> h;
	cout << w * h / 2 << "." << (w * h % 2 ? 5 : 0) << "\n";
	return 0;
}
