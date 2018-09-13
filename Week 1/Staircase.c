//https://www.hackerrank.com/contests/algorithm-fight-club-week-1/challenges/staircase
void staircase(int n) {
    int i, j;
    //The staircase is of height n so loop from 1 - n
    for(i = 1; i <= n; i++){
        //To make a staircase of height *n* each line will also be equal to *n*
        //Each line will be filled with either spaces (" ") or hashes ("#")
        //As you make you way down the stairs you can decrease the spaces from *n*-1 to 0
        //At the same rate you can increase the hahses from 1 to *n*

        //This loop handles the spaces
        //You want the spaces to be equal to *n* minus the row you currently are on
        //*i* holds the row you are on so the spaces will be equal to *n*-*i*
        for(j = 0; j < n-i; j++){
            printf(" ");
        }

        //This loop handles the hashes
        //You want the hashes to be equal to the row you are on
        //*i* holds the row you are on so the hashes will be equal to *i*
        for(j = 0; j < i; j++){
            printf("#");
        }

        //Lastly, you want to move to the next line after each line is complete
        //However you don't want to move to the next line after the last line
        //So, move to the next line unless the current line (*i*) is equal to the height (*n*)
        if(i != n){
            printf("\n");
        }
    }
}