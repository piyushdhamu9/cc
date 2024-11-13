#include <iostream>
using namespace std;

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        bool allocated = false;

        for (int count = 0; count < m; count++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                allocated = true;
                break;
            }
            j = (j + 1) % m;
        }

        if (!allocated)
        {
            allocation[i] = -1;
        }
    }

    cout << "\nNext-Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    nextFit(blockSize, m, processSize, n);

    return 0;
}
