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
    string inputFile = "prompt9.txt"; //make it equal to something
    map<pair<string, int>, int> steam; 
    inFS.open(inputFile); 

    while(!inFS.eof())
    {
        string inputLine;
        if(getline(inFS, inputLine))
        {
            istringstream ss; 
            int numReleases, year;
            string month;
            size_t spaceSeperator, underscoreSeperator;
            spaceSeperator = inputLine.find(' ');
            underscoreSeperator = inputLine.find('_');
            ss.str(inputLine.substr(0, spaceSeperator));
            ss >> numReleases;
            ss.clear();
            ss.str(inputLine.substr(spaceSeperator + 1, underscoreSeperator - (spaceSeperator + 1)));
            ss >> month;
            ss.clear();
            ss.str(inputLine.substr(underscoreSeperator + 1));
            ss >> year;
            ss.clear();

            steam[make_pair(month, year)] = numReleases;
        }
    }

    map<string, int> monthIncrease; 
    long int numReleases = 0; 
    double mapSize = static_cast<double>(steam.size());
    bool firstTime = true;
    int lastValue;  
    for(const auto& s : steam)
    {   
        if(firstTime == true)
        {
            firstTime = false;
        }
        else
        {
            if(s.second > lastValue)
            {
                monthIncrease[s.first.first] = s.first.second;
            }
            lastValue = s.second;
        }
        lastValue = s.second;
        numReleases += s.second;
    }
    double average = numReleases / mapSize; 
    cout << "Average number of steam releases the past 2 years: " << average << endl << endl;

    cout << "Months where number of steam increased from previous month: " << endl;
    for(auto m : monthIncrease)
    {
        cout << m.first << " " << m.second << endl;
    }

    inFS.close();
    return 0; 
}