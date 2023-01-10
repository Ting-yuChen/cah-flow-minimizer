#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"namelist.h" 
#define N 100
#define NAMELENGTH 25

/*
 * Graph is the graph representation in adjacency matrix
 */
float Graph[N][N];



typedef  char Name[NAMELENGTH];
 Name *namelst;




 // a pointer to an unknown number of arrays


 

 
 
int USER_AMOUNT, CASH_FLOW;
int u, v;
float w,tempnetcash=0,BIG,SMALL,TEMPBIG,TEMPSMALL,DIFFERENCE,fabsSMALL;
int i=0, j,k,SMALLADRESS,BIGADRESS;






void InputGraph(int b){
   
int USER_AMOUNT=b;


    

    for(k=USER_AMOUNT-1;k>0;k--)
    {
CASH_FLOW+=2*k;
    }
 
    // Reset graph
    for(i = 0; i < USER_AMOUNT; ++i)
        for(j = 0; j < USER_AMOUNT; ++j)
            Graph[i][j] = 0;
 
    // Input Graph
    printf("Enter (user flow money):\n");
    printf("Column 1: borrower(User Number)\n");
    printf("Column 2: lender(User Number)\n");
    printf("Column 3: money\n");
    for(i = 0; i < CASH_FLOW; ++i){
        scanf("%d%d%f", &u, &v, &w);
        Graph[u][v]-=w;
        Graph[v][u]+=w;
    }

}
 
void PrintGraph(){
    // Print the current Graph
    printf("\n");
    printf("Graph:\n");
   for(i=0;i<USER_AMOUNT;i++)
   {
    printf("\t%s",namelst[i]);
   }
   printf("\n");

    for(i = 0; i < USER_AMOUNT; ++i)
    {
        printf("%s\t",namelst[i]);
    {
        for(j = 0; j < USER_AMOUNT; ++j)
            printf("%.3f\t",Graph[i][j]);
        printf("\n");
    }
    }
    printf("\n");
}
 
int main(){
 

    printf("Cash_Flow_Minimizer:\n");
    printf("============================\n\n");
    printf("Please enter user amount: ");
    scanf("%d",&USER_AMOUNT);
namelst=makenamelist(USER_AMOUNT,namelst);


    InputGraph(USER_AMOUNT);
    
    
  

    
    
    
    float NetCash[USER_AMOUNT];
    memset(NetCash, 0, sizeof(NetCash));

    for(i=0;i<USER_AMOUNT;i++)
    {
        for(j=0;j<USER_AMOUNT;j++)
        {
            NetCash[i]+=Graph[i][j];
        }
         
    }
     PrintGraph();

    for(i=0;i<USER_AMOUNT;i++)
    {
        printf("Netcash for %s: %.3f\n",namelst[i],NetCash[i]);
    }
    BIG=NetCash[0];
    SMALL=NetCash[0];
  
    
   
  
    do
    {
          for(i=0;i<USER_AMOUNT;i++)
        {if(SMALL>NetCash[i])
            {SMALL=NetCash[i];
            SMALLADRESS=i;}
        }
        fabsSMALL=fabs(SMALL);
    for(j=0;j<USER_AMOUNT;j++)
        {if(BIG<NetCash[j])
            {BIG=NetCash[j];
            BIGADRESS=j;}
        }
    DIFFERENCE=BIG-fabsSMALL;

    if(DIFFERENCE>0)
    {
        printf("%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],fabsSMALL);
       
        NetCash[BIGADRESS]=DIFFERENCE;
         NetCash[SMALLADRESS]=0;
        SMALL=0;
        BIG=0;
    }

   else if(DIFFERENCE<0)
    {
        printf("%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],BIG);
        NetCash[SMALLADRESS]=DIFFERENCE;
        NetCash[BIGADRESS]=0;
        BIG=0;
        SMALL=0;
    }
    else if(DIFFERENCE==0)
    {printf("%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],BIG);
    NetCash[SMALLADRESS]=0;
    NetCash[BIGADRESS]=0;
    }
    } while (NetCash[SMALLADRESS]!=0||NetCash[BIGADRESS]!=0);
    

   
 
    return 0;
}