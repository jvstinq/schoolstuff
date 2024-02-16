#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <stack> 
#include <queue> 
#include <sstream>
#include <sstream>

#define ERROR GENSHIN
#define BUG YAEMIKO

using namespace std; 

int main()
{
    ifstream inFS;
    string inputFile = "prompt5.txt"; //make it equal to something
    map<string, int> states;
    inFS.open(inputFile); 

    int totalBirths = 0; 
    while(!inFS.eof())
    {
        string inputLine;
        string stateName;
        int numBirths;
        if(getline(inFS, inputLine))
        {
            size_t seperator = inputLine.find(',');
            stateName = inputLine.substr(0, seperator); 
            istringstream ss(inputLine.substr(seperator + 1));
            ss >> numBirths; 

            states[stateName] = numBirths; 
        }
    }

    int lowestState = 500000;
    string lowestBirthState;
    int numBirthsVowel = 0;
    for(auto s : states)
    {
        string stateName = s.first; 
        if( (stateName[0] == 'A') || (stateName[0] == 'E') || (stateName[0] == 'I') || (stateName[0] == 'O') || (stateName[0] == 'U'))
        {
            numBirthsVowel += s.second;
        }
        {

        }
        if(s.second < lowestState)
        {
            lowestBirthState = s.first;
            lowestState = s.second; 
        }
    }

    cout << lowestBirthState << " is the state with the least amount of births with " << lowestState << " births." << endl;
    cout << '\n';
    cout << "Total Amount of Births with States That Start with a Vowel: " << numBirthsVowel << " births." << endl;   

    inFS.close();
    return 0; 
}