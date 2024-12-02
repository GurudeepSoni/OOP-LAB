#include <iostream>
using namespace std;

class store
{
private:
    int itemid[100];
    int price[100];
    int count = 0;

public:
    void setlist(void);
    void display(void);
};
void store::setlist(void)
{
    cout << "Enter id of your item no " << count + 1 << endl;
    cin >> itemid[count];
    cout << "Enter price of your item" << endl;
    cin >> price[count];
    count ++;
}
void store::display(void){
    for (int i = 0; i < count; i++)
    {
        cout<<"the item no "<<itemid[i] <<" with price "<<price[i]<<endl;
    }
} 
int main(){
    store A;
    int n;
    cout<<"Enter the number of item you want to buy"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        A.setlist();
    }
    A.display();
}