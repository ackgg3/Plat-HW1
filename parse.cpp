#include <iostream>
#include <string>
#include <vector>

using namespace std;


const string ING = "Integer";
const string DEC = "Decimal";
const string HEX     = "Hexidecimal";
const string SCI = "Scientific";
const string PHN   = "Phone";
const string IDT   = "Identifier";
const string KEY    = "Keyword"
const string ERR	 = "INVALID!";
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
		input.push_back(word); 		//We get the input and hold it in the 
									//vector
	} 
	
	cout << input.size() << endl;  	//Print size because the first thing is 
									//the size
    
	

	//Grab it word by word
	while(input.size() > 0)
	{
		word = input.front(); //Get the next word
		if 		(isInt(word)) {result = ING}
		else if (isDec(word)) {result = DEC}
		else if (isSci(word)) {result = HEX}
		else if (isHex(word)) {result = SCI}
		else if (isPhn(word)) {result = PHN}
		else if (isKey(word)) {result = IDT}
		else if (isIdt(word)) {result = KEY}
		else 				  {result = ERR}
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
