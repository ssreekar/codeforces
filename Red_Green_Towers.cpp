#include <iostream>
#include <vector>

using namespace std;

int findH(int R, int G) {
    int H = 1;
    while(G > H) {
        G -= H;
        H++;
    }
    R -= (H - G);
    H++;
    G = 0;
    while (R > H) {
        R -= H;
        H++;
    }
    H--;
    return H;
}

int recurse(int greenLeft, int currLayer, int R, int G, int maxAmount) {
    if (currLayer == 0) {
        if ((G - greenLeft) + R == maxAmount) {
            return 1;
        } else {
            return 0;
        }
    } 
    int value1 = recurse(greenLeft, currLayer-1, R, G, maxAmount); 
    int value2 = 0;
    if (greenLeft >= currLayer) {
        value2 = recurse(greenLeft - currLayer, currLayer-1, R, G, maxAmount);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, G;
    cin >> R >> G;
    if (R < G) {
        swap(R, G);
    }
    int H = findH(R, G);
    int maxAmount = (H * (H + 1)) / 2;
    cout << recurse(G, H, R, G) << '\n';

    return 0;
}