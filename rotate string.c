#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool rotateString(char * s, char * goal){
    int slen=0, glen=0, flag=0;
    for (int i=0; s[i]!='\0'; i++) slen++;
    for (int i=0; goal[i]!='\0'; i++) glen++;
    if (slen!=glen) return false;
    char s1[1000];
    strcpy(s1, s);
    strcat(s,s1);
    for (int i=0; s[i]!='\0'; i++, flag=0) {
        for (int j=0, k=i; goal[j]!='\0' && s[k]==goal[j]; j++, k++) {
                flag++;
        }
        if (flag==slen) 
            return true;
    }
    return false;
}

int main() {
    char s[100]="abcdea";
    char goal[100]="cdeaab";
    printf("%d", rotateString(s,goal));
    return 0;
}
