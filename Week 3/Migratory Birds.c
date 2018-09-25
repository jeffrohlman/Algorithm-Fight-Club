//https://www.hackerrank.com/contests/algorithm-fight-club-week-3/challenges/migratory-birds
int migratoryBirds(int arr_count, int* arr) {
    int i;
    int t[5] = {0,0,0,0,0};
    for(i = 0; i < arr_count; i++){
        t[*(arr + i) - 1]++;
    }
    int max = t[0], maxnum = 0;
    for(i = 1; i < 5; i++){
        if(t[i] > max){
            max = t[i];
            maxnum = i;
        }
    }
    return maxnum + 1;
}