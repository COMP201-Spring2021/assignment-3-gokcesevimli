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
    int looprow;
    int loopcol;

    


    printf("\n");
    sizeOfGrid = rows * cols;
    Initial_Active_Cases = sizeOfGrid * 5/100;
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   printf("Initial active cases %d, ", Initial_Active_Cases);
   int u=0;

   int arr[rows][cols];
   int sizeOfArray = sizeof arr/ sizeof arr[0];
  
   for(looprow = 0; looprow < rows; looprow++){
     
      for(loopcol = 0; loopcol < cols; loopcol++){
      int randomnumber = rand() % 2;
      if(randomnumber==0 && u<Initial_Active_Cases){
            arr[looprow][loopcol] = 0;
            u++;
      }else{
             arr[looprow][loopcol] = 1;
        }

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
  
    return 0;
}




