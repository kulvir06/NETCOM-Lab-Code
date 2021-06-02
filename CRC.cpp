#include<iostream>
#include<stdlib.h>
using namespace std;


string xor1(string a, string b)
{
    string result = "";
    
    int n = b.length();
    
    
    for(int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}


string mod2div(string divident, string divisor)
{
    
   
    int pick = divisor.length();
    
   
    string tmp = divident.substr(0, pick);
    
    int n = divident.length();
    
    while (pick < n)
    {
        if (tmp[0] == '1')
            
            tmp = xor1(divisor, tmp) + divident[pick];
        else
            
            
            tmp = xor1(std::string(pick, '0'), tmp) +
            divident[pick];
        
       
        pick += 1;
    }
    
    
    if (tmp[0] == '1')
        tmp = xor1(divisor, tmp);
    else
        tmp = xor1(std::string(pick, '0'), tmp);
    
    return tmp;
}


string encodeData(string data, string key)
{
    int l_key = key.length();
    
    
    string appended_data = (data +
                            std::string(
                                        l_key - 1, '0'));
    
    string remainder = mod2div(appended_data, key);
    cout << "Remainder (sender's side) : "<< remainder << "\n";
    return remainder;
    
    
}


int main()
{
    cout<<"Kulvir Singh 19BCE2074\n";
    string data;
    string key;
    cout<<"Enter data: ";
    cin>>data;
    cout<<"Enter generator: ";
    cin>>key;
    cout<<"\nData:"<<data<<"\n";
    cout<<"Generator:"<<key<<"\n\n";
    string rem1 = encodeData(data, key);
    string codeword = data+rem1;
    string codeword1 = "100010000000000";
    string codeword2 = "100110000000001";
    cout << "Codeword :"<< codeword << "\n";
    
    string rem2 = mod2div(codeword, key);
    cout << "Remainder (reciever's side) : "<< rem2 << "\n";
    
    int flag=0;
    for(int i=0;i<rem2.length();i++){
        if(rem2[i]!='0'){
            cout<< "Error detected!"<<"\n";
            flag=1;
            break;
        }
    }
    
    if(flag==0)
        cout<<"No errors detected."<<"\n";
    return 0;
}


