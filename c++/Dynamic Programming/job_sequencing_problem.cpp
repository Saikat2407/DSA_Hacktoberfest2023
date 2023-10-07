// Name: Samarth Kumar
// Github Username: Samarthku
// Date: 02/oct/2023
// Project Name: Job Sequecing Problem with c++

// Introduction
// We will discuss the job sequencing problem. The job sequencing problem requires us to select jobs in such a way that it maximizes the total profit and deadlines must be taken into consideration.

// Code Start
#include <bits/stdc++.h>
using namespace std;

// Structure
typedef struct Job {

    char id; 
    int profit; 
    int deadline; 
	
} Job;

// Comparator function
bool compare(Job a, Job b)
{
	return (a.profit - b.profit);
}


// Get maximum profit from jobs
void jobSequence(Job jobs[], int n)
{
	// Sort all jobs as per the decreasing order of the profit
	sort(jobs, jobs + n, compare);

	int result[n]; // To store result (Sequence of jobs)
	bool time[n]; // To keep track of free time

	// Initially all time points must be available
	for (int i = 0; i < n; i++)
		time[i] = false;

	// Iterate over time
	for (int i = 0; i < n; i++) {
	
		// Find the free time
		for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
		
			// Free slot found
			if (time[j] == false) {
				result[j] = i; 
				time[j] = true; 
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
	{
		if (time[i])
		{
    		 cout << jobs[result[i]].id << ' ';
   
		}
	}
}

// Driver's code
int main()
{
    
    // All jobs
	Job jobs[] = { { 'A', 70, 4 },
				{ 'B', 20, 1 },
				{ 'C', 30, 2 },
				{ 'D', 40, 1 },
				{ 'E', 60, 3 } };
	int n = 5;
	cout <<	"The maximum profit can be achieved by doing the following jobs in sequence.\n";
    
    // Calling jobSequence() function
	jobSequence(jobs, n);
	return 0;
}
// Code End
// Output
// D C E A
