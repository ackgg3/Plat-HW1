#include <iostream>
#include <string>
#include <vector>

using namespace std;


const string INTEGER = "Integer";
const string DECIMAL = "Decimal";
const string HEX     = "Hexidecimal";
const string SCIENCE = "Scientific";
const string PHONE   = "Phone";
const string IDENT   = "Identifier";
const string ERR	 = "Unknown";
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
		input.push_back(word); 		//We get the input and hold it in the vector
	} //Weep
	
	cout << input.size() << endl;  	//Print size because the first thing is the size
    
	

	//Grab it word by word
	while(input.size() > 0)
	{
		word = input.front(); //Get the next word
		for(int i = 0; i < word.length(); i++) //Get word letter by letter
		{
			switch(state) //digest word
			{
				//Starting over
				
			}
		}
		output.push_back(result); //record result
		input.erase(input.begin()); //we don't need that word any more
	}

	while(output.size() > 0)
	{	
		count++;
		cout << count << ": " << output.front() << endl; //Knowing what's going in is nice
		output.erase(output.begin()); //BACK TO THE PIT WITH YE
	}
	return 0;
}
