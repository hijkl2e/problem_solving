#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ax{}, ay{}, az{};
	cin >> ax >> ay >> az;
	int cx{}, cy{}, cz{};
	cin >> cx >> cy >> cz;
	int bx = cx - az;
	int by = cy / ay;
	int bz = cz - ax;
	cout << bx << " " << by << " " << bz << "\n";
	return 0;
}
