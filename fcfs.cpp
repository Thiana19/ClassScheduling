#include<iostream> 
using namespace std; 

struct Process
{
   string ccode;     	// course code
   int duration;      	// class duration
   int arrival_time;   	// prefered arrival time
};

void findWaitingTime(Process proc[], int n, int bt[], int wt[])
{
    // waiting time for first class will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all classes
    findWaitingTime(proc, n, bt, wt);
 
    // function to find turn around time for all classes
    findTurnAroundTime(proc, n, bt, wt, tat);
 
    // display processes along with all details
    cout << " Course code  "<< "\t    Arrival time "<< "  Duration" <<"   Waiting time " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].ccode << "\t\t" << proc[i].arrival_time << "\t\t" <<  bt[i] <<"\t      "<< wt[i] <<"\t\t    " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}


int main(){
	Process proc[] = {{"CSC2201",3,1}, {"INFO3401",2,2}, {"CSC1103",1,3},  {"CSC2706",3,4}, {"INFO2302",2,5}};
	int n = sizeof(proc) / sizeof(proc[0]);
	
	 // duration of all classes
   int  burst_time[] = {3, 2, 1};
   
   findAverageTime(proc, n,  burst_time);
   
   return 0;
}
