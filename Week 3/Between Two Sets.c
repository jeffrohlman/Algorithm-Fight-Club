//https://www.hackerrank.com/contests/algorithm-fight-club-week-3/challenges/between-two-sets

//HackerRank again messed up the parsing in the default main() function when writing for C
//Most likely they use an autoconvertor and don't even check to see that it functions correctly
//To fix change this line (line 60):
//int total = getTotalX(a_count, a, b_count, b);
//To this:
//int total = getTotalX(n, a, m, b);
//They never declare a_count or b_count and instead they are declared as n and m respectively

int getTotalX(int a_count, int* a, int b_count, int* b) {
    int i, j, count = 0;
    bool p;
    for(i = a[a_count - 1]; i <= b[0]; i += a[a_count - 1]){
        p = true;
        for(j = 0; j < a_count && p; j++){
            if(i%a[j] != 0){
                p = false;
            }
        }
        for(j = 0; j < b_count && p; j++){
            if(b[j]%i != 0){
                p = false;
            }
        }
        if(p){
            count++;
        }
    }
    return count;
}