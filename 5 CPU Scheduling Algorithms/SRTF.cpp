#include<bits/stdc++.h>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[], int ct[])
{
    int rt[n]; 

    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;


    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;

            finish_time = t + 1;
            ct[shortest] = finish_time; 

            wt[shortest] = finish_time - bt[shortest] - at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int at[])
{
    int wt[n], tat[n], ct[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, at, ct);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Completion Time " << " Waiting Time " << " Turn-Around Time\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t\t" << at[i]
             << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {6, 8, 7};
    int arrival_time[] = {0, 1, 2};

    findAverageTime(processes, n, burst_time, arrival_time);
    return 0;
}
