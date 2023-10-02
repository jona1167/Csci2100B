#include <stdio.h>

void swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


int main(){
    int t,n,m,check;
    int a[100001],b[100001];//input a b array
    int temp[501];
    scanf("%d", &t);//input value  

    for(int i = 0; i < t; i++ ) {
    check=0;
      scanf("%d", &n);//input value
        for(int j=0;j<n;j++){
            scanf("%d", &a[j]);//input value
        }
        for(int j=0;j<n;j++){
            scanf("%d", &b[j]);//input value
        }

        for(int j=0;j<n-1;j++){
            if(b[j]!=b[j+1]){
                check=-1;
                break;
                
            }
        }
        

    int min;
 
   for (int k = 0; k < n-1; k++)
    {
        if(check!=-1){
            break;
        }

        min = k;
        for (int j = k+1; j < n; j++){
          if (a[j]<a[min])
            min = j;
  
        }
        
                swap(&a[min], &a[k]);//swap the str array
                swap(&b[min], &b[k]);//swap the str array
        
    }


        for(int j=0;j<n-1;j++){
            //printf("%d ",a[j]);
            if(a[j]>a[j+1]){
                //printf("No");
                temp[i]=-1;
                break;
            }
                
            else {
                temp[i]++;
                //printf("Yes");
            }
                
        }
        
    }
    for(int i = 0; i < t; i++ ) {//set all the value
        if(temp[i]==-1){
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
        
       
    }
    return 0;
}