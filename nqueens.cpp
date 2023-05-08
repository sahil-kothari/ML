#include<bits/stdc++.h>
using namespace std;


bool check(int board[8][8],int row,int col){

    int i,j;

    for(i=0;i<col;i++){
        if(board[row][i]){
            
            return false;
        }
    }

    for( i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(i=row,j=col;i<8 && j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }

    return true;

}

bool solve(int board[8][8],int col){

    if(col==8){
        return true;
    }

    for(int i=0;i<8;i++){
        if(check(board,i,col)){
            board[i][col]=1;
            //cout<<"Entered the value 1"<<endl;
       
            if(solve(board,col+1))
                return true;
            
            
                board[i][col]=0;
                //cout<<"deleted the value 1 and placed 0"<<endl;
            
        }
    } 
    return false;  
}

int main(){
    
    int board[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }

    solve(board,0);
    

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    
    return 0;
}