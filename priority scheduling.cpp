#include<bits/stdc++.h> 
using namespace std; 
  
struct Process 
{ 
	string ccode;  		// course code
    int duration;  		// class duration
    int priority; 
}; 
  
// sort the classes based on priority
bool sortProcesses(Process a, Process b) 
{ 
    return (a.priority < b.priority); 
} 
  
// Function to find the waiting time for all classes 
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    // waiting time for first class is 0 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  proc[i-1].duration + wt[i-1] ; 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // duration[i] + wt[i] 
    for (int  i = 0; i < n ; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
//Function to calculate average time 
void findavgTime(Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    //Function to find waiting time of all classes 
    findWaitingTime(proc, n, wt); 
  
    //Function to find turn around time for all classes
    findTurnAroundTime(proc, n, wt, tat); 
  
    //Display processes along with all details 
    cout << "\n Course code  "<< "\t    Priority  " << "\t    Duration  "<< " Waiting time  " << " Turn around time\n"; 
  
    // Calculate total waiting time and total turn 
    // around time 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << proc[i].ccode << "\t\t"<< proc[i].priority << "\t\t" <<   proc[i].duration << "\t    " << wt[i] << "\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 
  
void priorityScheduling(Process proc[], int n) 
{ 
    // Sort processes by priority 
    sort(proc, proc + n, sortProcesses); 
  
    cout<< "Order in which processes gets executed \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].ccode <<" " ; 
  
    findavgTime(proc, n); 
} 
  

int main() 
{ 
    Process proc[] = {{"CSC2201",3,2}, {"INFO3401",2,3}, {"CSC1103",1,1}, {"CSC2706",3,1}, {"INFO2302",2,2}}; 
    int n = sizeof proc / sizeof proc[0]; 
    priorityScheduling(proc, n); 
    return 0; 
}

