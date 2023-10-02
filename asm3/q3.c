#include <stdio.h>
#include <string.h>
int main()
{
    
    int n,num,temp,check;
    int ans=1;//hva t least one ans
    int a[2001];
    memset(a, 0, sizeof(a));
    scanf("%d",&n);//get 

    for(int i=1;i<n+1;i++){
        scanf("%d",&num);//get input
        
        a[i]=num;//store in a
        
    }

    for(int i=1;i<n+1;i++){
        temp=1;//set to 1 every time
        check =i;
        /*do{
            temp++;
            check=a[check];

            //printf("temp:%d\n\n",temp);
        }while(a[check]!=1);*/

        while(a[check]!=-1){
            temp++;
	        check=a[check];
            
	 	    //printf("temp:%d\n\n",temp);
	    }

        if(ans<temp)
            ans=temp;
    }
 

    //display answer
    printf("%d",ans);
    return 0;
}