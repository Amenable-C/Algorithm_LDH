#include <iostream>
using namespace std;


int tiles[256][256];
int num = 0;
int check(int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (tiles[i][j] != 0)
				return 0;
		}
	}
	return 1;
}

void divideAndPaint(int x, int y, int size) {
	++num;

	if (check(x, y, size >> 1))
		tiles[x + (size >> 1) - 1][y + (size >> 1) - 1] = num;
	if (check(x, y + (size >> 1), size >> 1))
		tiles[x + (size >> 1) - 1][y + (size >> 1)] = num;
	if (check(x + (size >> 1), y, size >> 1))
		tiles[x + (size >> 1)][y + (size >> 1) - 1] = num;
	if (check(x + (size >> 1), y + (size >> 1), size >> 1))
		tiles[x + (size >> 1)][y + (size >> 1)] = num;

	if (size == 2)
		return;

	divideAndPaint(x, y, size >> 1);
	divideAndPaint(x + (size >> 1), y, size >> 1);
	divideAndPaint(x, y + (size >> 1), size >> 1);
	divideAndPaint(x + (size >> 1), y + (size >> 1), size >> 1);
}





int main()
{
	int k, x, y;
	cin >> k >> x >> y;

	tiles[x - 1][y - 1] = -1;

	divideAndPaint(0, 0, 1 << k);
	for (int i = (1 << k) - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << k); j++) {
			cout << tiles[i][j] << " ";
		}
		cout << "\n";
	}
}

