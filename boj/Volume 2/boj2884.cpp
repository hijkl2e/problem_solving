#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, M{};
	cin >> H >> M;
	int time = 60 * H + M;
	time = (time + 1395) % 1440;
	H = time / 60;
	M = time % 60;
	cout << H << " " << M << "\n";
	return 0;
}
