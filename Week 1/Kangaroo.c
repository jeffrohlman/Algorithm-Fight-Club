//https://www.hackerrank.com/contests/algorithm-fight-club-week-1/challenges/kangaroo
char* kangaroo(int x1, int v1, int x2, int v2) {
    //Since *x1* is always strictly less than *x2*:
    //if *v1* is less than *v2* there is no chance of catching the kangaroo
    if(v1 <= v2){
        return("NO");
    }
    else{
        //Add the velocities to the position to get the new position of each kangaroo
        //Once *x1* is more than or equal to *x2* the loop ends
        while(x1 < x2){
            x1 += v1;
            x2 += v2;
        }
        //Now just check if their posititions are equal and return YES if so and NO if not
        if(x1 == x2){
            return("YES");
        }
        else{
            return("NO");
        }
    }
}