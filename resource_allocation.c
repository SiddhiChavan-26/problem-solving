#include <stdio.h>
#include <stdlib.h>

// Structure to store job information
typedef struct {
    char name[10];
    int resources;
    int profit;
    float ratio;
} Job;

// Comparator function for sorting jobs by profit-to-resource ratio in decreasing order
int compare(const void *a, const void *b) {
    float r1 = ((Job*)b)->ratio - ((Job*)a)->ratio;
    return (r1 > 0) - (r1 < 0);
}

// Function to allocate resources using the greedy approach
void allocateResources(Job jobs[], int n, int totalResources) {
    // Step 1: Sort jobs by profit-to-resource ratio
    qsort(jobs, n, sizeof(Job), compare);
    
    printf("Allocated Jobs: ");
    int usedResources = 0, totalProfit = 0;
    
    // Step 2: Allocate resources to jobs greedily
    for (int i = 0; i < n; i++) {
        if (usedResources + jobs[i].resources <= totalResources) {
            printf("%s ", jobs[i].name);
            usedResources += jobs[i].resources;
            totalProfit += jobs[i].profit;
        }
    }
    
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n, totalResources;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    Job jobs[n];
    printf("Enter total available resources: ");
    scanf("%d", &totalResources);
    
    printf("Enter job details (name, required resources, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: Name: ", i + 1);
        scanf("%s", jobs[i].name);
        printf("Job %d: Required Resources: ", i + 1);
        scanf("%d", &jobs[i].resources);
        printf("Job %d: Profit: ", i + 1);
        scanf("%d", &jobs[i].profit);
        jobs[i].ratio = (float) jobs[i].profit / jobs[i].resources;
    }
    
    // Call function to allocate resources optimally
    allocateResources(jobs, n, totalResources);
    
    return 0;
}

