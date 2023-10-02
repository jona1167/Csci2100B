#include<stdio.h>
#include<stdlib.h>

int main(){
	int t,n,num;
    int a[10001];

	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int check=-1;
		scanf("%d",&n);//get
		
		for(int j=0;j<n;j++){
			scanf("%d",&num);//get

            a[j]=num;
			if(a[j]==1 && check==-1){
				check=j;
			}
		}

		//store the position
        //printf("%d",check);
        if(a[0]==0||a[0]==1){
	    if(check!=-1){
			for(int j=0;j<check;j++){//case1
		        printf("%d ",j+1);

			}
			printf("%d ",n+1);
			for(int j=check+1;j<n+1;j++){//case2
			    printf("%d ",j);
			}
		}
		else{//nth do
			for(int j=0;j<n+1;j++){
			    printf("%d ",j+1);
			}	
		}
		}
		else
			printf("-1");//no path
        
	}
}