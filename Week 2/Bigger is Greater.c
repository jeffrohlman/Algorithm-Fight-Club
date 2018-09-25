//https://www.hackerrank.com/contests/algoirthm-fight-club-week-2/challenges/bigger-is-greater
void swap(char *str1, int p1, int p2)
{ 
  char temp = str1[p1]; 
  str1[p1] = str1[p2]; 
  str1[p2] = temp; 
}   

char* biggerIsGreater(char* w) {
    int len = strlen(w);
    int i, pos = -1, j;
    bool p = false;
    for(i = len - 1; i > 0 && !p; i--){
        if(w[i] > w[i - 1]){
            p = true;
            pos = i;
        }
    }
    if(p){
        int low = (int)w[pos];
        int pos2 = pos;
        for(i = pos + 1; i < len; i++){
            if((int)w[i] < low && (int)w[i] > (int)w[pos - 1]){
                pos2 = i;
                low = (int)w[i];
            }
        }
        swap(w, pos - 1, pos2);
        for(i = pos; i < len - 1; i++){
            for(j = i + 1; j < len; j++){
                if((int)w[i] > (int)w[j]){
                    swap(w, i, j);
                }
            }
        }
        return w;
    }
    else{
        return "no answer";
    }
}