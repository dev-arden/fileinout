//
//  main.c
//  fileinout
//
//  Created by 이은비 on 04/12/2019.
//  Copyright © 2019 이은비. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define PASSWD_LEN            4

typedef struct {
   int building;
   int room;
   int cnt;
   char passwd[PASSWD_LEN+1];
   
   char *context;
} storage_t;

static storage_t** deliverySystem;          //deliverySystem
static int storedCnt = 0;               //number of cells occupied
static int systemSize[2] = {0, 0};        //row/column of the delivery system
static char masterPassword[PASSWD_LEN+1];   //master password


int main(void)
{
    
    int i;
    int j;
    int x,y;
    FILE *fp;
    
    //this makes deliverySystem dimension array (like delivery box)
    fp   = fopen( "sample.txt", "r");
    fscanf( fp, "%d %d", &systemSize[0], &systemSize[1]);

    deliverySystem = (storage_t**)malloc(sizeof(storage_t*)*systemSize[1]);
    
    /*
     int **A;
     A = (int**)
     
     
     */
    for(i=0;i<systemSize[0];i++)
    {
        deliverySystem[i] = (storage_t*)malloc(sizeof(storage_t)*systemSize[1]);
    }
    
    //this sets masterPassword
    fscanf( fp, "%s", masterPassword);
    
    while( !feof( fp ) ) // if file is available
    {
        //this is about delivery information
        //ex: 0 0 3 103 1234 noPassword
        //from building number to passwd
        fscanf( fp, "%d %d", &x, &y);//row, column
        fscanf( fp, "%d %d %s", &deliverySystem[x][y].building, &deliverySystem[x][y].room, deliverySystem[x][y].passwd);//building, room, passwd
        //context
        deliverySystem[x][y].context = (char*)malloc(sizeof(char)*20);
        fscanf(fp,"%s",deliverySystem[x][y].context);
    }
    
//    for(i=0;i<systemSize[0];i++)
//    {
//        for(j=0;j<systemSize[1];j++)
//        {
//            printf("%d\n",deliverySystem[i][j].building);
//            printf("%d\n",deliverySystem[i][j].room);
//            printf("%s\n",deliverySystem[i][j].passwd);
//            printf("%s\n",deliverySystem[i][j].context);
//            //free(deliverySystem[i][j].context);
//        }
//    }
    
        
//    for(i=0;i<systemSize[0];i++)
//    {
//        for(j=0;j<systemSize[1];j++)
//        {
//            free(deliverySystem[i][j].context);
//        }
//    }
    
    
    
    for(i=0;i<systemSize[0];i++)
    {
        free(deliverySystem[i]);
    }
    free(deliverySystem);
    
    fclose(fp);
    return 0;
}
