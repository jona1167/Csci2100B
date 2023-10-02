#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){

    int error=-1;//check error
    int change=0,x=0;//change is to count the bracket 
    char* input=malloc(sizeof(char)*1000001);
    char* stack=malloc(sizeof(char)*1000001);
    
    stack[0]='@';
    scanf("%s",input);//take the input
    

    for(int i=0;i<strlen(input);i++){//check all the variable in the string
        if(strlen(input)%2!=0){//fast check
                error=0;
                break;
        }


        if(input[i]=='('|| input[i]=='{'||input[i]=='['||input[i]=='<'){//stack if ( push)
            stack[x]=input[i];
            x++;
        }
            
       
        else{
        //if(input[i]==')'||input[i]=='}'||input[i]==']'||input[i]=='>'){//if) pop
            if(stack[0]=='@'){//empty then break
                error=0;
                break;
            }else{               
                if(stack[x-1]==input[i]-1||stack[x-1]==input[i]-2){                   //for()        
                
                x--;                 
                }
                else if(!(stack[x-1]==input[i]-2&&stack[x-1]==input[i]-1)){//change
                    change++;
                    
                    x--;
                }
                else{//for other special case
                    error=0;
                    break;
                }
                if(x==0)
                stack[x]='@';
            }                     
        }
        
            
    }
    free(input);
    if(x!=0)//if stack still have thing then error
        error=0;
     
    if(error==0){//error case
        printf("Impossible");

    }
    else{//display   
        printf("%d",change);
    }
    
    free(stack);
    return 0;
}