/* Assignment 3, Covid-19 social distancing effect simulation
 * The main aim of this assigment is getting familiar with dynamic arrays and heap management. 
 *  
 *  Please write your name and Student ID as comment below.
 *  Name and Surname:  Gökçe Sevimli             Student ID: 63992
 */



#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define Fatality_Rate 3/100;
#define Recover_Rate 97/100;

int main(int argc, char *argv[])
{
  double Social_Distancing;
  int Simulation_Length;
  int Random_seed;

  printf("Program name %s\n", argv[0]);

 if( argc == 5 ) {
        printf("The first argument supplied is %d\n", atoi(argv[1]));
        printf("The second argument supplied is %d\n", atoi(argv[2]));
        printf("The third argument supplied is %d\n", atoi(argv[3]));
        printf("The forth argument supplied is %d\n", atoi(argv[4]));
   }else if( argc > 5 ) {
     printf("Too many arguments supplied.\n");
   }
   else {
     printf("Expected 4 arguments but only %d argument passed.\n", argc-1);
   }



    int rows, cols, a, b, c, i, j, k, s, sizeOfGrid;
    int Initial_Active_Cases;
    
    time_t t;

    /* Input rows and columns from user */
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    char *m;
    int w;
    for(w=1; w<5;w++){
      long conv = strtol(argv[w], &m, 10);
      if(w==1){
        conv == rows;
        printf("Arg 1 is %ld", conv);
      }else if(w==2){
        conv == Social_Distancing;
        printf("Arg 1 is, %ld", conv);
      }else if(w==3){
        conv == Simulation_Length;
        printf("Arg 1 is %ld ", conv);
      }else{
        conv == Random_seed;
        printf("Arg 1 is %ld", conv);
      }
    }
  


    k = 1;
    b=0; //array
  

    


    printf("\n");
    sizeOfGrid = rows * cols;
    Initial_Active_Cases = sizeOfGrid * 5/100;
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   printf("Initial active cases %d, ", Initial_Active_Cases);
   int u=0;

   int arr[rows][cols];
   int kzck[rows][cols];
    int looprow;
   int loopcol;
   for(looprow = 0; looprow < rows; looprow++){
      for(loopcol = 0; loopcol < cols; loopcol++){
            arr[looprow][loopcol] = 1;
            kzck[looprow][loopcol] =-1;
        
    }
   }
   
   int start_count = 0;
   while(start_count<Initial_Active_Cases){
       int row_index = rand()%rows;
       int col_index = rand()%cols;
       if(arr[row_index][col_index]==1){
           arr[row_index][col_index]=0;
           kzck[row_index][col_index]=0;
           start_count++;
       }
   }
   
       int p,r; 
        for(p = 0; p<rows; p++) 
        { 
         printf("\n"); 
         for(r = 0; r<cols; r++) { 
           printf("%d\t", arr[p][r]); 
         } 
        }
        printf("\n");
   
   int simulation_cycle;
   for(simulation_cycle=0;simulation_cycle<10;simulation_cycle++){
       
       //Spread the virus
       int f;
       int h;
        for(f=0;f<rows;f++){
           for(h=0;h<cols;h++){
               if(arr[f][h]==0){
                   if(kzck[f][h]==4){
                       int dead = rand()%100;
                       if(dead<3){
                          arr[f][h]=-1; //-1 indicates the dead person
                       }else{
                           arr[f][h]=2; //2 indicates the people who was infected before and healty now.
                       }
                   }else{
                        kzck[f][h]++;
                   }
                  
               }
               
           }
        }
       int g;
       int y;
       for(g=0;g<rows;g++){
           for(y=0;y<cols;y++){
                if(arr[g][y]==0&kzck[g][y]>0){
                    if(g!=0&&arr[g-1][y]==1){
                        int isInfected = rand()%5;
                        if(isInfected<3){ //indicates the %60 rate
                            arr[g-1][y]=0;
                            kzck[g-1][y]=0;
                        }
                        
                    }
                    if(g!=rows-1&&arr[g+1][y]==1){
                        int isInfected = rand()%5;
                        if(isInfected<3){
                            arr[g+1][y]=0;
                            kzck[g+1][y]=0;
                        }
                        
                    }
                    if(y!=0&&arr[g][y-1]==1){
                        int isInfected = rand()%5;
                        if(isInfected<3){
                            arr[g][y-1]=0;
                            kzck[g][y-1]=0;
                        }
                        
                    }
                    if(y!=cols-1&&arr[g][y+1]==1){
                        int isInfected = rand()%5;
                        if(isInfected<3){
                            arr[g][y+1]=0;
                            kzck[g][y+1]=0;
                        }
                        
                    }
                    
                }
            
               
           }
       }
       
 
        for(p = 0; p<rows; p++) 
        { 
         printf("\n"); 
         for(r = 0; r<cols; r++) { 
           printf("%d\t", arr[p][r]); 
         } 
        }
        printf("\n");
        
        printf("*****************************************\n");
        //     for(p = 0; p<rows; p++) 
        // { 
        //  printf("\n"); 
        //  for(r = 0; r<cols; r++) { 
        //   printf("%d\t", kzck[p][r]); 
        //  } 
        // }
        // printf("\n\n\n");
       
       
       
   }
   


 

   for(p = 0; p<rows; p++) 
   { 
     printf("\n"); 
     for(r = 0; r<cols; r++) { 
       printf("%d\t", arr[p][r]); 
     } 
   }
   printf("\n");
  
    return 0;
} 







    




