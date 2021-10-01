/* 
Given a map Map<String, List<String>> userSongs with user names as keys and a list of all the songs that the user has listened to as values.

Also given a map Map<String, List<String>> songGenres, with song genre as keys and a list of all the songs within that genre as values. 
The song can only belong to only one genre.

The task is to return a map Map<String, List<String>>, where the key is a user name and the value is a list of the user's favorite genre(s). 
Favorite genre is the most listened to genre. A user can have more than one favorite genre if he/she has listened to the same number of songs per each of the genres.

Example 1:

Input:
userSongs = {  
   "David": ["song1", "song2", "song3", "song4", "song8"],
   "Emma":  ["song5", "song6", "song7"]
},
songGenres = {  
   "Rock":    ["song1", "song3"],
   "Dubstep": ["song7"],
   "Techno":  ["song2", "song4"],
   "Pop":     ["song5", "song6"],
   "Jazz":    ["song8", "song9"]
}

Output: {  
   "David": ["Rock", "Techno"],
   "Emma":  ["Pop"]
}

Explanation:
David has 2 Rock, 2 Techno and 1 Jazz song. So he has 2 favorite genres.
Emma has 2 Pop and 1 Dubstep song. Pop is Emma's favorite genre.
Example 2:

Input:
userSongs = {  
   "David": ["song1", "song2"],
   "Emma":  ["song3", "song4"]
},
songGenres = {}

Output: {  
   "David": [],
   "Emma":  []
} 

*/


/*
Problem analysis:
	- userSongs: Map<string, List<string>>; user as key; list of songs as values
	- songGenres: Map<string, List<string>>; genres as keys and list of songs as values.
	- need to find the favorite genres for each user.
	- favorite genres determined by the song counts, a user can have more than 1 genres. 

Questions:
	- How to keep count of each genres to determine the max count [?]
	- What is the best way to determine the count of each song genres [?]

Approach:
	- reverse the song genres map to have songs as key and genres as values. 
	- traverse the map for each user to find songs count for each genres.

Ex: after translate 
	['Rock', 'Pop', 'Rock', 'Jazz']

*/





#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;




map<string, vector<string>> favoriteGenresFinder(map<string,vector<string>> _songGenres, map<string, vector<string>> _userSongs);


int main()
{

	auto songGenres = map<string,vector<string>>();
	auto userSongs = map<string, vector<string>>();

	//Create song lists
	auto songsList1 = vector<string>();
	songsList1.push_back("song1");
	songsList1.push_back("song3");

	auto songsList2 = vector<string>();
	songsList2.push_back("song7");

	auto songsList3 = vector<string>();
	songsList3.push_back("song2");
	songsList3.push_back("song4");

	auto songsList4 = vector<string>();
	songsList4.push_back("song5");
	songsList4.push_back("song6");

	auto songsList5 = vector<string>();
	songsList5.push_back("song8");
	songsList5.push_back("song9");

	//populate song genres map
	songGenres["Rock"] 		= songsList1;
	songGenres["Dubstep"] 	= songsList2;
	songGenres["Techno"] 	= songsList3;
	songGenres["Pop"] 	= songsList4;
	songGenres["Jazz"] 	= songsList5;


	auto user1Songs= vector<string>();
	user1Songs.push_back("song1");
	user1Songs.push_back("song2");	
	user1Songs.push_back("song3");
	user1Songs.push_back("song4");
	user1Songs.push_back("song8");

	userSongs["David"] = user1Songs;

	auto user2Songs = vector<string>();
	user2Songs.push_back("song5");
	user2Songs.push_back("song6");
	user2Songs.push_back("song7");

	userSongs["Emma"] = user2Songs;


	auto finalMap = favoriteGenresFinder(songGenres,userSongs);

	for (auto mapIter = finalMap.begin(); mapIter != finalMap.end(); mapIter++)
	{
		cout << mapIter->first << " ";
		for(auto vecIter = mapIter->second.begin(); vecIter != mapIter->second.end(); vecIter++)
		{
			cout << *vecIter << " ";
		}
		cout << endl;
	}

	return 0;
}



/* Function: Favorite Genres Finder */
/* Take map of song genres, and map of user songs as input. Output the map of users favorite genres */
map<string, vector<string>> favoriteGenresFinder(map<string,vector<string>> _songGenres, map<string, vector<string>> _userSongs)
{
	//the return map
	auto userFavGenres = map<string, vector<string>>();

	//the reverse map 
	auto reversed_songGenres = map<string,string>();

	for (auto mapIter = _songGenres.begin(); mapIter != _songGenres.end(); mapIter++)
	{
		for(auto vecIter = mapIter->second.begin(); vecIter != mapIter->second.end(); vecIter++)
		{
			reversed_songGenres[*vecIter] = mapIter->first;
		}
	}


	//traverse each user song lists 
	for (auto userIter = _userSongs.begin(); userIter != _userSongs.end(); userIter++)
	{
		//vector to store the translated genres from songs
		auto genresList = vector<string>();

		//set to keep the unique genres of each list
		auto genresSet = set<string>();

		//countMap to keep track of the count of each genres
		auto countMap = map<string,int>();

		//the max occurence of genres
		int max = 0;

		//traverse the vector to translate song into genres
		for (auto vecIter = userIter->second.begin(); vecIter != userIter->second.end(); vecIter++)
		{
			genresList.push_back(reversed_songGenres[*vecIter]);
			genresSet.insert(reversed_songGenres[*vecIter]);
		}

		//traverse the genresSet  to count the number of occurence for each genres
		for (auto iter = genresSet.begin(); iter != genresSet.end(); iter++)
		{
			int counter = count(genresList.begin(), genresList.end(), *iter);

			if (max < counter)
				max = counter;

			//add to the count map
			countMap[*iter] = counter;
		}

		//vector of user fav genres 
		auto userGenres = vector<string>();

		for (auto iter = countMap.begin(); iter != countMap.end(); iter++)
		{
			if(iter->second == max)
			{
				userGenres.push_back(iter->first);
			}
		}

		//update the user favorite genres map
		userFavGenres[userIter->first] = userGenres;
	}

	return userFavGenres; 

}
