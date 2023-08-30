#include<bits/stdc++.h>

using namespace std;



/* directions:
N- (0,1,0)
E - (1,0,0)
U -(0,0,1)
*/


class spacecraft{
    private:
        int pos[3];
        int direction;

        const int update[6][3] = {  {0,0,1},
                                    {0,0,-1},
                                    {0,1,0},
                                    {1,0,0},
                                    {0,-1,0},
                                    {-1,0,0}};

        char dir_map[6]={'U','D','N','E','S','W'};

    /* direction:
            0 - Up          -> update (0,0,1)
            1 - down        -> update (0,0,-1)
            2 - North       ->  (0,1,0)
            3 - East        ->  (1,0,0)
            4 - South       -> (0,-1,0)
            5 - West        -> (-1,0,0)
    */


   public:
        spacecraft();
        spacecraft(int givenPos[],char dir);
        void move(bool forward);
        void turn_horizontally(bool left);
        void turn_vertically(bool up);
        void print();

};


//implementation

//default initializer
spacecraft::spacecraft(){
    for(int i=0;i<3;++i) pos[i]=0;
    direction=2;
}

//parameterized initializer
spacecraft::spacecraft(int givenPos[],char dir){
    for(int i=0;i<3;++i) pos[i]=givenPos[i];
    
    direction=2;                                                 //default (in case wrong direction is provided)
    for(int i=0;i<6;++i) if(dir==dir_map[i] || dir==dir_map[i]-'A'+'a') direction=i;
}

//move implementation
void spacecraft::move(bool forward){
    int step=1;
    if(forward==false) step=-1;
    
    for(int i=0;i<3;++i){
        // cout<<direction<<" "<<i<<step<<endl;
        pos[i]+=update[direction][i]*step;
    }
}

//turn implementation
void spacecraft::turn_horizontally(bool left){
    if(left){
        if(direction==0) direction=2;
        else if (direction==1) direction=4;
        else if(direction==2) direction=5;
        else direction--;
    }
    else{
        if(direction==0) direction=4;
        else if (direction==1) direction=2;
        else if(direction==5) direction=2;
        else direction++;
    }
}

//vertically
void spacecraft::turn_vertically(bool up){
    if(up) direction=0;
    else direction=1;
}

void spacecraft::print(){
    cout<<"Postion   : ";
    for(int i:pos) cout<< i<<" ";
    cout<<endl<<"Direction : "<<dir_map[direction]<<endl;
}


int main(){
    int pos[3];
    char direction;

    cout<<"enter the starting position {ex : x y z }";
    for(int i=0;i<3;++i) cin>>pos[i];

    cout<<"Enter the direction (N,W,S,E,U,D) : ";
    cin>>direction;
    
    spacecraft a(pos,direction);

    char c='a';     //c for choice

    cout<<"------------------------       MENU    ---------------------"<<endl;
    cout<<" Press \"f\" : to move Forward"<<endl;
    cout<<" Press \"b\" : to move backward"<<endl;
    cout<<" Press \"l\" : to turn Left"<<endl;
    cout<<" Press \"r\" : to turn right"<<endl;
    cout<<" Press \"u\" : to turn up-side"<<endl;
    cout<<" Press \"d\" : to turn down-side"<<endl;
    cout<<" Press anything else : to exit"<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    while(true){
        cout<<" ENTER YOUR CHOICE : ";
        cin>>c;

        if(c=='f' || c=='F') a.move(true);
        else if(c=='b' || c=='B') a.move(false);
        else if(c=='l' || c=='L') a.turn_horizontally(true);
        else if(c=='r' || c=='R') a.turn_horizontally(false);
        else if(c=='u' || c=='U') a.turn_vertically(true);
        else if(c=='d'|| c=='D') a.turn_vertically(false);
        else break;

        a.print();
        cout<<endl<<endl;
    }
    
    cout<<endl<<endl<<" TEST END"<<endl<<endl;
    a.print();
    return 0;

}
