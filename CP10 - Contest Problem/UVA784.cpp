#include <string>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> maze;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(ii pos){
    int i = pos.first, j = pos.second;
    if(i<0 || j<0) return;
    if(maze[i][j] == 0){
        maze[i][j] = 2;
        for(int k=0;k<4;k++){
            dfs( ii( i+dr[k], j+dc[k] ) );
        }
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        char wall;
        maze.resize(31);
        maze.clear();
        string input;
        int line = 0;
        ii pos;
        
        while(getline(cin, input)){
            maze[line].resize(80,3);
            if(input[0] == '_'){
                break;
            }else{
                for(int i=0;i<input.length();i++){
                    if(input[i] == ' ' ||  input[i] == '*'){
                        maze[line][i] = 0;
                        if(input[i] == '*'){
                            pos = make_pair(line, i);
                        }
                    }else{
                        wall = input[i];
                        maze[line][i] = 1;
                        
                    }
                }
            }
            line++;
        }
        
        dfs(pos);
        for(int i=0;i<line;i++){
            for(int j=0;j<maze[line].size();j++){
                if(maze[i][j] == 1)
                    cout << wall;
                else if(maze[i][j] == 2)
                    cout << "#";
                else if(maze[i][j] == 0)
                    cout << " ";
            }
            cout << endl;
        }
        cout << input << endl;
    }
    
    
}