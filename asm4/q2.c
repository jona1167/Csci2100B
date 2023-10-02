#include <stdio.h>
 int a[1001];
int main(){
    
    int n,m,num1,num2,c;
    scanf("%d %d",&n,&m);//get
    


    for(int i=0;i<m;i++){
       scanf("%d %d",&num1,&num2);//get
       a[num1]=1;
       a[num2]=1;
    }

   
    for(int i=1;i<n+1;i++){
      if(a[i]==0){ //find the empty one
        c=i;
        break;
      }
          
    }
    printf("%d\n",n-1);
    for(int i=1;i<n+1;i++){//display
        if(i!=c){
            printf("%d %d\n",c,i);
        }
    }
    

    
    return 0;
}
