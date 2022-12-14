// Link: https://leetcode.com/problems/odd-string-difference/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char * oddString(char ** words, int wordsSize){
    int* diff = (int*)calloc(wordsSize, sizeof(int));
    for(int i = 1; i < strlen(words[i]); i++){
        int diffMax = INT_MIN, diffMin = INT_MAX;
        for(int j = 0; j < wordsSize; j++){
            diff[j] = words[j][i]-words[j][i-1];
            if(diff[j]>diffMax) diffMax = diff[j];
            if(diff[j]<diffMin) diffMin = diff[j];
        }
        if(diffMax != diffMin){
		    /* means there is one different diff happen */
			/* try to find out which word by using diffMax and diffMin */
            int maxIdx = -1, minIdx = -1, maxCount = 0;
            for(int i = 0; i < wordsSize; i++){
                if(diff[i]==diffMax)
                {
                    maxIdx = i;
                    maxCount++;
                }
                else if(diff[i]==diffMin)
                    minIdx = i;
            }
            return maxCount==1? words[maxIdx] : words[minIdx];
        }
    }
    return "";
}

int main()
{
    char *words[] = {"adc","wzy","abc"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    char *result = oddString(words, wordsSize);
    printf("%s", result);
    return 0;
}