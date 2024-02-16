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
    set<string> iceCream;
    vector<string> vectorFlavor;
    string inputFile = "prompt8.txt"; //make it equal to something
    inFS.open(inputFile); 

    int numStudents = 0;

    while(!inFS.eof())
    {   
        string inputLine; 
        if( getline(inFS, inputLine) )
        {
            if(!inputLine.empty())
            {
                istringstream ss(inputLine);
                string flavor; 
                while(ss >> flavor)
                {
                    numStudents++;
                    vectorFlavor.push_back(flavor);
                    iceCream.emplace(flavor);  
                }
            }           
        }
    }

    int chocolateCounter = 0; 
    for(size_t i = 0; i < vectorFlavor.size(); i++)
    {
        if(vectorFlavor[i] == "Chocolate")
        {
            chocolateCounter++;
        }
    }
    int numDifferentFlavors = iceCream.size();

    cout << endl;
    cout << "Number of times chocolate was said as favorite flavor: " << chocolateCounter << endl;
    cout << "Total amount of different flavors surveyed: " << numDifferentFlavors << endl << endl;

    cout << "List of unique flavor names:" << endl;
    for(auto i : iceCream)
        cout << i << endl;
    cout << endl; 

    inFS.close();
    return 0; 
}