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
        spacecraft(int givenPos[],int dir);
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
spacecraft::spacecraft(int givenPos[],int dir){
    for(int i=0;i<3;++i) pos[i]=givenPos[i];
    // if(dir>5) cout<<"ITS ERROR !!!!!"<<endl;
    direction=dir;
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
    cout<<"Postion : ";
    for(int i:pos) cout<< i<<" ";
    cout<<endl<<" Direction : "<<direction<<endl;
}


int main(){
    int pos[3];
    int direction;
    // given starting position and the commands
    char comm[]={'f','r','u','b','l'};

    cout<<"enter the starting position {ex : x y z }";
    for(int i=0;i<3;++i) cin>>pos[i];

    cout<<"Enter the direction (0-5) : ";
    cin>>direction;
    
    spacecraft a(pos,direction);
    
    for(char c:comm){
        cout<<c<<endl;
        if(c=='f') a.move(true);
        else if(c=='b') a.move(false);
        else if(c=='l') a.turn_horizontally(true);
        else if(c=='r') a.turn_horizontally(false);
        else if(c=='u') a.turn_vertically(true);
        else if(c=='d') a.turn_vertically(false);
        else cout<<" REALLY !!"<<endl;

        
        a.print();
        cout<<endl<<endl;
    }

    cout<<" TEST END"<<endl;
    a.print();
    return 0;

}