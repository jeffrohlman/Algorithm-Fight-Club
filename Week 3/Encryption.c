//https://www.hackerrank.com/contests/algorithm-fight-club-week-3/challenges/encryption
//Fails test 5 because hackerrank don't seem to even care about supporting C
char* encryption(char* s) {
    int len = strlen(s);
    int row = floor(sqrt(len));
    int col = ceil(sqrt(len));
    if(row * col < len){
        row++;
    }
    int i, j, counter = 0;
    char* result = (char*)calloc((len + col - 1), sizeof(char));
    //static char result[(len + col - 1)];
    for(i = 0; i < col; i++){
        for(j = 0; i + j < len; j+=col){
            result[counter++] = s[i + j];
        }
        if(i != col - 1){
            result[counter++] = ' ';
        }
    }
    return result;
}

//hvbp xrju fqah csvb bsuy