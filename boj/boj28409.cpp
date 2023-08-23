#include <bits/stdc++.h>

using namespace std;

struct rec {
	int w{}, h{};
};

bool operator==(const rec &r1, const rec &r2) {
	return r1.w == r2.w && r1.h == r2.h;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<rec> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i].w >> A[i].h;
		A[i].w += A[i - 1].w;
	}
	A[N + 1].w = A[N].w + 1;
	int M{};
	cin >> M;
	vector<rec> B(M + 2);
	for (int i = 1; i <= M; ++i) {
		cin >> B[i].w >> B[i].h;
		B[i].w += B[i - 1].w;
	}
	B[M + 1].w = B[M].w + 1;
	vector<int> C;
	for (int i = 1, j = 1; i <= M; ++i) {
		if (B[i - 1].h > B[i].h || B[i].h < B[i + 1].h) {
			continue;
		}
		while (A[j].w <= B[i - 1].w) {
			++j;
		}
		while (A[j].w <= B[i].w) {
			if (A[j].h == B[i].h) {
				C.push_back(j);
				break;
			}
			++j;
		}
	}
	vector<rec> D(N + 2);
	for (int i = 0; i < A.size(); ++i) {
		D[i].w = A[i].w;
	}
	for (int x : C) {
		D[x].h = A[x].h;
	}
	for (int i = 1; i <= N; ++i) {
		D[i].h = max(D[i].h, min(D[i - 1].h, A[i].h));
	}
	for (int i = N; i > 0; --i) {
		D[i].h = max(D[i].h, min(D[i + 1].h, A[i].h));
	}
	vector<rec> E;
	for (int i = 0, j = 1; i < N + 2; i = j++) {
		while (j < N + 2 && D[i].h == D[j].h) {
			++j;
		}
		E.push_back(D[j - 1]);
	}
	if (B == E) {
		cout << C.size() << "\n";
		for (int i = 0; i < C.size(); ++i) {
			cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
