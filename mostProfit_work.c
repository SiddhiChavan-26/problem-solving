#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

int compareInt(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int maxProfitAssignment(int *difficulty, int *profit, int difficultySize, int *worker, int workerSize) {

    int jobs[difficultySize][2];
    for (int i = 0; i < difficultySize; i++) {
        jobs[i][0] = difficulty[i];
        jobs[i][1] = profit[i];
    }

    qsort(jobs, difficultySize, sizeof(jobs[0]), compare);

    qsort(worker, workerSize, sizeof(int), compareInt);

    // Preprocess jobs to maintain max profit for each difficulty
    int maxProfit = 0;
    for (int i = 0; i < difficultySize; i++) {
        if (jobs[i][1] > maxProfit) {
            maxProfit = jobs[i][1];
        }
        jobs[i][1] = maxProfit;
    }

    // Assign jobs to workers
    int sum = 0;
    int j = 0; // Pointer for jobs
    for (int i = 0; i < workerSize; i++) {
        while (j < difficultySize && jobs[j][0] <= worker[i]) {
            j++;
        }
        if (j > 0) {
            sum += jobs[j - 1][1]; // Add the maximum profit for the worker's skill
        }
    }

    return sum;
}

int main() {
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 11};
    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);

    int result = maxProfitAssignment(difficulty, profit, difficultySize, worker, workerSize);
    printf("Maximum Profit: %d\n", result);

    return 0;
}

