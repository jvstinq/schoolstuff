#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath> 
#include <set>
#include <string> 
#include <vector>
#include <map> 
#include <stack> 
#include <queue> 
#include <algorithm> 
#include <sstream>

using namespace std;

int main()
{
    ifstream inFS;
    inFS.open("prompt1.txt");
    map<string, int> anime;

    while(!inFS.eof())
    {   
        string lineInput;
        while (getline(inFS, lineInput))
        {
            istringstream ss; 
            string animeTitle;
            size_t seperator = lineInput.find(',');
            ss.str(lineInput.substr(0, seperator));
            getline(ss, animeTitle); 
            ss.clear();
            //animeTitle = lineInput.substr(0, seperator);
            //stringstream ss(lineInput.substr(seperator + 1));
            ss.str(lineInput.substr(seperator + 1));
            int animeEpisode;
            ss >> animeEpisode;

            anime[animeTitle] = animeEpisode;
        }
    }
    
    string animeHighTitle;
    set<string> movie;
    int highestNumEp = 0; 
    for(auto s : anime)
    {
        if(s.second > highestNumEp)
        {
            highestNumEp = s.second;
            animeHighTitle = s.first;
        }
        if(s.second == 1)
        {
            movie.emplace(s.first);
        }
    }

    cout << "Anime with most episodes is: " << animeHighTitle << endl << endl;
    cout << "List of anime movies (1 in Text File): " << endl;
    for(auto s : movie)
    {
        cout << s << endl;
    }

    inFS.close();
    return 0;  
}

