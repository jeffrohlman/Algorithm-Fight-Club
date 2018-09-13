//https://www.hackerrank.com/contests/algoirthm-fight-club-week-2/challenges/queens-attack-2
int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles) {
	//set *c_q* and *r_q* to *x* and *y* to make the code more readable
    int x = c_q; 
    int y = r_q;

    //Set the max possible positions the queen could move in each direction if there were no obstructions
    int columnUp = n - y;
    int columnDown = y - 1;
    int rowRight = n - x;
    int rowLeft = x - 1;
    int diaganolUpRight = min(n - x, n - y);
    int diaganolUpLeft = min(x - 1, n - y);
    int diaganolDownRight = min(n - x, y - 1);
    int diaganolDownLeft = min(x - 1, y - 1);
    
    //Declare the variables needed then loop through every obstacle in the given array
    int i, obstacleX, obstacleY, distanceX, distanceY;
    for(i = 0; i < k; i++){
    	//Declare variables needed
    	//*obstacleX* and *obstacleY* are the X and Y coordinates for the obstacle
    	//*distanceX* and *distanceY* are the distances from the Queen's X and Y coordinates to the obstacles X and Y coordinates
        obstacleX = obstacles[i][1];
        obstacleY = obstacles[i][0];
        distanceX = (x - obstacleX);
        distanceY = (y - obstacleY);

        //Now I need to check if the obstacle lays in the path of a potential queen move
        //If it does lay within the potential path I check if the obstacle obstructs the current path in that direction
        //Obstacles farther than a closer obstacle have no impact on the movement in that direction because the closer obstacle already blocks that direction

        //I first check for *distanceX* being equal to zero
        //If it is equal to zero then that means the obstacle is within the vertical movement path of the Queen
        if(distanceX == 0){
            if(distanceY < 0){
                if(abs(distanceY) <= columnUp){
                    columnUp = abs(distanceY) - 1;
                }
            }
            else{
                if(abs(distanceY) <= columnDown){
                    columnDown = abs(distanceY) - 1;
                }
            }
        }
        
        //Next I check for *distanceY* being equal to zero
        //If it is equal to zero then that means the obstacle is within the horizontal movement path of the Queen
        else if(distanceY == 0){
            if(distanceX < 0){
                if(abs(distanceX) <= rowRight){
                    rowRight = abs(distanceX) - 1;
                }
            }
            else{
                if(abs(distanceX) <= rowLeft){
                    rowLeft = abs(distanceX) - 1;
                }
            }
        }
        
        //Last I check for the absoulte value of *distanceX* being equal to absoulte value of *distanceY*
        //If they are equal then that means the obstacle is within a diaganol of the Queen's movement path
        else if(abs(distanceX) == abs(distanceY)){
            if(distanceX < 0){
                if(distanceY < 0){
                    if(abs(distanceX) <= diaganolUpRight){
                        diaganolUpRight = abs(distanceX) - 1;
                    }
                }
                else{
                    if(abs(distanceX) <= diaganolDownRight){
                        diaganolDownRight = abs(distanceX) - 1;
                    }
                }
            }
            else{
                if(tempDy < 0){
                    if(abs(distanceX) <= diaganolUpLeft){
                        diaganolUpLeft = abs(distanceX) - 1;
                    }
                }
                else{
                    if(abs(distanceX) <= diaganolDownLeft){
                        diaganolDownLeft = abs(distanceX) - 1;
                    }
                }
            }
        }
    }

    //I then return the sum of the possible movements in every direction
    return columnUp + columnDown + rowRight + rowLeft + diaganolUpLeft + diaganolUpRight + diaganolDownLeft + diaganolDownRight;
}