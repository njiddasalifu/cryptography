//columnar transposition is transposition cypher technique

#include<stdio.h>
char Key = "";
map<int,int> KeyMap;

void setPermutationOrder(){
    //adding the permutation order
    for(int i=0;i<Key.length();i++){
        KeyMap[Key[i]] = i;
    }
}

//encryption function

String encryptMessage(String msg){
    int row,col,j;
    String cipher = "";

    col = Key.length();
    row = msg.length()%col;

    if(msg.length() % col)
    row++;

    char matrix[row][col];

    for(int i=0;k=0; i<row;i++){
        for(int j=0; j<col){
            if(msg[k] == '\0'){
                matrix[i][j] = '_';
                j++;
            }
        }
    }
}
