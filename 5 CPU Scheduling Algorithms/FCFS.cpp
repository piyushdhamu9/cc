#include <iostream>
using namespace std;

void CalculateTimes(int at[], int bt[], int N) {

    int wt[N], tat[N], ct[N];
    int currentTime = 0;

    cout << "PN\tAT\tBT\tCT\tWT\tTAT\n\n";

    for (int i = 0; i < N; i++) {
        if (at[i] > currentTime) {
            currentTime = at[i]; 
        }

        ct[i] = currentTime + bt[i];
        currentTime = ct[i]; 

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cout << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < N; i++) {
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nAverage waiting time = " << totalWT / N;
    cout << "\nAverage turnaround time = " << totalTAT / N << endl;
}

int main() {

    int N = 4;
    int at[] = {0, 1, 6, 8};
    int bt[] = {2, 2, 3, 4};

    CalculateTimes(at, bt, N);

    return 0;
}
