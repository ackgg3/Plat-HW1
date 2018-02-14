#include <iostream>
#include <string>
#include <vector>

using namespace std;


const string ING = "Integer";
const string DEC = "Decimal";
const string HEX = "Hexidecimal";
const string SCI = "Scientific";
const string PHN = "Phone";
const string IDT = "Identifier";
const string KEY = "Keyword";
const string ERR = "INVALID!";

bool isInt(string word)
{
  char c;
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      (c == '+' || c == '-')  {state = 1;}
      else if (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 1:
      if (c >= '0' && c <= '9')       {state = 2;}
      else                            {return false;}
      break;
      case 2:
      if (c >= '0' && c <= '9')       {state = 2;}
      else                            {return false;}
      break;
    }
  }
  if(state == 2)                      {return true;}
  else                                {return false;}
}

bool isDec(string word)
{
  char c;
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      (c == '+' || c == '-')  {state = 1;}
      else if (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 1:
      if      (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 2:
      if      (c >= '0' && c <= '9')  {state = 2;}
      else if (c == '.')              {state = 3;}
      else                            {return false;}
      break;
      case 3:
      if      (c >= '0' && c <= '9')  {state = 4;}
      else                            {return false;}
      break;
      case 4:
      if      (c >= '0' && c <= '9')  {state = 4;}
      else                            {return false;}
      break;
    }
  }
  if(state == 4)                      {return true;}
  else                                {return false;}
}

bool isSci(string word)
{
  char c;
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      (c == '+' || c == '-')  {state = 1;}
      else if (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 1:
      if      (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 2:
      if      (c >= '0' && c <= '9')  {state = 2;}
      else if (c == '.')              {state = 3;}
      else                            {return false;}
      break;
      case 3:
      if      (c >= '0' && c <= '9')  {state = 4;}
      else                            {return false;}
      break;
      case 4:
      if      (c >= '0' && c <= '9')  {state = 4;}
      else if (c == 'E')              {state = 5;}
      else                            {return false;}
      break;
      case 5:
      if      (c == '-')              {state = 6;}
      else if (c >= '0' && c <= '9')  {state = 7;}
      else                            {return false;}
      break;
      case 6:
      if      (c >= '0' && c <= '9')  {state = 7;}
      else                            {return false;}
      break;
      case 7:
      if      (c >= '0' && c <= '9')  {state = 7;}
      else                            {return false;}
      break;
    }
  }
  if(state == 7)  {return true;}
  else            {return false;}
}

bool isHex(string word)
{
  char c;
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      ((c >= '0' && c <= '9') 
              || (c >= 'A' && c <= 'F'))          {state = 1;}
      else                                        {return false;}
      break;
      case 1:
      if      ((c >= '0' && c <= '9') 
              || (c >= 'A' && c <= 'F'))          {state = 1;}
      else if (c == 'H' && i == word.length()-1)  {return true;}
      else                                        {return false;}
      break;
    }
  }
}

bool isPhn(string word)
{
  //Here's the Hatchet O' Hacking
  //Because there's some stupid hacks ahead
  //  /'-./\_
  // :HACK||,>
  //  \.-'||
  //      ||
  //      ||
  //      ||
  char c;
  bool paren = 0; //Awful hack because I'm lazy. it works though.
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      (c == '(')              {state = 1; paren = 1;}
      else if (c >= '0' && c <= '9')  {state = 6;}
      else                            {return false;}
      break;
      case 1:
      if      (c >= '0' && c <= '9')  {state = 2;}
      else                            {return false;}
      break;
      case 2:
      if      (c >= '0' && c <= '9')  {state = 3;}
      else                            {return false;}
      break;
      case 3:
      if      (c >= '0' && c <= '9')  {state = 4;}
      else                            {return false;}
      break;
      case 4:
      if      (c == ')')              {state = 5;}
      else                            {return false;}
      break;
      case 5:
      if      (c >= '0' && c <= '9')  {state = 10;}
      else                            {return false;}
      break;
      case 6:
      if      (c >= '0' && c <= '9')  {state = 7;}
      else                            {return false;}
      break;
      case 7:
      if      (c >= '0' && c <= '9')  {state = 8;}
      else                            {return false;}
      break;
      case 8:
      if      (c == '-')              {state = 9;}
      else if (c == '.')              {state = 15;}
      else                            {return false;}
      break;
      case 9:
      if      (c >= '0' && c <= '9')  {state = 10;}
      else                            {return false;}
      break;
      case 10:
      if      (c >= '0' && c <= '9')  {state = 11;}
      else                            {return false;}
      break;
      case 11:
      if      (c >= '0' && c <= '9')  {state = 12;}
      else                            {return false;}
      break;
      case 12:
      if      (c == '-')              {state = 13;}
      else                            {return false;}
      break;
      case 13:
      if      (c >= '0' && c <= '9')  {state = 14;}
      else                            {return false;}
      break;
      case 14:
      if      (c >= '0' && c <= '9')  {state = 19;}
      else                            {return false;}
      break;
      case 15:
      if      (c >= '0' && c <= '9')  {state = 16;}
      else                            {return false;}
      break;
      case 16:
      if      (c >= '0' && c <= '9')  {state = 17;}
      else                            {return false;}
      break;
      case 17:
      if      (c >= '0' && c <= '9')  {state = 18;}
      else                            {return false;}
      break;
      case 18:
      if      (c == '.')              {state = 14;}
      else                            {return false;}
      break;
      case 19:
      if      (c >= '0' && c <= '9')  {state = 20;}
      else                            {return false;}
      break;
      case 20:
      if      (c >= '0' && c <= '9')  {state = 21;}
      else                            {return false;}
      break;
      case 21:
      if      (c >= '0' && c <= '9')  {return true;}
      else                            {return false;}
      break;
    }                              
  }
  if(state == 21 && paren)            {return true;}
  else  {return false;} 
}

bool isKey(string word)
{
  if      (word == "while") {return true;}
  else if (word == "else")  {return true;}
  else if (word == "if")    {return true;}
  else if (word == "print") {return true;}
  else                      {return false;}
}

bool isIdt(string word)
{
  char c;
  int state = 0;
  for(int i = 0; i < word.length(); i++)
  {
    c = word[i];
    switch(state)
    {
      case 0:
      if      ((c >= 'a' && c <= 'z') 
              || (c >= 'A' && c <= 'Z'))    {state = 1;}
      else                                  {return false;}
      break;
      case 1:
      if      (c == '_' 
              || (c >= 'a' && c <= 'z') 
              || (c >= 'A' && c <= 'Z') 
              || (c >= '0' && c <= '9'))    {state = 1;}
      else                                  {return false;}
    }
  }
  if(state == 1)                            {return true;}
  else                                      {return false;}
}

int main()
{   
  vector<string> input;
  vector<string> output;
  int state = 0;
  int count = 0;
  int t;
  string word = "";
  string result = "";
  cin >> t;
  //while(cin >> word) I was going to be clever then realized theres confined
  //                   input for this assignment 
  for(int i = 0; i < t; i++)
  {
        cin >> word;
        input.push_back(word);      //We get the input and hold it in the 
                                    //vector
  } 

  cout << input.size() << endl;   //Print size because the first thing is 
                                  //the size



    //Grab it word by word
  while(input.size() > 0)
  {
    word = input.front(); //Get the next word
    if      (isInt(word)) {result = ING;} //          ,--.!,
    else if (isDec(word)) {result = DEC;} //       __/   -*-
    else if (isSci(word)) {result = SCI;} //     ,d08b.  '|`
    else if (isHex(word)) {result = HEX;} //     0088MM     
    else if (isPhn(word)) {result = PHN;} //     `9MMP'     
    else if (isKey(word)) {result = KEY;} //
    else if (isIdt(word)) {result = IDT;} //
    else                  {result = ERR;} //
    output.push_back(result); //record result
    input.erase(input.begin()); //we don't need that word any more
  }
  while(output.size() > 0)
  {   
    count++;
    cout << count << ": " << output.front() <<"."<< endl;//Knowing what's 
                                                        //going in is nice
    output.erase(output.begin()); //BACK TO THE PIT WITH YE
  }
  return 0;
}
