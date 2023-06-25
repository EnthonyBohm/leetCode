int numJewelsInStones(char * jewels, char * stones){
  char *firstAdress;
  int numberJewels = 0;
  firstAdress = jewels;

  for(; *stones != '\0'; stones++){
    for (jewels = firstAdress; *jewels != '\0'; jewels++){
      if(*stones == *jewels)
        numberJewels++;
    }
  }
  return numberJewels;
}
