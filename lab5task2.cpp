#include<iostream>
#include<string>
using namespace std;
bool isGoodnumber(const string&s,int index=0){

 if (index == s.size())
        return true;

    
    char ch = s[index];
int digit = ch - '0';
   
   if (index % 2 == 0) {
        
        if (digit % 2 != 0)
            {return false;}
    } else if (digit!=2 && digit!=3 && digit!=5 && digit!=7)
           { return false;
    }
  
    return isGoodnumber(s, index + 1);
}






int main (){
string digit_strings[]={"02468","23478","224365"};
for(string digits : digit_strings){

bool is_good=isGoodnumber(digits,0);
cout<<"Digit string:"<<digits
<<"is"<<(is_good ?"good":"not good")<<endl;



}

return 0;



}