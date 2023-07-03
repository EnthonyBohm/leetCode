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
    char* startAdress = t;
    bool found;


    if (sizeof(s) != sizeof(t))
        return false;

    for(; *s != '\0'; s++){
        found = false;
        for(t = startAdress; *t != '\0'; t++){
            if(*s == *t){
                found = true;
                *t = '_';
                break;
            }
        }
        if (found != true)
            return false;
    }
    return true;
}