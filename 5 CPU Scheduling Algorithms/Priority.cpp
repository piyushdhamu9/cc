#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Process
{
    int pid;      // Process ID
    int bt;       // Burst Time
    int priority; // Priority
    int at;       // Arrival Time
    int wt;       // Waiting Time
    int tat;      // Turnaround Time
    bool completed; // To track if a process is completed
};

// Function to sort processes according to their arrival time initially
bool arrivalComparison(Process a, Process b)
{
    return a.at < b.at; // Sort by arrival time
}

// Function to find the next process to schedule based on priority
int selectProcess(vector<Process> &proc, int currentTime, int n)
{
    int idx = -1;
    int highestPriority = INT_MAX;

    // Find the process with the highest priority that has arrived
    for (int i = 0; i < n; i++)
    {
        if (!proc[i].completed && proc[i].at <= currentTime)
        {
            // Prioritize by priority, and then by arrival time if priority is the same
            if (proc[i].priority < highestPriority)
            {
                highestPriority = proc[i].priority;
                idx = i;
            }
            else if (proc[i].priority == highestPriority && proc[i].at < proc[idx].at)
            {
                idx = i;
            }
        }
    }
    return idx;
}

// Function to find the waiting time for all processes
void findWaitingTime(vector<Process> &proc, int n)
{
    int currentTime = 0; // Tracks the current time in the system

    // Process the first process that arrives at time 0
    int firstProcessIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (proc[i].at == 0)
        {
            firstProcessIdx = i;
            break;
        }
    }

    // Schedule the first process if found
    if (firstProcessIdx != -1)
    {
        proc[firstProcessIdx].wt = 0; // The first process has a waiting time of 0
        currentTime += proc[firstProcessIdx].bt; // Increment current time by its burst time
        proc[firstProcessIdx].completed = true; // Mark it as completed
    }

    // Schedule the rest of the processes based on priority
    while (true)
    {
        int idx = selectProcess(proc, currentTime, n);
        if (idx == -1) // No available process to schedule
            break;

        proc[idx].wt = currentTime - proc[idx].at;
        if (proc[idx].wt < 0)
            proc[idx].wt = 0;

        currentTime += proc[idx].bt; // Increment current time by burst time
        proc[idx].completed = true; // Mark the process as completed
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(vector<Process> &proc, int n)
{
    for (int i = 0; i < n; i++)
    {
        proc[i].tat = proc[i].bt + proc[i].wt; // TAT = Burst Time + Waiting Time
    }
}

// Function to calculate average waiting and turnaround times
void findAverageTime(vector<Process> &proc, int n)
{
    // Sort processes by arrival time initially
    sort(proc.begin(), proc.end(), arrivalComparison);

    // Find waiting time of all processes
    findWaitingTime(proc, n);

    // Find turnaround time for all processes
    findTurnAroundTime(proc, n);

    // Display processes along with their details
    cout << "Processes " << " Burst Time " << " Arrival Time " << " Priority "
         << " Waiting Time " << " Turn-Around Time\n";

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        cout << " " << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].at
             << "\t" << proc[i].priority << "\t" << proc[i].wt
             << "\t" << proc[i].tat << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n << endl;
}

// Driver code
int main()
{
    // Predefined input values
    vector<Process> proc = {
        {1, 11, 2, 0, 0, 0, false},
        {2, 28, 0, 5, 0, 0, false},
        {3, 2, 3, 12, 0, 0, false},
        {4, 10, 1, 2, 0, 0, false},
        {5, 16, 4, 9, 0, 0, false}
    };

    int n = proc.size(); // Number of processes

    findAverageTime(proc, n);
    return 0;
}
