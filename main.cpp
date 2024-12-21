#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;
bool gameOver = false;
int x, y, fruitx, fruity, bodylen, score;
int bodyx[100], bodyy[100];


enum eDirection {LEFT, RIGHT, UP, DOWN, STOP=0};
eDirection dir; 

void setup();
void draw();
void input();
void logic();

int main() {
  
 setup();
while(!gameOver){
  draw();
  input();
  logic(); 
}
  
return 0;
}

void setup(){
  x=WIDTH/2;
  y=HEIGHT/2;
  fruitx=rand()%WIDTH;
    fruity=rand()%HEIGHT;

}
void draw(){
  system("clear");
  //top wall
  for(int i=0; i<WIDTH+2; i++){
    cout<<"#";
  }
  cout<<endl;

for(int i=0; i<HEIGHT; i++){
  for(int j=0; j<WIDTH; j++){
    if(j==0)
    cout<<"#";
  if(i==y && j==x)
  cout<<"O";
    else if (i==fruity && j==fruitx)
      cout<<"@";
else{
  bool print=false;
for(int k=0; k<bodylen; k++){
  if(bodyx[k]==j && bodyy[k]==i){
    cout<<"o";
  print= true;
  }
}
if(!print)
  cout<<" ";
  }

    
    if(j==WIDTH-1)
       cout<<"#";
  

  }
  cout<<endl;
}
  
  //bottom wall
  for(int i=0; i<WIDTH+2; i++){
    cout<<"#";
  }
  cout<<endl;
    cout<<"score:\t"<<score<<endl;

}
void input(){
  char input;
  cin>>input;
  switch(input){
    case 'a':
    dir = LEFT;
    break;
    case 'd':
    dir = RIGHT;
    break;
    case 'w':
    dir = UP;
    break;
    case 's':
    dir = DOWN;
    break;
    case 'q':
    gameOver = true;
    break;
  }
}
void logic(){
  int prevx=bodyx[0];
  int prevy=bodyy[0];
  int tempx, tempy;
bodyx[0]=x;
  bodyy[0]=y;
for(int i=1; i<bodylen; i++){
  tempx=bodyx[i];
  tempy=bodyy[i];
bodyx[i]= prevx;
  bodyy[i]=prevy;
  prevx=tempx;
  prevy=tempy;
}


  
  switch(dir){
    case LEFT:
      x--;
    break;
    case RIGHT:
      x++;
    break;
    case UP:
      y--;
    break;
    case DOWN:
      y++;
    break;
    default:
  break;
  }

  //if(x>WIDTH || x<0 || y>HEIGHT || y<0)
    //gameOver=true;
if(x>=WIDTH)
  x=0;
  else if(x<0)
    x=WIDTH-1;

  if(y>=HEIGHT)
  y=0;
  else if(y<0)
    x=HEIGHT-1;

  for(int i=0; i<bodylen; i++){
    if(bodyx[i]==x && bodyy[i]==y){
      gameOver=true;
      cout<<"you lose!"<<endl;
    }
  }
  if(x==fruitx && y==fruity){
    fruitx = rand()%WIDTH;
    fruity = rand()%HEIGHT;
    bodylen++;
    score+=10;
  }
}
