#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include"queue.h"


//function for the encryption

void encrypt(circularQueue *q,char *text,int key){                    
    for(int i=0;text[i]!='\0';i++){
        if(isalpha(text[i])){
            int isLower = islower(text[i]);  //To check the lowercase 

            text[i] = toupper(text[i]);
            int index = getindex(q, text[i]);
            int shiftindex = (index + key + queue_size) % queue_size;  
            text[i] = getinchar(q, shiftindex);

            if (isLower) {
                text[i] = tolower(text[i]);  //convert to lowercase if original is lowercase
            }
        }
    }
}


//function for the decryption

void decrypt(circularQueue *q,char *text,int key){      
    for(int i=0;text[i]!='\0';i++){
        if(isalpha(text[i])){
            int isLower = islower(text[i]);  

            text[i] = toupper(text[i]);
            int index = getindex(q, text[i]);
            int shiftindex = (index - key + queue_size) % queue_size;  //can handle negative values
            text[i] = getinchar(q, shiftindex);

            if (isLower) {
                text[i] = tolower(text[i]);  
            }
        }
    }
}


int main(){
    return 0;
}