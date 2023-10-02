#include <stdio.h>
 
int main(){
    
    int n,q;//input value
    int ans;//output
    scanf("%d %d",&n,&q);//get
    int a1[n],a2[q],result[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a1[i]);//get thte first line
    }
    for(int i=0;i<q;i++){
        scanf("%d",&a2[i]);//the second line
    }
    
    for(int i=0;i<q;i++){

        for(int f=0;f<n;f++){//compare the first
            if(a1[f]==a2[i]){
                result[i]=f+1;//store the index
                
                for(int d=f;d>0;d--){//delete 
                    a1[d]=a1[d-1];
                }
            a1[0]=a2[i];//put to the front
            /*
                for(int i=0;i<n;i++){
                    printf("%d ",a1[i]);
                }

                printf("\n");
            */

            break;
            }
        }
    }

    for(int i=0;i<q;i++){//display
        printf("%d ",result[i]);
    }
 
    return 0;
}
