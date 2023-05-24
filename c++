#include <iostream>
using namespace std;
char turn='X';
 int row,coloum;
  int choice;
 char tic[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 bool draw=false;
void dispaly(){
   cout<<"\t\t"<<"   |"<<"     |"<<endl;
   cout<<"\t\t"<<tic[0][0]<<"  |  "<<tic[0][1]<<"  |  "<<tic[0][2]<<endl;
   cout<<"\t"<<"        ___| "<<"____|"<<"____"<<endl;
   cout<<"\t\t"<<"   |"<<"     |"<<endl;
   cout<<"\t\t"<<tic[1][0]<<"  |  "<<tic[1][1]<<"  |  "<<tic[1][2]<<endl;
   cout<<"\t"<<"        ___| "<<"____|"<<"____"<<endl;
   cout<<"\t\t"<<"   |"<<"     |"<<endl;
   cout<<"\t\t"<<tic[2][0]<<"  |  "<<tic[2][1]<<"  |  "<<tic[2][2]<<endl;
    }
 void turns(){
    if (turn =='X')
    cout<<"player 1  turn :";
    else if (turn=='O')
    cout<<"player 2  turn :";
    cin>>choice;
    switch(choice){
    case 1:row=0;coloum=0;
    break;
    case 2:row=0;coloum=1;
    break;
    case 3:row=0;coloum=2;
    break;
    case 4:row=1;coloum=0;
    break;
    case 5:row=1;coloum=1;
    break;
    case 6:row=1;coloum=2;
    break;
    case 7:row=2;coloum=0;
    break;
    case 8:row=2;coloum=1;
    break;
    case 9:row=2;coloum=2;
    break;
    default:
        cout<<"wrong  choice";
        break;
        turns();
        return;}
    if (turn == 'X' &&tic[row][coloum]!='X'&&tic[row][coloum]!='O') {
        tic[row][coloum] = 'X';
        turn = 'O';}
    else if (turn == 'O'&&tic[row][coloum]!='X'&&tic[row][coloum]!='O') {
        tic[row][coloum] = 'O';
        turn = 'X';}
        else{
            cout<<"wrong entry"<<endl;
            turns();
        }
    }

bool over(){


    for (int i = 0; i < 3; i++) {
        if (tic[i][0] == tic[i][1] && tic[i][0] == tic[i][2] || tic[0][i] == tic[1][i] && tic[0][i] == tic[2][i])
        return false;
    }
    if (tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2] || tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0]) {
        return false;
    }


    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        if (tic[i][j] != 'X' && tic[i][j] != 'O') {
            return true;
        }
    draw = true;
    return false;
}



int main()
{
    dispaly();
    while(over()){
    turns();
    dispaly();
    over();}

    if (turn == 'X' && draw == false) {
        cout << "player 2[O] WINS!!!" << endl;
    }
    else if (turn == 'O'  && draw == false) {
        cout << "player 1[X] WINS!!!" << endl;
    }
    else {
        cout << "GAME DRAW!!" << endl;
    }

    return 0;

}
