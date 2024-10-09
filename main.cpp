#include <iostream>
using namespace std;

void drawTable(char gameSpaces[][3]){
    cout<<" "<<gameSpaces[0][0]<<" | "<<gameSpaces[0][1]<<" | "<<gameSpaces[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<gameSpaces[1][0]<<" | "<<gameSpaces[1][1]<<" | "<<gameSpaces[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<gameSpaces[2][0]<<" | "<<gameSpaces[2][1]<<" | "<<gameSpaces[2][2]<<endl;
}

bool checkWin(char gameSpaces[][3], char player){
    for(int i = 0;i<3;i++){
        if(gameSpaces[i][0] == player && gameSpaces[i][1] == player && gameSpaces[i][2] == player){
            return 1;
        }
        if(gameSpaces[0][i] == player && gameSpaces[1][i] == player && gameSpaces[2][i] == player){
            return 1;
        }
    }
    if(gameSpaces[0][0] == player && gameSpaces[1][1] == player && gameSpaces[2][2] == player){
            return 1;
    }
    if(gameSpaces[0][2] == player && gameSpaces[1][1] == player && gameSpaces[2][0] == player){
            return 1;
        }
    return 0;
}


int main() {
    int xwin = 0;
    int owin = 0;
    int draw = 0;
    char player;
    char bot;
    int gameType;
    cout<<"Hi! Choose the game you want to play (1-single player,2 - 2 players, 0- exit):";
    cin>>gameType;
    while(gameType > 2 || gameType < 0){
        cout<<"Invalid Input, try again:";
        cin>>gameType;
    }
    while(gameType!=0){
        char gameSpaces[3][3] = {{' ', ' ', ' '}, 
                            {' ', ' ', ' '}, 
                            {' ', ' ', ' '}};
        int freeSpaces[9];
        for(int i = 0; i<9;i++){
            if(gameType == 2){
                player = (i%2 == 0)?'X':'O';
            }else if (gameType == 1 && i == 0){
                cout<<"Choose X/O"<<endl;
                cin>>player;
                while(player != 'X' && player != 'O'){
                    cout<<"Invalid choice,try again:";
                    cin>>player;
                }
                bot = (player == 'X')?'O':'X';
            }
            if(gameType == 2 || (gameType == 1 && i%2 == (player == 'O'))){
                drawTable(gameSpaces);
                cout<<"Choose row and column for "<<player<<" : "<<endl;
                int col,row;
                while(true){
                    cin>>row>>col;
                    if(gameSpaces[row][col] == ' '){
                        gameSpaces[row][col] = player;
                        break;
                    }else{
                        cout<<"Position invalid,choose again:"<<endl;
                    }
                }
            }else{
                cout<<endl;
                int pos = 0;
                for(int i = 0;i<3;i++){
                    for(int j = 0;j<3;j++){
                        if(gameSpaces[i][j] == ' '){
                            freeSpaces[pos++]=i+10*j;
                        }
                    }
                }
                int choice = rand()%(pos+1);
                gameSpaces[freeSpaces[choice]%10][freeSpaces[choice]/10] = bot;
            }
            if(i>=4){
                if(checkWin(gameSpaces,'X')){
                    drawTable(gameSpaces);
                    cout<<endl<<"X WON!"<<endl;
                    xwin++;
                    break;
                }
                if(checkWin(gameSpaces,'O')){
                    drawTable(gameSpaces);
                    cout<<"O WON!";
                    owin++;
                    break;
                }
            }
            if(i == 8){
                drawTable(gameSpaces);
                cout<<"Draw"<<endl;
                draw++;
                break;
            }
        }
        cout<<"X has won "<<xwin<<" times"<<endl;
        cout<<"O has won "<<owin<<" times"<<endl;
        cout<<"The game ended in a draw "<<draw<<" times"<<endl;
        cout<<"Hi! Choose the game you want to play (1-single player,2 - 2 players, 0- exit):";
        cin>>gameType;
        while(gameType > 2 || gameType < 0){
            cout<<"Invalid Input, try again:";
            cin>>gameType;
        }
    }
    return 0;
}
