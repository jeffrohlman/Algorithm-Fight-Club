//https://www.hackerrank.com/contests/algorithm-fight-club-week-1/challenges/simple-array-sum
int simpleArraySum(int ar_count, int* ar) {
    int i, sum = 0;
    //Loop through every element in array *ar* and add it to *sum*
    for(i = 0; i < ar_count; i++){
        sum += *(ar + i);
    }
    return sum;
}