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
void clearline() 
{ for (int ch = 0; (ch != EOF) && (ch != '\n'); ch = fgetc(stdin)); }

char *namelist;
typedef  char Name[NAMELENGTH];




 // a pointer to an unknown number of arrays


 
/*
 * u is the current or source vertex
 * v is the next or destination vertex
 * w is the edge weight or path cost
 */
 
 
int USER_AMOUNT, CASH_FLOW;
int u, v;
float w,tempnetcash=0,BIG,SMALL,TEMPBIG,TEMPSMALL,DIFFERENCE,fabsSMALL;
int i=0, j,k,SMALLADRESS,BIGADRESS;
char* name;




/*char createnamelist(int USER_AMOUNT)
{
    int k;
    k=USER_AMOUNT;
    Name* namelist = ((Name*)malloc(k * NAMESIZE));

clearline();
    
for (i = 0; i < k; i++) {
    printf("User %d : ", i );
    fgets(namelist[i], NAMESIZE , stdin);
}

for(i=0;i<USER_AMOUNT;i++)
    {
        printf("User %d is %s \n",i,namelist[i]);
    }
;
}*/
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
     printf("Column 1: borrower\n");
    printf("Column 2: lender\n");
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
    for(i = 0; i < USER_AMOUNT; ++i){
        for(j = 0; j < USER_AMOUNT; ++j)
            printf("%.3f ", Graph[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
int main(){
 
 
    printf("Cash_Flow_Minimizer:\n");
    printf("============================\n\n");
    printf("Please enter user amount: ");
    scanf("%d",&USER_AMOUNT);


Name* namelst = ((Name*)malloc(USER_AMOUNT * NAMELENGTH));

clearline();
    
for (int i = 0; i < USER_AMOUNT; i++) {
    printf("Name %d :  ", i);
    fgets(namelst[i], NAMELENGTH , stdin);
}
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
        printf("%.3f\t",NetCash[i]);
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
        printf("\n%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],fabsSMALL);
       
        NetCash[BIGADRESS]=DIFFERENCE;
         NetCash[SMALLADRESS]=0;
        SMALL=0;
        BIG=0;
    }

   else if(DIFFERENCE<0)
    {
        printf("\n%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],BIG);
        NetCash[SMALLADRESS]=DIFFERENCE;
        NetCash[BIGADRESS]=0;
        BIG=0;
        SMALL=0;
    }
    else if(DIFFERENCE==0)
    {printf("\n%s should pay %s %f dollars\n",namelst[SMALLADRESS],namelst[BIGADRESS],BIG);
    NetCash[SMALLADRESS]=0;
    NetCash[BIGADRESS]=0;
    }
    } while (NetCash[SMALLADRESS]!=0||NetCash[BIGADRESS]!=0);
    

   
 
    return 0;
}














