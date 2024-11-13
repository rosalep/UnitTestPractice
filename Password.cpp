#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0; // changed from 1 to 0
  int index = 0;
  if(phrase.length()==0){return 0;}
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  int index = 0;
  bool lower=false;
  bool upper=false;

  // empty pass 
  if(pass.length()==0){return false;}

  while( index < pass.length()-1){
    if (lower && upper){return true;}
    if(isupper(pass[index])){upper=true;}
    if(islower(pass[index])){lower=true;}
    
    index++;
  }
  return false;
}

