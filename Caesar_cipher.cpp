#include<iostream>
#include<string.h>
using namespace std;
char Encryption(char ch){
    char base=islower(ch)?'a':'A';
    char c=((ch-base+3)%26)+base;
    return c;
}
char Decryption(char ch){
    char base=islower(ch)?'a':'A';
    char c=((ch-base+23)%26)+base;
    return c;
}
string convertocipher(string str){
    string ans="";
    int n=str.length();
    for(int i=0;i<n;i++){
        if(isalpha(str[i])){
            /*char base=islower(str[i])?'a':'A';
            char c=((str[i]-base+3)%26)+base;*/
            char c=Encryption(str[i]);
            ans+=c;
        }
        else{
            ans+=str[i];
        }
    }
    return ans;
}
string convertoplain(string str){
    string ans="";
    int n=str.length();
    for(int i=0;i<n;i++){
        if(isalpha(str[i])){
            /*char base=islower(str[i])?'a':'A';
            char c=((str[i]-base+23)%26)+base;*/
            char c=Decryption(str[i]);
            ans+=c;
        }
        else{
            ans+=str[i];
        }
    }
    return ans;
}
int main(){
    string s1,ans;
    char choice;
    while(true){
        cout<<"Which operation do you want to perform "<<endl<<"'E' : for Encryption and 'D' : for Decryption: ";
        cin>>choice;
        cin.ignore();  //Ignore the newline character left in the stream
        if(choice=='e' || choice=='E'){
            cout<<"Enter the plain-text to convert into cipher-text : ";
            //cin>>s1;
            getline(cin,s1);
            ans=convertocipher(s1);
        }
        else if(choice=='d' || choice=='D'){
            cout<<"Enter the ciphered-text to convert into plain-text : ";
            //cin>>s1;
            getline(cin,s1);
            ans=convertoplain(s1);
        }
        cout<<ans<<endl;
    }
    return 0;
}