#include <iostream>
#include <vector>
using namespace std;
//  X | O | X
// ===|===|===
//  X | O | X
// ===|===|===
//  X | O | X
void printttt(char mat[][3])
{
    for(int i=0; i<3; i++) {
        int j;
        for(j=0; j<3; j++) {
            cout<<" "<<mat[i][j]<<" ";
            if(j<2)cout<<"|";
        }
        if(i==0)cout<<"       a | b | c ";
        else if (i==1)cout<<"       d | e | f ";
        else cout<<"       g | h | i ";
        cout<<endl;
        if(i<2)
            cout<<"===|===|===      ===|===|===\n";
    }
}
bool checkwin(char m[][3])
{
    if(m[0][0]==m[0][1] && m[0][1]==m[0][2] &&m[0][2]!=' ')return true;
    else if(m[2][0]==m[2][1] && m[2][1]==m[2][2] && m[2][2]!=' ')return true;
    else if(m[1][0]==m[1][1] && m[1][1]==m[1][2] && m[1][2]!=' ')return true;
    else if(m[0][0]==m[1][0] && m[1][0]==m[2][0] && m[2][0]!=' ')return true;
    else if(m[0][1]==m[1][1] && m[1][1]==m[2][1] && m[2][1]!=' ')return true;
    else if(m[0][2]==m[1][2] && m[1][2]==m[2][2] && m[2][2]!=' ')return true;
    else if(m[0][0]==m[1][1] && m[1][1]==m[2][2] && m[2][2]!=' ')return true;
    else if(m[2][0]==m[1][1] && m[1][1]==m[0][2] && m[0][2]!=' ')return true;
    else return false;
}
int main()
{
    vector<string>names;
    char ch[2];
    string plr;
    int user;
    cout<<"User 1, please enter your name : ";
    getline(cin,plr);
    names.push_back(plr);
    cout<<"User 1, please enter your sign for game : ";
    cin>>ch[0];
    cin.ignore();
    cout<<"User 2, please enter your name : ";
    getline(cin,plr);
    names.push_back(plr);
    cout<<"User 2, please enter your sign for game : ";
    cin>>ch[1];

    while(1) {
        cout<<"Who want to start first? User 1 or 2 ? : ";
        cin>>user;
        char mat[3][3];
        for(int i=0; i<3; i++)for(int j=0; j<3; j++)mat[i][j]=' ';
        int size=0;
        while(1) {
            printttt(mat);
            cout<<names[user-1]<<", your turn! : ";
            int row,col;
            char c;
            cin>>c;
            switch(c) {
            case 'a':
                row=0;
                col=0;
                break;
            case 'b':
                row=0;
                col=1;
                break;
            case 'c':
                row=0;
                col=2;
                break;
            case 'd':
                row=1;
                col=0;
                break;
            case 'e':
                row=1;
                col=1;
                break;
            case 'f':
                row=1;
                col=2;
                break;
            case 'g':
                row=2;
                col=0;
                break;
            case 'h':
                row=2;
                col=1;
                break;
            case 'i':
                row=2;
                col=2;
                break;
            default:
                cout<<"Enter correctly.\n";
                continue;
            }
            if(mat[row][col]!=' ') {
                cout<<"Enter correctly !"<<endl;
                continue;
            }
            mat[row][col]=ch[user-1];
            size++;
            if(checkwin(mat)) {
                printttt(mat);
                cout<<"Congratulations! "<<names[user-1]<<", you have won.\n";
                break;
            }
            if(size==9) {
                printttt(mat);
                cout<<"Match had tied!\n";
                break;
            }
            if(user==1)user=2;
            else user=1;
        }
        bool ans;
        cout<<"Do you want to continue ?  Enter 1 or 0 : ";
        cin>>ans;
        if(ans==0)
            break;
    }
    return 0;
}
