#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	int dist{}, time{};
	while (N--) {
		int D{}, R{}, G{};
		cin >> D >> R >> G;
		time += D - dist;
		int r = time % (R + G);
		if (r < R) {
			time += R - r;
		}
		dist = D;
	}
	time += L - dist;
	cout << time << "\n";
	return 0;
}
