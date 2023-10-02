#include <stdio.h>

void swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(){
    int n,m;
    int str[100001],pos[100001];//input string and position array
    int left[100001], right[100001];
    scanf("%d %d", &n, &m);//input value  
    
    for(int i = 1; i < n+1; i++ ) {//set all the value
        str[i] =i;
        pos[i] =i;
        left[i]=i;
        right[i]=i;
    }
    
    for(int i=0;i<m;i++){//loop m time
        
        
        int templ, tempr;//templ mean temp left which swap to left and tempr mean temp right the value be swapped
        scanf("%d", &templ);

        if( pos[templ] != 1 ) {//as in position one cannot swap
            tempr = str[pos[templ]-1];
            swap(&str[pos[templ]],&str[pos[tempr]]);//swap the str array
            swap(&pos[templ],&pos[tempr]);//both the position array
            if( pos[templ] < left[templ] ) {//compare to find out is it the leftmost or rightmost
                left[templ] = pos[templ];
            }
            if( pos[tempr] > right[tempr] ){
                right[tempr] = pos[tempr];
            }
        }
    }
    
    for(int i=1; i<n+1; i++) {
        printf("%d %d\n",left[i], right[i] );//display left and right
    }

    return 0;
}