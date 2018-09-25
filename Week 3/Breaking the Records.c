//https://www.hackerrank.com/contests/algorithm-fight-club-week-3/challenges/breaking-best-and-worst-records
int* breakingRecords(int scores_count, int* scores, int* result_count) {
    int max = scores[0];
    int min = scores[0];
    *result_count = 2;
    int *results = malloc(sizeof(int) * 2);
    *results = 0;
    *(results + 1) = 0;
    int i;
    for(i = 1; i < scores_count; i++){
        if(scores[i] > max){
            max = scores[i];
            results[0]++;
        }
        else if(scores[i] < min){
            min = scores[i];
            results[1]++;
        }
    }
    
    return results;
}