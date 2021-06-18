//this code is completely written by T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class String{
    private:
        char *myString;
    public :
        friend ostream &operator<<(ostream &output,String &s);
        friend istream &operator>>(istream &input,String &s);
        int size(){
            int i=0;
            for(i;myString[i]!='\0';i++){
                i++;
            }
            return i;
        }
};
ostream &operator<<(ostream &output,String &s){
    for(int i=0;i<s.size();i++){
        output<<s.myString[i];
    }
    output<<endl;
    return output;
}
istream &operator>>(istream &input,String &s){
    s.myString=new char;
    input>>s.myString;
    return input;
}
