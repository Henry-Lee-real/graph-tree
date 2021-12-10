#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int head, e[N], ne[N], idx;
void init();
void insert_head(int a);
void remove_head(void);
void remove(int k);
void insert(int k, int a);

int main() {
	int m;
	cin >> m;
	while (m--) {
		string a;
		cin >> a;
		if (a == "H") {
			int x;
			cin >> x;
			insert_head(x);
		}
		if (a == "D") {
			int x;
			cin >> x;
			if (x != 0)
				remove(x - 1);
			else
				remove_head();
		}
		if (a == "I") {
			int k, x;
			cin >> k >> x;

			insert(k - 1, x);
		}
	}
	for (int i = head; i != -1; i = ne[i])
		cout << e[i] << ' ' << endl;

	return 0;
}

void init() {
	head = -1;
	idx = 0;
}

void insert_head(int a) {
	e[idx] = a;
	ne[idx] = head;
	head = idx++;
}

void remove_head(void) {
	head = ne[head];
}

void insert(int k, int a) {
	e[idx] = a;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}

void remove(int k) {
	ne[k] = ne[ne[k]];
}