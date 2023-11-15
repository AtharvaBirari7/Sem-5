#include <iostream>
#include <algorithm>
#include<limits.h>// For sorting
#include <vector>

using namespace std;

// Structure for every process
struct Process {
    int pid;      // Process ID
    int bt;       // Burst Time
    int art;      // Arrival Time
    bool executed; // Flag to track if the process has been executed
};

vector<int> Pid;
vector<int> T;

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void printGanttChart(Process proc[]){
    int min=INT_MAX;
    for(int a=0;a<Pid.size();a++){
        if(min>proc[a].art){
            min=proc[a].art;
        }
    }
    cout<<"\nGantt Chart:\n|";
    for(int i=0;i<Pid.size();i++){
            cout<<"    P"<<Pid[i]+1<<"    |";
    }
    cout<<"\n"<<min;
    for(int i=0;i<Pid.size();i++){
            if(T[i]>=10){
                cout<<"         "<<T[i];
            }
            else{
                cout<<"         "<<"0"<<T[i];
            }
    }
    cout<<"\n\n";
}
// Function to calculate average time
void findavgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    int currentTime = 0,completed=0;
    while(completed!=n){
        // Find the next process that has arrived and not executed yet
        int nextProcess = -1,temp=INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!proc[j].executed && proc[j].art <= currentTime) {
                if(proc[j].bt<temp){
                    temp=proc[j].bt;
                    nextProcess = j;
                }
            }
        }

        if (nextProcess != -1) {
            // Execute the next process
            proc[nextProcess].executed = true;
            wt[nextProcess] = currentTime - proc[nextProcess].art;
            currentTime += proc[nextProcess].bt;
            completed++;
            // Record the process and time in the Gantt chart
            Pid.push_back(nextProcess);
		    T.push_back(currentTime);
        } else {
            // If no process is available to execute, move time forward
            currentTime++;
        }
    }

    findTurnAroundTime(proc, n, wt, tat);
    printGanttChart(proc);

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "\nProcesses " <<proc[i].pid<<":\n";
        cout << "\tWaiting Time:"<< wt[i]<<"\n";
        cout << "\tTurn Around Time:" << tat[i] << "\n";
    }
    cout << "\nAverage waiting time = " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];

    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> proc[i].art;
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> proc[i].bt;
        proc[i].pid = i + 1;
        proc[i].executed=false;
    }


    findavgTime(proc, n);
    return 0;
}
