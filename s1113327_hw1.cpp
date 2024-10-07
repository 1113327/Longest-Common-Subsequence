#include<iostream>
#include<string>
using namespace std;

int main(){
  string str[2];
  while( getline( cin, str[0] ) ){
    getline( cin, str[1] );
    int LCS[101] = {0};
    for( int i = 1 ; i <= str[0].length() ; i++ ){
      for( int j = str[1].length() ; j >= 1 ; j-- ){
        if( str[0][i-1] == str[1][j-1] )
          LCS[j] = LCS[j-1] + 1;
      }
      for( int j = 1 ; j <= str[1].length() ; j++ ){
        if( str[0][i-1] != str[1][j-1] )
          LCS[j] = max( LCS[j], LCS[j-1] );
      }
    }
    cout << LCS[str[1].length()] << endl;
  }
  return 0;
}