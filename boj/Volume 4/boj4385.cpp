#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> reg(10);
	vector<int> ram(1001);
	for (int i = 0; cin >> ram[i]; ++i);
	int pc{}, ans{};
	while (true) {
		++ans;
		int x = ram[pc] / 100;
		int y = ram[pc] % 100 / 10;
		int z = ram[pc] % 10;
		if (x == 1) {
			break;
		} else if (x == 2) {
			reg[y] = z;
		} else if (x == 3) {
			reg[y] = (reg[y] + z) % 1000;
		} else if (x == 4) {
			reg[y] = (reg[y] * z) % 1000;
		} else if (x == 5) {
			reg[y] = reg[z];
		} else if (x == 6) {
			reg[y] = (reg[y] + reg[z]) % 1000;
		} else if (x == 7) {
			reg[y] = (reg[y] * reg[z]) % 1000;
		} else if (x == 8) {
			reg[y] = ram[reg[z]];
		} else if (x == 9) {
			ram[reg[z]] = reg[y];
		} else {
			if (reg[z]) {
				pc = reg[y];
				continue;
			}
		}
		++pc;
	}
	cout << ans << "\n";
	return 0;
}
