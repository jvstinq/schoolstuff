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
    string inputFile = "prompt10.txt"; //make it equal to something
    set<string> uniquePlayers; 
    vector<string> allMVP;
    inFS.open(inputFile); 

    string inputLine; 
    string header1, header2, dashes;
    getline(inFS, inputLine);
    header1 = inputLine; 
    getline(inFS, inputLine);
    header2 = inputLine; 
    getline(inFS, inputLine);
    inputLine.clear(); 
    
    while(!inFS.eof())
    {
        if( (getline(inFS, inputLine)) )
        {
            if(!inputLine.empty())
            {
                uniquePlayers.emplace(inputLine);
                allMVP.push_back(inputLine);  
            }
        }
    }
    cout << endl;

    int uniqueMVP = uniquePlayers.size();
    cout << "Number of unique MVPs: " << uniqueMVP << endl << endl;

    cout << "List of unique MVPs who have won more than once:" << endl;
    for(set<string>::iterator it = uniquePlayers.begin(); it != uniquePlayers.end(); it++)
    {
        int numApperances = 0; 
        for(size_t j = 0; j < allMVP.size(); j++)
        {
            if(*it == allMVP[j])
            {
                numApperances++;
            }
        }
        if(numApperances >= 2)
        {
            string name = *it; 
            cout << name << " has won MVP " << numApperances << " times." << endl;
        }
    }
    cout << endl;


    inFS.close();
    return 0; 
}