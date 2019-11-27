#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct {
    char id;
    int deadline;
    int profit;
 
}Job;
 
int compareJob(const void *a, const void *b){
    return ((Job*)a)->profit - ((Job*)a)->profit;
}
 
void bestJob(Job jobs[],int sizeOfJobs){
    char jobsToDo[5]= {'\0'}; 
    
    int i, k;
 
    for(i=0; i< sizeOfJobs; i++){
            k= jobs[i].deadline-1;
        while(jobsToDo[k] != '\0' && k >= 0){
            k--;
        }
        if(k != -1)
            jobsToDo[k]= jobs[i].id;
    }
 
    printf("Best order and jobs to do is \n");
    k=0;
    while(jobsToDo[k] != '\0'){
            printf("%c ",jobsToDo[k]);
            k++;
        }
}
 
void display(Job jobs[],int n){
    int i;
    printf("Job Id: \t");
    for(i=0; i<n; i++){
        printf("%c \t",jobs[i].id);
    }
    printf("\n");
 
    printf("Job Deadline: \t");
    for(i=0; i<n; i++){
        printf("%d \t",jobs[i].deadline);
    }
    printf("\n");
 
    printf("Job Profit: \t");
    for(i=0; i<n; i++){
         printf("%d \t",jobs[i].profit);
    }
    printf("\n");
}
int main()
{
    Job jobs[]=  {{'w', 1, 19}, {'v', 2, 100}, {'x', 2, 27},
                   {'y', 1, 25}, {'z', 3, 15}};
    display(jobs,5);
 
    qsort(jobs,5,sizeof(jobs[0]),compareJob);
 
    bestJob(jobs,5);
    return 0;
}

