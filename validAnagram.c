#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isAnagram(char* s, char* t);

int main(){
    // char *s = "anagram";
    // char *t = "nagaram";
    bool answer;

    // char t = "car";
    // char s = "rat";
    char *t = "ab";
    char *s = "a";

    answer = isAnagram(s, t);
    printf("%d", answer);
}

bool isAnagram(char* s, char* t){
    int sLetterCount[26] = {0}, tLetterCount[26] = {0};

    for(;*s != '\0'; s++){
        sLetterCount[*s - 'a']++;
    }
    for(;*t != '\0'; t++){
        tLetterCount[*t - 'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(sLetterCount[i] != tLetterCount[i])
            return false;
    }
    return true;
    
}