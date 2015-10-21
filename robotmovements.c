//
//  https://www.codeeval.com/open_challenges/56/
//  robotmovements
//
//  Created by Stephan Warren on 12/25/14.
//  Copyright (c) 2014 Stephan Warren. All rights reserved.
//

/*

 CHALLENGE DESCRIPTION:
 
 A robot is located at the top-left corner of a 4x4 grid. The robot can move either up, down, left, or right, but can not visit the same spot twice. The robot is trying to reach the bottom-right corner of the grid.
 
 INPUT SAMPLE:
 
 There is no input for this program.
 
 OUTPUT SAMPLE:
 
 Print out the unique number of ways the robot can reach its destination. (The number should be printed as an integer whole number eg. if the answer is 10 (its not !!), print out 10, not 10.0 or 10.00 etc)
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define FIELDEDGES 2
#define MONKEYGRID 4
#define WHOLEFIELD (MONKEYGRID + FIELDEDGES)


static short solutions = 0;


char ** newGrid(char ** oldgrid)
{
//    if(oldgrid) {
//        printf("Old Grid:\n");
//        for(char i = 0; i < WHOLEFIELD; i++) {
//            for(char j = 0; j < WHOLEFIELD; j++) {
//                printf(" %2d", (int) oldgrid[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//    }
    char ** grid = (char **) malloc(sizeof(char *) * WHOLEFIELD);
    for(char i = 0; i < WHOLEFIELD; i++) {
        grid[i] = (char *) malloc(sizeof(char) * WHOLEFIELD);
        for(char j = 0; j < WHOLEFIELD; j++) {
            if(oldgrid == NULL) {
                grid[i][j] = (((i == 0) || (i == WHOLEFIELD-1)) || ((j == 0) || (j == WHOLEFIELD-1))) ? 1 : 0;
            }
            else {
                grid[i][j] = oldgrid[i][j];
            }
        }
    }
   // grid[1][1] = 1;
//    
//    printf("Made Grid:\n");
//    for(char i = 0; i < WHOLEFIELD; i++) {
//        for(char j = 0; j < WHOLEFIELD; j++) {
//            printf(" %2d", (int) grid[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    
    return(grid);
}



void recurse(char ** grid, char x, char y, char cnt)
{
    typedef struct { char x; char y;} dirs_t;
    
     dirs_t dirs [4] = {
        { 1, 0},
        { 0, 1},
        {-1, 0},
        { 0,-1}
     };
    
    
//    printf("Enter R: x = %d, y = %d, cnt = %d\n", x, y, cnt);
    grid[x][y] = cnt;
    cnt++;
    if((x == MONKEYGRID) && (y == MONKEYGRID)) {
        solutions++;
//        printf("SOLUTION #%d:\n", solutions);
//        for(char i = 1; i <= MONKEYGRID; i++) {
//            for(char j = 1; j <= MONKEYGRID; j++) {
//                printf(" %2d", grid[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
    }
    else {
        
        for(char i = 0; i < 4; i++) {
            if(grid[x + dirs[i].x][y + dirs[i].y] == 0) {
//                printf("recurse\n");
                recurse(newGrid(grid), x+dirs[i].x, y+dirs[i].y, cnt);
            }
//            else {
//                printf("no recurse\n");
//            }
        }
        for(char i = 0; i < WHOLEFIELD; i++) {
            if(grid[i])free(grid[i]);
        }
        free(grid);
    }
   // printf("Unexpected landing spot\n");
}




int main(int argc, const char * argv[]) {
    // insert code here...

    char ** grid = newGrid(NULL);
    recurse(grid, 1, 1, 1);
    // skip freeing a this will occur at termination
    printf("%d\n", solutions);
    
    return 0;
}
