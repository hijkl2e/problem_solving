#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

void print(int x) {
	char c = 'A' + x;
	cout << c;
}

void pre(int x) {
	if (x == -1) {
		return;
	}
	print(x);
	pre(G[x][0]);
	pre(G[x][1]);
}

void in(int x) {
	if (x == -1) {
		return;
	}
	in(G[x][0]);
	print(x);
	in(G[x][1]);
}

void post(int x) {
	if (x == -1) {
		return;
	}
	post(G[x][0]);
	post(G[x][1]);
	print(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.assign(N, vector<int>(2));
	for (int i = 0; i < N; ++i) {
		char c1{}, c2{}, c3{};
		cin >> c1 >> c2 >> c3;
		G[c1 - 'A'][0] = c2 == '.' ? -1 : (c2 - 'A');
		G[c1 - 'A'][1] = c3 == '.' ? -1 : (c3 - 'A');
	}
	pre(0); cout << "\n";
	in(0); cout << "\n";
	post(0); cout << "\n";
	return 0;
}
