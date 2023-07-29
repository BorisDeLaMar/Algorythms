#include <iostream>

using namespace std;

int board[512][512];
int m = 3;

void generate(int n, int x, int y, int hx, int hy) {
    if (n == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (x + i != hx || y + j != hy) {
                    board[x + i][y + j] = m++ / 3;
                }
            }
        }

        return;
    }

    // Middle trgl
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (x + i * n / 2 > hx || hx >= x + i * n / 2 + n / 2 || y + j * n / 2 > hy || hy >= y + j * n / 2 + n / 2) {
                board[x + n / 2 - 1 + i][y + n / 2 - 1 + j] = m++ / 3;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // With odd square
            if (x + i * n / 2 <= hx && hx < x + i * n / 2 + n / 2 && y + j * n / 2 <= hy && hy < y + j * n / 2 + n / 2) {
                generate(n / 2, x + i * n / 2, y + j * n / 2, hx, hy);
            // Without odd square
            } else {
                generate(n / 2, x + i * n / 2, y + j * n / 2, x + n / 2 - 1 + i, y + n / 2 - 1 + j);
            }
        }
    }
}

int main() {
    int dim, x, y;
    cin >> dim >> x >> y;

    dim = 1 << dim;

    generate(dim, 0, 0, x - 1, y - 1);

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}