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
        if      (c == '+' || c == '-') {state = 1;}
        else if (c >= '0' && c <= '9') {state = 2;}
        else                           {return false;}
        break;
      case 1:
        if (c >= '0' && c <= '9') {state = 2;}
        else                      {return false;}
        break;
      case 2:
        if (c >= '0' && c <= '9') {state = 2;}
        else                      {return false;}
       break;
    }
  }
  if(state == 2)  {return true;}
  else            {return false;}
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
  if(state == 4)  {return true;}
  else            {return false;}
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
        if      ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))  {state = 1;}
        else                                                        {return false;}
        break;
      case 1:
        if      ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))  {state = 1;}
        else if (c == 'H' && i == word.length()-1)                  {return true;}
        else                                                        {return false;}
        break;
      case 2:                                                       {return false;}
        break;
    }
  }
}

bool isPhn(string word)
{
return false;
}

bool isKey(string word)
{
return false;
}

bool isIdt(string word)
{
return false;
}

int main()
{   
  vector<string> input;
  vector<string> output;
  int state = 0;
  int count = 0;
  string word = "";
  string result = "";
  while(cin >> word)
  {
        input.push_back(word);      //We get the input and hold it in the 
                                    //vector
      } 

    cout << input.size() << endl;   //Print size because the first thing is 
                                    //the size
    
    

    //Grab it word by word
    while(input.size() > 0)
    {
        word = input.front(); //Get the next word
        if      (isInt(word)) {result = ING;}
        else if (isDec(word)) {result = DEC;}
        else if (isSci(word)) {result = SCI;}
        else if (isHex(word)) {result = HEX;}
        else if (isPhn(word)) {result = PHN;}
        else if (isKey(word)) {result = IDT;}
        else if (isIdt(word)) {result = KEY;}
        else                  {result = ERR;}
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
