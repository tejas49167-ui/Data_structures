#include <stdio.h>
#include <string.h> 

char mainStr[50], pattern[20], replaceStr[20], resultStr[50];
int matchFlag = 0 ; 

void stringmatch() {
    int mainIdx = 0, tempIdx = 0, patIdx = 0, resIdx = 0; 

    while (mainStr[mainIdx] != '\0') {
        if (mainStr[tempIdx] == pattern[patIdx]) {
            patIdx++;
            tempIdx++;
            if (pattern[patIdx] == '\0') {  // Pattern matched
                matchFlag = 1;
                for (int repIdx = 0; replaceStr[repIdx] != '\0'; repIdx++) {
                    resultStr[resIdx++] = replaceStr[repIdx];  // Copy replacement
                }
               patIdx = 0; 
               mainIdx = tempIdx ; 
            }
            
           
        } 
        else {
            resultStr[resIdx++] = mainStr[mainIdx];
            mainIdx++;
            tempIdx = mainIdx;
            patIdx = 0;
        }
    }
    resultStr[resIdx] = '\0';
}

void main() {
    printf("Enter the main string: ");
    scanf("%s",mainStr);          // VTU expects gets() // but get is not there is new version
    printf("\nEnter the pattern string: ");
    scanf("%s",pattern);
    printf("\nEnter the replacement string: ");
    scanf("%s",replaceStr);

    printf("\nThe string before pattern match is:\n%s", mainStr);

    stringmatch();

    if (matchFlag == 1)
        printf("\nThe string after pattern match and replace is:\n%s", resultStr);
    else
        printf("\nPattern string is not found");
}
