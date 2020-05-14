#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector> 
#include <string>
#include <set>


using namespace std;

typedef pair<string,int> si;
typedef vector<si> vsi;

bool comp(si a, si b){
	return (a.first < b.first) || (a.first == b.first && a.second < b.second);
}

int main(){
	vector<string> words, titles;
	set<string> unique_titles;
	vsi kwic;
	string input;
	while(cin >> input, input != "::"){
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		words.push_back(input);
	}
    sort(words.begin(), words.end());


	int line = 0;
    cin.ignore();
	while(getline(cin, input)){
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		titles.push_back(input);

        istringstream iss(input);
        do
	    {
	        string subs = "";
	        iss >> subs;
	        if( subs != "" && !binary_search(words.begin(), words.end(), subs) ){
	        	kwic.push_back( make_pair(subs, line) );
	        }

	    } while (iss);
        line++;
	}

	sort(kwic.begin(), kwic.end(), comp);
	for(vsi::iterator it = kwic.begin(); it != kwic.end(); it++ ){
        string key = (*it).first;

        string title = titles[ (*it).second ];
        int pos = 0;
        while(1){
        	bool error = false;
        	title = titles[ (*it).second ];
        	size_t found = title.find(key, pos);
        	if(found >= title.length()) break;
        	if(found != 0){
	        	if(title[found-1] != ' '){
		        	pos = found + 1;
			        if(pos > title.length()){
			        	break;
			        }	
			        continue;
		        }
	    	}

	    	if(found+key.length() + 1 < title.length()){
	        	if(title[ found+key.length() ] != ' '){
		        	pos = found + 1;
			        if(pos > title.length()){
			        	break;
			        }
			        continue;	
		        }
	    	}

	        for(int i=found; i < ((int)found + (int)key.length()); i++){
	            title[i] = toupper(title[i]);
	        }

	        if(unique_titles.find(title) == unique_titles.end()){
        		break;    	
	        }
	        pos = found + 1;
	        if(pos > title.length()){
	        	break;
	        }
        }
        
        cout << title << endl;
        unique_titles.insert(title);
        
	}
}