#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int cases = 0; cases < T; cases++) {
        int N, M;
        cin >> N >> M;
        vector<long long> arrP(N + M + 1);
        vector<long long> arrT(N + M + 1);
        long long PLeft = 0;
        long long TLeft = 0;
        for (int i = 0; i < N + M + 1; i++) {
            cin >> arrP[i];
            PLeft += arrP[i];
        }
        for (int i = 0; i < N + M + 1; i++) {
            cin >> arrT[i];
            TLeft += arrT[i];
        }
        long long specialP = PLeft;
        long long specialT = TLeft;

        int totalP = 0;
        int totalT = 0;
        long long totalPAmount = 0;
        long long totalTAmount = 0;
        long long PBound = 0;
        long long PBoundIndex = 1e10;
        long long PExtra = 0;
        long long PExtraIndex = 1e10;
        long long TBound = 0;
        long long TBoundIndex = 1e10;
        long long TExtra = 0;
        long long TExtraIndex = 1e10;

        for (int i = 0; i < N + M + 1; i++) {
            PLeft -= arrP[i];
            TLeft -= arrT[i];
            if (arrP[i] > arrT[i]) {
                totalP++;
                totalPAmount += arrP[i];
                if (totalP == N) {
                    PBound = totalPAmount + totalTAmount + TLeft;
                    PBoundIndex = i;
                }
                if (totalP == N + 1) {
                    PExtra = totalPAmount + totalTAmount + TLeft;
                    PExtraIndex = i;
                }
            } else {
                totalT++;
                totalTAmount += arrT[i];
                if (totalT == M) {
                    TBound = totalTAmount + totalPAmount + PLeft;
                    TBoundIndex = i;
                }
                if (totalT == M + 1) {
                    TExtra = totalTAmount + totalPAmount + PLeft;
                    TExtraIndex = i;
                }
            }
        }
        if (M == 0) {
            TBoundIndex = -1;
            TBound = specialP;
        }
        if (N == 0) {
            PBoundIndex = -1;
            PBound = specialT;
        }

        //cout << "PBound " << PBound << endl;
        //cout << "PBoundIndex" << PBoundIndex << endl;
        //cout << "TBound " << TBound << endl;
        // cout << "TBoundIndex " << TBoundIndex << endl;
        // cout << "PExtraIndex" << PExtraIndex << endl;
        //cout << "PExtra" << PExtra << endl; 
        //cout << "TExtraIndex" << TExtraIndex << endl;
        //cout << "TExtra" << TExtra << endl; 

        for (int i = 0; i < N + M + 1; i++) {
            if ((PBoundIndex < TBoundIndex && (arrP[i] < arrT[i] || i > PBoundIndex)) || 
                (PBoundIndex < TExtraIndex && (arrP[i] < arrT[i] && i <= PBoundIndex))) {
                cout << PBound - arrT[i] << " ";
            } else if ((TBoundIndex < PBoundIndex && (arrP[i] > arrT[i] || i > TBoundIndex)) || 
                        (TBoundIndex < PExtraIndex && (arrP[i] > arrT[i] && i <= TBoundIndex))) {
                cout << TBound - arrP[i] << " ";
            } else if (arrP[i] > arrT[i] && i <= PExtraIndex) {
                cout << PExtra - arrP[i] << " ";
            } else if (arrT[i] > arrP[i] && i <= TExtraIndex) {
                cout << TExtra - arrT[i] << " ";
            }
        }   
        cout << endl;
    }
    return 0;
}