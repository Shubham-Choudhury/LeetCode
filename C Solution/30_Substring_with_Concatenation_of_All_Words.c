// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    char *temp;
    int slen = strlen(s);
    int *pmark;
    int dictlen=0, count=0;
    char *p=NULL;
    int regwordlen = strlen(words[0]);
    dictlen=regwordlen*wordsSize;
    temp = calloc((dictlen+1),sizeof(char));
        
    pmark = calloc((slen+1),sizeof(int));
      
    for(int i=0; i<= slen-dictlen;){
        strncpy(temp, &s[i],dictlen);
        for(int j=0; j< wordsSize; j++){
     
            for(int k=0; k<dictlen ;){
                p=strstr(temp+k, words[j]);
                if(p!= NULL && ((p-temp) % regwordlen)==0)//poistion check
                    break;
                else if(NULL!=p){
                    k=p-temp+1;
                    p=NULL;
                }else if(NULL==p)
                    goto nextseg;
                
            }
            
            if(NULL!=p )
                memset(p, '.', regwordlen);
            else
                goto nextseg;
            
        }
                
        if(slen!=0 && dictlen!=0)
            pmark[count++]=i;
nextseg:
        i++;
    }
   
    *returnSize = count;
    
    return pmark;
}

int main(){
    char *s = "barfoothefoobarman";
    char *words[] = {"foo","bar"};
    int wordsSize = 2;
    int returnSize;
    int *p;
    p = findSubstring(s, words, wordsSize, &returnSize);
    for(int i=0; i<returnSize; i++)
        printf("%d ", p[i]);
    return 0;
}