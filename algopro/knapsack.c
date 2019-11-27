#include<stdio.h>

void knapsack(float a[],float b[],int);

int main()
{
        float v[10],w[10],r[10];
        int n,i,j,t;
        printf("How many Items are there : \t");
        scanf("%d",&n);
        printf("\nEnter %d Weights and their values ",n);
        for(i=0;i<n;i++)
        {
                scanf("%f%f",&w[i],&v[i]);
                r[i] = v[i]/w[i];
        }
        for(i=0;i<n;i++)
        {
                for(j=0;j<n-1;j++)
                {
                        if(r[j]<r[j+1])
                        {
                                t = v[j];
                                v[j] = v[j+1];
                                v[j+1] = t;

		         t = w[j];
                                w[j] = w[j+1];
                                w[j+1] = t;
                        }
                }
        }
        knapsack(v,w,n);
}

void knapsack(float v[],float w[],int n)
{
        int i=0,c;
        float sum=0;
        printf("\nEnter the total capacity of the Knapsack : ");
        scanf("%d",&c);
        while(c>0)
        {
                if(c>w[i])
                {
                        c = c-w[i];
                        sum = sum + v[i];
                        i++;
                }
                else
                {
                        float x = (float)c/(float)w[i];
                        sum = sum + (x*v[i]);
                        c = 0;
                }
        }
         printf("The Maximum Value accomodated is : %f",sum);
}



