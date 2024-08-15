#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string actual;
    string recieved;
    cin >> actual >> recieved;
    int finalPos = 0;
    for (int i = 0; i < actual.size(); i++) {
        if (actual[i] == '+') {
            finalPos++;
        } else {
            finalPos--;
        }
    }
    vector<int> field (101, 0.0);
    int amount = 1;
    for (int i = 0; i < recieved.size(); i++) {
        if (recieved[i] == '?') {
            amount *= 2;
        }
    }
    //std::cout << "here" << endl;
    int offset = 50;
    int curPos = 0;
    field[curPos + offset] = double(amount);
    for (int i = 0; i < recieved.size(); i++) {
        vector<int> newField (101, 0.0); 
        for (int j = 1; j+1 < field.size(); j++) {
            if (recieved[i] == '+') {
                newField[j+1] += field[j];
            } else if (recieved[i] == '-') {
                newField[j-1] += field[j];
            } else {
                newField[j+1] += field[j] / 2.0;
                newField[j-1] += field[j] / 2.0;
            }
            //std::cout << "here" << endl;
        }
        field = newField;
    }

    std::cout << fixed;
    std::cout << setprecision(10);
    std::cout << double(double(field[finalPos + offset]) / double(amount)) << '\n';
    return 0;

}