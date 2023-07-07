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
    // char *t = "ab";
    // char *s = "a";

    answer = isAnagram(s, t);
    printf("%d", answer);
}

bool isAnagram(char* s, char* t){
    int sLetterCount[26] = {0}, tLetterCount[26] = {0};

    for(;*s != '\0' || *t != '\0'; s++){
        if(*t == '\0' || *s == '\0')
            return false;
        
        sLetterCount[*s - 'a']++;
        tLetterCount[*t - 'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(sLetterCount[i] != tLetterCount[i])
            return false;
    }
    return true;
    
}