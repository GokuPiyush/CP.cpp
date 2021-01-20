#include<bits/stdc++.h>
using namespace std;

const int n = 10;
char crossword[n][n];

void printCrossword(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< crossword[i][j];
        }
        cout<< endl;
    }
}
pair<bool, vector<pair<pair<int, int>, char>>> checkVertical(int x, int y, string word){
    bool b = true;
    vector<pair<pair<int, int>, char>> v;
    for(int i=0; i<word.length(); i++){
        if(crossword[x+i][y] == '-'){
            v.push_back(make_pair(make_pair(x+i, y), word[i]));
        }else if(crossword[x+i][y] == word[i]){
            continue;
        }else{
            b = false;
            break;
        }
    }
    return make_pair(b, v);
}
pair<bool, vector<pair<pair<int, int>, char>>> checkHorizontal(int x, int y, string word){
    bool b = true;
    vector<pair<pair<int, int>, char>> v;
    for(int i=0; i<word.length(); i++){
        if(crossword[x][y+i] == '-'){
            v.push_back(make_pair(make_pair(x, y+i), word[i]));
        }else if(crossword[x][y+i] == word[i]){
            continue;
        }else{
            b = false;
            break;
        }
    }
    return make_pair(b, v);
}
void setCrossword(vector<pair<pair<int, int>, char>> v){
    for(int i=0; i<v.size(); i++){
        crossword[v[i].first.first][v[i].first.second] = v[i].second;
    }
}
void resetCrossword(vector<pair<pair<int, int>, char>> v){
    for(int i=0; i<v.size(); i++){
        crossword[v[i].first.first][v[i].first.second] = '-';
    }
}
bool solveCrossword(string *st, int m, int index = 0){
    if(index >= m ){
        return true;
    }
    string word = st[index];
    for(int i=0; i<n; i++){
        for(int j=0; j<n-word.length()+1; j++){
            pair<bool, vector<pair<pair<int, int>, char>>> result = checkHorizontal(i, j, word);
            if(result.first){
                setCrossword(result.second);
                //printCrossword();
                //cout<< endl;
                if(solveCrossword(st, m, index+1)){
                    return true;
                }else{
                    resetCrossword(result.second);
                    //printCrossword();
                    //cout<< endl;
                }
            }
        }
    }
    for(int i=0; i<n-word.length()+1; i++){
        for(int j=0; j<n; j++){
            pair<bool, vector<pair<pair<int, int>, char>>> result = checkVertical(i, j, word);
            if(result.first){
                setCrossword(result.second);
                //printCrossword();
                //cout<< endl;
                if(solveCrossword(st, m, index+1)){
                    return true;
                }else{
                    resetCrossword(result.second);
                    //printCrossword();
                    //cout<< endl;
                }
            }
        }
    }

    return false;
}

int main() {

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> crossword[i][j];
        }
    }
    string s;
    cin>> s;

    int m = count(&s[0], &s[0]+s.length(), ';')+1;
    string st[m];
    int c = 0;
    st[c] = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == ';'){
            c++;
            st[c] = "";
            continue;
        }
        st[c] += s[i];
    }

    if(solveCrossword(st, m)){
        printCrossword();
    }else{
        cout<< "Can't be solved"<< endl;
        printCrossword();
    }
}

/*
Crossword Problem
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/