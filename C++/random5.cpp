#include <iostream>
#include <vector>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void ssort(vector<int> &priority, vector<int> &burst_time, vector<int> &processes, int n)
{
    int min, i, j;

    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (priority[j] < priority[min])
                min = j;
        }

        swap(priority[min], priority[i]);
        swap(burst_time[min], burst_time[i]);
        swap(processes[min], processes[i]);
    }
}

void printTime(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void findWT(vector<int> &priority, vector<int> &burst_time, vector<int> &waiting_time, int n)
{
    waiting_time[0] = 0;

    for (int i = 1; i < n; i++)
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
}

void findTAT(vector<int> &priority, vector<int> &burst_time, vector<int> &waiting_time, vector<int> &turn_around_time, int n)
{
    for (int i = 0; i < n; i++)
        turn_around_time[i] = burst_time[i] + waiting_time[i];

}

void findTime(vector<int> &priority, vector<int> &burst_time, vector<int> &processes, int n)
{
    vector<int> waiting_time;
    vector<int> turn_around_time;
    int total_wt = 0;
    int total_tat = 0;

    findWT(priority, burst_time, waiting_time, n);

    findTAT(priority, burst_time, turn_around_time, waiting_time, n);

    cout << " Processes :-        ";
    printTime(processes, n);
    cout << " Arrival Time :-     ";
    printTime(priority, n);
    cout << " Burst Time :-       ";
    printTime(burst_time, n);
    cout << " Waiting Time :-     ";
    printTime(waiting_time, n);
    cout << " turn around Time :- ";
    printTime(turn_around_time, n);

    for (int i = 0; i < n; i++)
    {
        total_tat += turn_around_time[i];
        total_wt += waiting_time[i];
    }

    int avg_wt = total_wt / n;
    int avg_tat = total_tat / n;

    cout << endl
         << "The average turn around time is :- " << avg_tat;
    cout << endl
         << "The average waiting time is :-     " << avg_wt;
}

int main()
{
    int n, p, a, b;

    cout << "Enter the number of processes :- ";
    cin >> n;

    vector<int> processes;
    cout << "Enter the processes :-    ";
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        processes.push_back(p);
    }

    vector<int> priority;
    cout << "Enter priority :-         ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        priority.push_back(a);
    }

    vector<int> burst_time;
    cout << "Enter the burst time   :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        burst_time.push_back(b);
    }

    ssort(priority, burst_time, processes, n);
    findTime(priority, burst_time, processes, n);

    return 0;
}