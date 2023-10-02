#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,m,ans=0,max;
    int check=0;//for checking is the queue still have buyers
    scanf("%d %d",&n,&m);//get n m 

    int* queue=malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {     
        scanf("%d",&queue[i]);     //get the queue
    } 
    ans=n-1;//for first round
    do{
    for (int i = 0; i < n; i++) {     
        queue[i]-=m;     //buyers minus the ticket they can buy
    } 
    
        for (int i = n-1; i > -1; i--) {     
            if(queue[i]>0){//break it if still have buyers buy
                check=0;
                ans=i;
                break;
            }
            if(queue[n-1]<=0)
                check=1;
        } 
    
    
     
    }while(check==0);

    
    printf("%d ", ans+1);   
    return 0;
}