class Robot {
    int n,m,dir;
    int x,y,peri;
    unordered_map<int,string> mp;
public:
    Robot(int width, int height) {
        m = width;
        n = height;
        peri = 2*(m+n-2);
        x = 0;
        y = 0;
        dir = 0;
        mp[0] = "East";
        mp[1] = "North";
        mp[2] = "West";
        mp[3] = "South";
    }
    
    void step(int num) {
        if(num%peri == 0)num = peri;
        else num = num%peri;

        if(dir == 0){
            if(x+num > m-1){
                dir = 1;
                int temp = x+num-m+1;
                x = m-1;
                step(temp);
            }
            else{
                x = x+num;
            }
        }
        else if(dir == 1){
            if(y+num > n-1){
                dir = 2;
                int temp = y+num-n+1;
                y = n-1;
                step(temp);
            }
            else{
                y = y+num;
            }
        }
        else if(dir == 2){
            if(x-num < 0){
                dir = 3;
                int temp = num-x;
                x = 0;
                step(temp);
            }
            else{
                x = x-num;
            }
        }
        else if(dir == 3){
            if(y-num < 0){
                dir = 0;
                int temp = num-y;
                y = 0;
                step(temp);
            }
            else{
                y = y-num;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return mp[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */