#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 void substr( char   * dest, const   char * src, unsigned int start, unsigned int cnt) {
   strncpy(dest, src + start, cnt);
   dest[cnt] =   0 ;
 }
 long long chash(char s[]){
     int m=1e9+7;
     long long hash=0;
     for(int i=0;i<strlen(s);i++){
         hash=((hash+(s[i]-'a'+1))*769)%m;
        
     }
     return hash;
 }
int main(){
    int m=1e9+7;
    int nt=0,flag=0;
    char temp[1000001];
    long long num[2];
    char check[1000001]="\0";//create a empty string 
    int alph[26];
    
    int min[6];
    memset(alph, 0, sizeof alph);
    int max=0,index=0;

    char **str;//create a string array
    str = malloc(2 * sizeof(char*));
    for (int i = 0; i < 2; i++)
    str[i] = malloc( 1000001* sizeof(char));

    char **strck;//create a string array
    strck = malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; i++)
    strck[i] = malloc( 1000001* sizeof(char));

    scanf("%s",strck[0]);//take the input
    scanf("%s",strck[1]);//take the input
    scanf("%s",strck[2]);//take the input
    
    
    strcat(check,strck[0]);   
    strcpy(str[0],strck[1]);
    strcpy(str[1],strck[2]);


    for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            //printf("\t%s\t",temp);
            //printf("\t%d\t\n",num[0],temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            //printf("\t%s\t",temp);
            //printf("\t%d\t\n",num[1]);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[0]=strlen(check);
//printf("\n\n\n\n%s",check);
//printf("%d\n",min[0]);//display

check[0]='\0';
strcat(check,strck[0]);  
for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[1]=strlen(check);
    //printf("%s",check);
    //printf("%d\n",min[1]);//display
    


    check[0]='\0';  
    strcat(check,strck[1]);   
    strcpy(str[0],strck[0]);
    strcpy(str[1],strck[2]);


    for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[2]=strlen(check);
//printf("%s",check);
//printf("%d\n",min[2]);//display

check[0]='\0';
strcat(check,strck[1]); 
for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[3]=strlen(check);
    //printf("%s",check);
    //printf("%d\n",min[3]);//display



check[0]='\0';  
    strcat(check,strck[2]);   
    strcpy(str[0],strck[0]);
    strcpy(str[1],strck[1]);


    for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[4]=strlen(check);
//printf("%s",check);
//printf("%d\n",min[4]);//display

check[0]='\0';
    strcat(check,strck[2]);   
for(int i=0;i<2;i++){//input only three line  
        memset(alph, -1, sizeof alph);
        nt=0;
        flag=0;
        if(strstr(check,str[i]) == NULL){//if after check the check string not cointain the input string then strcat                             
        for(int j=strlen(str[i])-1;j>0;j--){//hash the character in check
            substr(temp, str[i], 0 ,j);
            num[0]=chash(temp);
            substr(temp, check, strlen(check)-j ,j);
            num[1]=chash(temp);
            if(num[0]==num[1]){
                nt=j;
                flag=1;
                break;
            }            
        }     
        if(flag==0){
            substr(temp, str[i], 0 , strlen(str[i]) );
            strcat(check,temp);
        }
        if(flag==1){
          substr(temp, str[i], nt , strlen(str[i])-nt );
            strcat(check,temp);           
        }
        }
    }
    min[5]=strlen(check);
    //printf("%s",check);
    //printf("%d\n",min[5]);//display
    int ans;
    ans=min[0];
    for(int i=1;i<6;i++){
        if(ans>min[i])
        ans=min[i];
    }
    printf("%d",ans);
    
    return 0;
}
