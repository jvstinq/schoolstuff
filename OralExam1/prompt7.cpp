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
    string inputFile = "prompt7.txt"; //make it equal to something
    vector<pair<string,int>> music;
    inFS.open(inputFile); 

    while(!inFS.eof())
    {
        string artistName, inputLine;
        int numStreams;
        if(getline(inFS, inputLine))
        {
            size_t seperator = inputLine.find(' ');
            artistName = inputLine.substr(0, seperator);
            istringstream ss(inputLine.substr(seperator + 1));
            ss >> numStreams; 

            music.push_back(make_pair(artistName, numStreams));
        }
    }

    double counter, totalStream = 0; 
    for(auto m : music)
    {   
        counter++; 
        totalStream += m.second; 
    }
    long double average = totalStream / counter; 
    cout << "Average number of streams: " << average << endl << endl;
    
    bool doInput = true;
    while(doInput == true)
    {
        bool artistFound = false; 
        string userInput; 
        cout << "Input an artist: ";
        getline(cin, userInput);

        long long int numStreams = 0; 
        int counterSongs = 0; 
        for(auto m : music)
        {
            if(userInput == m.first)
            {
                artistFound = true; 
                numStreams += m.second; 
                counterSongs++;
            }
        }
        if(artistFound == false)
        {
            cout << "Artist search not found." << endl << endl;
        }
        else
        {
            cout << "Total Number of Streams for " << userInput << " is: " << numStreams << endl;
            cout << "Number of songs that are in the top streams category: " << counterSongs << endl << endl;
        }
    }
    inFS.close();
    return 0; 
}