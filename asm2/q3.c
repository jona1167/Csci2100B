#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char **str, int num1,int num2,int pos[]){
    char temp[1000001];
    strcpy(temp,str[num1]);
    strcpy(str[num1],str[num2]);
    strcpy(str[num2],temp);
    int tempp;
    tempp =pos[num1];
    pos[num1]=pos[num2];
    pos[num2]=tempp;
}

void bubbleSortass(char **str, int n,int d,int pos[]){
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    for (j = 0; j < n-i-1; j++)
        if (str[j][d]> str[j+1][d])
            swap(str,j+1,j,pos); 
}
void bubbleSortdes(char **str, int n,int d,int pos[]){
    int i, j;
    for (i = 0; i < n-1; i++)    
    for (j = 0; j < n-i-1; j++){
        
        if (str[j][d]< str[j+1][d]){
            swap(str,j+1,j,pos); 

        }
    }
}

void csort(int n, char **str, int d,int m,int pos[]){

if((d+1)%2==0){
    bubbleSortdes(str,n,d,pos);
}
else{ 
 bubbleSortass(str,n,d,pos);
}
}
void oddcsort(int n, char **str, int d,int m,int pos[]){
if((d+1)%2!=0){
 bubbleSortass(str,n,d,pos);
}
else{
    bubbleSortdes(str,n,d,pos);
}

}

void radixsort(int n, char **str,int D,int *pos){//D is dig
if(D%2==0){
for (int i = D-1; i >=0; i--){
 csort(n, str,i,D,pos);
 }
}else{
for (int i = D-1; i >=0; i--){
 oddcsort(n, str,i,D,pos);
 }

}

}


int main(){
    int n,m;
    char temp[1000001];
    scanf("%d %d", &n,&m);//input value  
    char **str;//create a string array
    str = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    str[i] = malloc( m* sizeof(char));
    
    int *pos = malloc( sizeof(int)*n);
   
    for(int i = 0; i < n; i++ ) {
        temp[0] = '\0';
        scanf("%s",str[i]);
        pos[i]=i+1;
    }

    radixsort( n, str,m,pos);






for(int i=0;i<n;i++){
    printf("%d ",pos[i]);
}




free(str);
free(pos);

    return 0;
}