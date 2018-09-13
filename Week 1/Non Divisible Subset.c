//https://www.hackerrank.com/contests/algorithm-fight-club-week-1/challenges/non-divisible-subset
//If you run this in HackerRank it will solve 15/16 cases because it will hit a runtime error for case #5 regardless of solution
//There is an issue in how they parse the inputs which causes a runtime error

int nonDivisibleSubset(int k, int S_count, int* S) {
    //Initialize an array that is the size of *k*
    //Each position in array *count* will hold the number of variable in *S* that are modulus *k* of the position in *count*
    int count[k];
    int i, maxSubset;
    for(i = 0; i < k; i++){
        count[i] = 0;
    }
    for(i = 0; i < S_count; i++){
        count[S[i]%k]++;
    }
    //If there is a number divisible by *k* 
    //then you can add it to a number not divisible by *k* and the resulting sum will not be divisible by *k*
    //So if there is a number divisible to *k* initilize *maxSubset* to 1
    if(count[0] > 0)
        maxSubset = 1;
    else
        maxSubset = 0;
    
    //Next you want to compare items in *count* that add up to *k*
    //So you just need to loop through half of *count* and compare it's corresponding *count* position
    //So I'll find the halfway point and store it in *splitArray*
    int splitArrayPosition = k/2 + 1;
    
    //If *k* is even then the mid point won't have a corresponding position adding up to *k* besides itself
    //So if the midpoint is greater than 0 (meaning there is a number that has modulus half of *k*)
    //Then increase *maxSubset* by 1 and decrease the comparison position by 1
    if(k % 2 == 0){
        if(count[k/2] > 0)
            maxSubset++;
        splitArrayPosition--;
    }
    
    //Now loop through *count* up the the middle position we determined above
    //and if the *count[i]* is greater than it's corresponding part (*count[k-i]*) then add *count[i]* to the subset
    //if it's not greater then add *count[k-i]* to the subset
    for(i = 1; i < splitArrayPosition; i++){
        if(count[i] > count[k-i])
            maxSubset+= count[i];
        else
            maxSubset+= count[k-i];
    }
    //Return the max subset
    return maxSubset;
}