//https://www.hackerrank.com/contests/algorithm-fight-club-week-3/challenges/mini-max-sum
void miniMaxSum(int arr_count, int* arr) {
    int min  = 100000000001;
    int max = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
    }
    int minSum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] - max;
    int maxSum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] - min;
    printf("%ld ", minSum);
    printf("%ld", maxSum);
}