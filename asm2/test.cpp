#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <iostream>
using std::string;
using namespace std;

void csort(int size, string a[], int k,int m,int *pos){
 
 string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];
    int *post = new int[size];
 

if((k+1)%2!=0){
   //printf("now odd");
    for (int i = 0; i <257; i++){
        c[i] = 0;
        
    }
   
for (int j = 0; j <size; j++){   
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            
    }
    
 for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
 }
for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        post[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1]=pos[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
        pos[l]=post[l];
    }

    
 
}
else{
   // printf("now even");
 for (int i = 0; i <257; i++){
        c[i] = 0;
        
    }
   
for (int j = 0; j <size; j++){   
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            
    }
    
 for (int f = 257-1; f >0; f--){
       c[f-1] += c[f];
    }
for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        post[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1]=pos[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
        
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
        pos[l]=post[l];
    }

}
// avold memory leak
    delete[] b;
    delete[] c;
    delete[] post;
}


void oddcsort(int size, string a[], int k,int m,int *pos){
 
 string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];
    int *post = new int[size];
 

if((k+1)%2==0){
   
//printf("now even");
 for (int i = 0; i <257; i++){
        c[i] = 0;
        
    }
   
for (int j = 0; j <size; j++){   
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            
    }
    
 for (int f = 257-1; f >0; f--){
       c[f-1] += c[f];
    }
for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        post[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1]=pos[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
        
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
        pos[l]=post[l];
    }
    
 
}
else{
    //printf("now odd");
    for (int i = 0; i <257; i++){
        c[i] = 0;
        
    }
   
for (int j = 0; j <size; j++){   
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            
    }
    
 for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
 }
for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        post[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1]=pos[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
        pos[l]=post[l];
    }
    

}
    delete[] b;
    delete[] c;
    delete[] post;
}


void radixSort(string a[], int n,int m,int pos[]){
if(m%2!=0){
for (int i = m-1; i >= 0; i--){
  //  printf("\nodd %d\n",i);
 csort(n, a, i,m,pos);
 }
}else{
for (int i = m-1; i >= 0; i--){
  // printf("\neven\n");
oddcsort(n, a, i,m,pos);
}
}

}





int main(void) {
    int n,m;
    scanf("%d %d", &n,&m);//input value  
    int pos[n];
    string data[n];
    for(int i = 0; i < n; i++ ) {
        cin>>data[i];
        pos[i]=i+1;
    }
    radixSort(data, n,m,pos);
    for(int i=0;i<n;i++){
        printf("%d",pos[i]);
        if(i!=n-1)
        printf(" ");
    }
    
    return 0;
}