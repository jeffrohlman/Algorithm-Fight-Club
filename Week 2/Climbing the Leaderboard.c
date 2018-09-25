//https://www.hackerrank.com/contests/algoirthm-fight-club-week-2/challenges/climbing-the-leaderboard
int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count) {
    *result_count = alice_count;
    int* positions = (int*)calloc(alice_count, sizeof(int));
    int i, j, ladder, previous = scores_count - 1, next = 1;
    
    for(i = 1; i < scores_count; i++){
        if(scores[i] != scores[i - 1]){
            next++;
        }
    }
    ladder = next + 1;
    
    for(i = 0; i < alice_count; i++){
        if(ladder != 1){
            if(alice[i] >= scores[previous]){
                while(alice[i] >= scores[previous] && previous != -1){
                    if(previous == 0){
                        next = 0;
                        previous--;
                    }
                    else{
                        if(scores[previous] != scores[previous - 1]){
                            next--;
                        }
                        previous--;
                    }
                }
                ladder = next + 1;
            }
        }
        positions[i] = ladder;
    }
    return positions;
}