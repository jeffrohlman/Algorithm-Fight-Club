//https://www.hackerrank.com/challenges/the-grid-search/problem

char* gridSearch(int G_count, char** G, int P_count, char** P) {
    int GC = strlen(G[0]);
    int PC = strlen(P[0]);
    bool found = false;
    for(int i = 0; i <= G_count - P_count && !found; i++){
        for(int j = 0; j <= GC - PC && !found; j++){
            if(G[i][j] == P[0][0]){
                found = true;
                for(int k = 0; k < P_count && found; k++){
                    for(int l = 1; l < PC && found; l++){
                        if(P[k][l] != G[i+k][j+l]){
                            found = false;
                        }
                    }
                }
            }
        }
    }
    if(found){
        char* str = "YES";
        return str;
    }
    else{
        char* str = "NO";
        return str;
    }
}