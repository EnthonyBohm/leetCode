#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isAnagram(char* s, char* t);

int main(){
    char *s = "anagram";
    char *t = "nagaram";
    bool answer;

    // char t = "car";
    // char s = "rat";

    answer = isAnagram(s, t);
    printf("%d", answer);
}

bool isAnagram(char* s, char* t){
    int slen = strlen(s), tlen = strlen(t);
    char aux[slen];
    bool found;

    if (slen != tlen)
        return false;

    strcpy(aux, t);
    for(; *s != '\0'; s++){
        found = false;
        for(int i = 0; i < tlen; i++){
            if(*s == aux[i]){
                found = true;
                aux[i] = '_';
                break;
            }
        }
        if (found != true)
            return false;
    }
    return true;
}