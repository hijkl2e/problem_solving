#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	int sum{}, minv = -1;
	for (int i = sqrt(N - 1) + 1; i * i <= M; ++i) {
		sum += i * i;
		minv = minv == -1 ? i * i : minv;
	}
	if (minv == -1) {
		cout << "-1\n";
	} else {
		cout << sum << "\n" << minv << "\n";
	}
	return 0;
}
