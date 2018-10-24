//https://www.hackerrank.com/challenges/bomber-man/problem
//Getting weird memory errors again, have to allocate space but all alloc calls lead to random unicode letters at end of line
//Hackerrank's C memory management is awful
//Solves 15/18

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    int len = strlen(grid[0]);
    int t = n % 4;
    bool neighbor = false;
    *result_count = grid_count;
    
    if(n == 1)
        return grid;
    else if(t == 0 || t == 2){
        char** all = calloc(grid_count, sizeof(char*));
        for(int i = 0; i < grid_count; i++){
            all[i] = calloc(len, sizeof(char));
            for(int j = 0; j < len; j++){
                    all[i][j] = 'O';
            }
        }
        return all;
    }
    else{
        char** init = calloc(grid_count, sizeof(char*));
        for(int i = 0; i < grid_count; i++){
            init[i] = calloc(len, sizeof(char));
            for(int j = 0; j < len; j++){
                neighbor = false;
                if(i > 0 && grid[i - 1][j] == 'O')
                    neighbor = true;
                else if(i < grid_count - 1 && grid[i + 1][j] == 'O')
                    neighbor = true;
                else if(j > 0 && grid[i][j - 1] == 'O')
                    neighbor = true;
                else if(j < len - 1 && grid[i][j + 1] == 'O')
                    neighbor = true;
                else if(grid[i][j] == 'O')
                    neighbor = true;
                if(neighbor)
                    init[i][j] = '.';
                else
                    init[i][j] = 'O';
            }
        }
        if(t == 3){
            return init;
        }
        else{
            char** inv = calloc(grid_count, sizeof(char*));
            for(int i = 0; i < grid_count; i++){
                inv[i] = calloc(len, sizeof(char));
                for(int j = 0; j < len; j++){
                    neighbor = false;
                    if(i > 0 && init[i - 1][j] == 'O')
                        neighbor = true;
                    else if(i < grid_count - 1 && init[i + 1][j] == 'O')
                        neighbor = true;
                    else if(j > 0 && init[i][j - 1] == 'O')
                        neighbor = true;
                    else if(j < len - 1 && init[i][j + 1] == 'O')
                        neighbor = true;
                    else if(init[i][j] == 'O')
                        neighbor = true;
                    if(neighbor)
                        inv[i][j] = '.';
                    else
                        inv[i][j] = 'O';
                }
            }
            return inv;
        }
    }
}