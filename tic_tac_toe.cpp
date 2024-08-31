#include<iostream>

using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token='X';
string p1="",p2="";
bool isTie=false;

void BoardFunc(){

cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
cout<<"---|---|---"<<endl;
cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
cout<<"---|---|---"<<endl;
cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

}


void UserInput(){

 int digit;
 if(token=='X'){
  cout<<p1<<"'s move : ";
  cin>>digit;
 }
 if(token=='0'){
  cout<<p2<<"'s move : ";
  cin>>digit;
 }


 if(digit==1){
  row=0;
  col=0;
 }
 if(digit==2){
  row=0;
  col=1;
 }
 if(digit==3){
  row=0;
  col=2;
 }
 if(digit==4){
  row=1;
  col=0;
 }
 if(digit==5){
  row=1;
  col=1;
 }
 if(digit==6){
  row=1;
  col=2;
 }
 if(digit==7){
  row=2;
  col=0;
 }
 if(digit==8){
  row=2;
  col=1;
 }
 if(digit==9){
  row=2;
  col=2;
 }

 else if(digit<=1 || digit>=9){
  cout<<"Invalid Input"<<endl; 
 }

 if(token=='X' && board[row][col]!='X' && board[row][col]!='0'){
  board[row][col]='X';
  token='0';
 }
 else if(token=='0' && board[row][col]!='X' && board[row][col]!='0'){
  board[row][col]='0';
  token='X';
 }
 else{
  cout<<"Cell Already Filled..."<<endl;
  UserInput();
 }
 BoardFunc();
}

bool gameStatus(){
 for(int i=0;i<3;i++){
  if((board[i][0]==board[i][1] && board[i][0]==board[i][2]) ||(board[0][i]==board[1][i] && board[0][i]==board[2][i])){
    return true;
  }
  if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
   return true;
  }
 }
  for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
    if(board[i][j]!='X' && board[i][j]!='0'){
     return false;
    }
   }
  }
  isTie = true;
  return false;
}


int main(){
 
cout<<"Insert P1 name : ";
getline(cin,p1);
cout<<"Insert P2 name : ";
getline(cin,p2);
cout<<endl<<"Tic Tac Toe"<<endl;
 
 while(!gameStatus()){
  BoardFunc();
  UserInput();
  gameStatus();
 }
 if(token=='X' && isTie == false){
  cout<<p2<<" Wins!!!"<<endl;
 }
 else if(token=='0' && isTie == false){
  cout<<p1<<" Wins!!!"<<endl;
 }
 else{
  cout<<".....DRAW....."<<endl;
 }
}
