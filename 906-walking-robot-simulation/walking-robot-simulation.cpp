class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int x = 0,y = 0;
        unordered_map<int,set<int>> row,col;
        for(int i = 0; i < obstacles.size(); i++){
            col[obstacles[i][0]].insert(obstacles[i][1]);
            row[obstacles[i][1]].insert(obstacles[i][0]);
        }

        unordered_map<char,vector<char>> dir;
        dir['N'] = {'W','E'};
        dir['E'] = {'N','S'};
        dir['S'] = {'E','W'};
        dir['W'] = {'S','N'};

        char curr = 'N';
        for(int i = 0; i < commands.size(); i++){
            if(commands[i] < 0){
                curr = dir[curr][commands[i]+2];
                continue;
            }

            if(curr == 'N'){
                //+y;
                auto itr = col[x].upper_bound(y);
                if(itr == col[x].end()){
                    y += commands[i];
                }
                else {
                    int val = *itr;
                    y = min(y+commands[i],val-1);
                }
            }
            else if(curr == 'S'){
                auto itr = col[x].lower_bound(y);
                if(itr == col[x].begin()){
                    y -= commands[i];
                }
                else {
                    itr--;
                    int val = *itr;
                    y = max(y-commands[i],val+1);
                }
            }
            else if(curr == 'E'){
                auto itr = row[y].upper_bound(x);
                if(itr == row[y].end()){
                    x += commands[i];
                }
                else {
                    int val = *itr;
                    x = min(x+commands[i],val-1);
                }
            }
            else{
                auto itr = row[y].lower_bound(x);
                if(itr == row[y].begin()){
                    x -= commands[i];
                }
                else {
                    itr--;
                    int val = *itr;
                    x = max(x-commands[i],val+1);
                }
            }


            ans = max(ans,x*x + y*y);

        }

        return ans;
    }
};