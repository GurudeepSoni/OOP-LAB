#include <iostream>
using namespace std;

class Person{
    const long long Adhar_id;
    const string pan_id;
    string address;
    long long mob_no;
    public:
        Person(): Adhar_id(0),pan_id(""){

        }
        Person(long long AD_id, string Pan_id, string add, long long no):Adhar_id(AD_id), pan_id(Pan_id){
            this->address=add;
            this->mob_no=no;
        }   
        // member function
        long long getAdhar(){
            return Adhar_id;
        }
        string panid(){
            return pan_id;
        }
        string add(){
            return address;
        }
        long long num(){
            return mob_no;
        }
        void display(){
            cout<<"Adhar ID: "<<Adhar_id<<endl;
            cout<<"Pan Id: "<<pan_id<<endl;
            cout<<"Address is: "<<address<<endl;
            cout<<"mobile Number is: "<<mob_no<<endl;
        }
        void change(string add, long long num){
            address=add;
            mob_no=num;
        }
};
int main(){
    Person p1(12345678900, "asdasda64546", "jaipur", 7014962336);
    p1.display();
    cout<<endl;
    cout<<"changed data is "<<endl;
    cout<<endl; 
    p1.change("123456789", 123456789);
    p1.display();
    return 0;
}
