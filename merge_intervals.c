int compare(const void* a, const void* b) {
    int* interval1 = *(int**)a;
    int* interval2 = *(int**)b;
    return interval1[0] - interval2[0];
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize==0){
        *returnSize=0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result=(int**)malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes=(int*)malloc(intervalsSize *sizeof(int));

    result[0]=(int*)malloc(2 * sizeof(int));
    result[0][0]=intervals[0][0];
    result[0][1]=intervals[0][1];
    int j=0;

    for(int i=1; i < intervalsSize; i++){
        if(result[j][1] >= intervals[i][0]){
            result[j][1]= (result[j][1]>intervals[i][1])?result[j][1]:intervals[i][1];
        }
        else{
            j++;
            result[j] = (int*)malloc(2*sizeof(int));
            result[j][0] = intervals[i][0];
            result[j][1] = intervals[i][1];
        }
    }

    *returnSize = j + 1;
    for (int i = 0; i <= j; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
int main() {
    int intervalsArray[][2] = {{1, 3}, {2, 4}, {3, 6}, {7, 8}};
    int intervalsSize = 4;
    int intervalsColSize = 2;

    // Convert the array to a 2D pointer array
    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int*)malloc(intervalsColSize * sizeof(int));
        intervals[i][0] = intervalsArray[i][0];
        intervals[i][1] = intervalsArray[i][1];
    }

    int returnSize;
    int* returnColumnSizes;

    // Call the merge function
    int** result = merge(intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    // Print the result
    printf("Merged intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }

    // Free memory
    free(result);
    free(returnColumnSizes);
    for (int i = 0; i < intervalsSize; i++) {
        free(intervals[i]);
    }
    free(intervals);

    return 0;
}
