#include <stdio.h>
#include<string.h>

int main()
{
    
    int n,num;
    int check = 0;
    int a[10001],b[10001];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d",&n);//get number
    for(int i=2;i<n+1;i++){
        scanf("%d",&num);//input value
        a[i]=num;
        b[num]+=1;
    }
    
    for(int j=1;j<n+1;j++){//set the value to some useless value
        if(b[j]==0){
            b[j]=-1;
        }
    }

    for(int j=2;j<n+1;j++){
        if(b[j]>0){ 
            b[a[j]]=b[a[j]]-1;
        }
    }
    for(int k=1;k<n+1;k++){
        if(b[k]!=-1&&b[k]<=2){
        check++;
        }
    }


    //display answer
    if(b[1]!=-10&&check==0) {
        printf("Yes");
    }
    else 
        printf("No");
    return 0;
}