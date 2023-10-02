#include <stdio.h>
 
int main(){
    
    int n,t,num;
    int check;
    scanf("%d %d",&n,&t);//get
    int a[n+1];
    a[0]=-1;//no use

    for(int i=1;i<n;i++){
       scanf("%d",&num);
       a[i]=num;
    }

    int dir=1;
    for(int i=1;i<n;i++){
        dir+=a[dir];//finding the road
        if(dir==t){//yes 
            check=1;
            break;
        }
        else if(dir>t){//no
            check=0;
            break;
        }
    }


    if(check==1){
        printf("YES");
    }else{
        printf("NO");
    }
    

    
    return 0;
}
