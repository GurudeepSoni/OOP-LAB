#include <iostream>
#include <string>
using namespace std;
class binary
{
private:
    string s;

public:
    void read(void);
    void ckbin(void);
    void ones(void);
    void display(void);
};

void binary ::read(void)
{
    cout << "Enter the binary" << endl;
    cin >> s;
}

void binary::ckbin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "invalid binary" << endl;
            exit(0);
        }
    }
}
void binary ::display(void)
{
    for (int i = 0; i < s.length(); i++)
    cout<<s.at(i);
}
void binary :: ones(void){
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i)=='0')
        {
            s.at(i)='1';
        }
        else
        {
            s.at(i)='0';
        }   
    }   
}
int main()
{
    binary b;
    b.read();
    b.ckbin();
    cout<<"the binary you entered is"<<endl; 
    b.display();
    cout<<endl;
    b.ones();
    cout<<"the binarty changed is"<<endl; 
    b.display();
}
