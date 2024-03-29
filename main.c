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
  int Social_Distancing;
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

    char *m;
    int w;
    for(w=1; w<5;w++){ //4 arguments can be given by the user.
      long conv = strtol(argv[w], &m, 10); //takes the given argument and convert it to long.
      if(w==1){
        rows=conv; //first argument is Word size, which is equal to number of rows.
      }else if(w==2){
        Social_Distancing=conv; //second argument is the social distancing percentage.
      }else if(w==3){
        Simulation_Length=conv; //third argument is the simulation length.
      }else{
        t=conv; //fourth argument is the random seed.
      }
    }

    k = 1;
    b = 0; //array
    printf("\n");

    sizeOfGrid = rows * cols;
    Initial_Active_Cases = sizeOfGrid * 5/100;

   /* Intializes random number generator */
   srand(t);

   int u=0;

   int arr[rows][cols];
   int kzck[rows][cols];
   int looprow;
   int loopcol;
   for(looprow = 0; looprow < rows; looprow++){
      for(loopcol = 0; loopcol < cols; loopcol++){
            arr[looprow][loopcol] = 1; //initializing whole grid array with 1's.
            kzck[looprow][loopcol] =-1; //keeps the number of cycles.
        
    }
   }
   
   int start_count = 0;
   while(start_count<Initial_Active_Cases){ //goes until it reaches the number of initial active cases.
       int row_index = rand()%rows; //randomly takes the index of the row.
       int col_index = rand()%cols; //randomly takes the index of column.
       if(arr[row_index][col_index]==1){ //if the randomly chosen person is healthy  
           arr[row_index][col_index]=0; //making the person sick
           kzck[row_index][col_index]=0;//the number of cycles which the person encounters.
           start_count++;
       }
   }

    FILE *file = fopen("file.txt", "w"); //opening file.txt file in write mode.
   if (file == NULL){
    printf("Error opening file!\n");
    exit(1);
   }

    //prints the content of whole array.  
    
    int p,r; 
    for(p = 0; p<rows; p++) { 
        fprintf(file, "\n"); 
        for(r = 0; r<cols; r++) { 
            if(arr[p][r]==0){
                fprintf(file, "*\t"); //* indicates the active case.
            }
            else if(arr[p][r]==1){
                fprintf(file, "1\t"); //1 indicates the healthy people.
            }
            else if(arr[p][r]==-1){
                fprintf(file, "0\t"); //0 indicates the dead people.
            }
            else if(arr[p][r]==2){ //2 indicates the people who was sick and healthy now.
               fprintf(file, "1\t"); // 1 indicates the healthy people.
            }
            
        } 
    }
    fprintf(file, "\n");
   
   int simulation_cycle;
   for(simulation_cycle=0;simulation_cycle<Simulation_Length;simulation_cycle++){
       
       //Spreading the virus
       int f;
       int h;
        for(f=0;f<rows;f++){
           for(h=0;h<cols;h++){
               if(arr[f][h]==0){ //if the person is sick
                   if(kzck[f][h]==4){ //if 4 cycles are passed
                       int dead = rand()%100;
                       if(dead<3){ //indicates the fatality rate 3/100.
                          arr[f][h]=-1; //-1 indicates the dead person
                       }else{
                          arr[f][h]=2; //2 indicates the people who was infected before and healty now.(Recover_Rate)
                       }
                   }else{
                        kzck[f][h]++; //incrementing the number of cycles encountered.
                   }
                  
               }
               
           }
        }
       int g;
       int y;
       for(g=0;g<rows;g++){
           for(y=0;y<cols;y++){
                if(arr[g][y]==0 & kzck[g][y]>0){ //if the person is sick
                    //spreading virus to left neighbour.
                    if(g!=0&&arr[g-1][y]==1){ 
                        int isInfected = rand()%100;
                        if(isInfected<Social_Distancing){ //indicates the social distancing rate, which is given as argument.
                            arr[g-1][y]=0; //spreading the virus.
                            kzck[g-1][y]=0;//the cyle of the new sick person just begins.
                        }
                        
                    }
		    //spreading the virus to right neighbour.
                    if(g!=rows-1&&arr[g+1][y]==1){
                        int isInfected = rand()%100;
                        if(isInfected<Social_Distancing){
                            arr[g+1][y]=0;
                            kzck[g+1][y]=0;
                        }
                        
                    }
		   //spreading the virus to above neighbour.
                    if(y!=0&&arr[g][y-1]==1){
                        int isInfected = rand()%100;
                        if(isInfected<Social_Distancing){
                            arr[g][y-1]=0; 
                            kzck[g][y-1]=0;
                        }
                        
                    }
		    //spreading the virus to below neighbour.
                    if(y!=cols-1&&arr[g][y+1]==1){
                        int isInfected = rand()%100;
                        if(isInfected<Social_Distancing){
                            arr[g][y+1]=0;
                            kzck[g][y+1]=0;
                        }
                        
                    }
                    
                }
            
               
           }
       }
           
     	//printing the content of whole array according to its correct contents 1,0 and *.
        for(p = 0; p<rows; p++) { 
            fprintf(file, "\n"); 
            for(r = 0; r<cols; r++) { 
                if(arr[p][r]==0){
                    fprintf(file, "*\t"); //* indicates the active case 
                }
                else if(arr[p][r]==1){
                    fprintf(file, "1\t"); // 1 indicates the healthy people
                }
                else if(arr[p][r]==-1){
                    fprintf(file, "0\t"); //0 indicates the dead people
                }
                else if(arr[p][r]==2){ //2 indicates the people who is encountered with this illness and healthy now.
                   fprintf(file, "1\t"); //so it is showed as 1, which shows healthy people.
                }
                
            } 
        }
        fprintf(file, "\n");
    }
    fclose(file); //closing the file.txt file
    return 0;
} 
                      
                        
                          
                        
                        
                    
                   
                        
                            
                    
             







    








    




