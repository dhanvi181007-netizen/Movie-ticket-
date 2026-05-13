#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Ticket
{
private:
    string name,movie,language,screen,timing;
    int seats,totalAmount;
public:
    void book()
    {
        cin.ignore();
        cout<<"Enter Your Name: ";
        getline(cin,name);
        cout<<"\nNOW SHOWING"<<endl;
        cout<<"1. Dune"<<endl;
        cout<<"2. Spider-Man Brand New Day"<<endl;
        cout<<"3. Chhaava"<<endl;
        int m;
        cout<<"Choose Movie: ";
        cin>>m;
        if(m==1)
            movie="Dune";
        else if(m==2)
            movie="Spider-Man Brand New Day";
        else
            movie="Chhaava";
        cout<<"Choose Language:"<<endl;
        cout<<"1. English\n2. Hindi\n3. Gujarati"<<endl;
        int l;
        cin>>l;
        if(l==1)
            language="English";
        else if(l==2)
            language="Hindi";
        else
            language="Gujarati";
        cout<<"Choose Screen Type:"<<endl;
        cout<<"1. IMAX - Rs.500"<<endl;
        cout<<"2. 3D - Rs.350"<<endl;
        cout<<"3. 2D - Rs.200"<<endl;
        int s,price;
        cin>>s;
        if(s==1)
        {
            screen="IMAX";
            price=500;
        }
        else if(s==2)
        {
            screen="3D";
            price=350;
        }
        else
        {
            screen="2D";
            price=200;
        }
        cout<<"Choose Show Timing:"<<endl;
        cout<<"1. 10:00 AM\n2. 2:00 PM\n3. 7:00 PM"<<endl;
        int t;
        cin>>t;
        if(t==1)
            timing="10:00 AM";
        else if(t==2)
            timing="2:00 PM";
        else
            timing="7:00 PM";
        cout<<"Enter Number of Seats: ";
        cin>>seats;
        totalAmount=seats*price;
    }
    void show()
    {
        cout<<"BOOKING CONFIRMED"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Movie: "<<movie<<endl;
        cout<<"Language: "<<language<<endl;
        cout<<"Screen: "<<screen<<endl;
        cout<<"Timing: "<<timing<<endl;
        cout<<"Seats: "<<seats<<endl;
        cout<<"Total Amount: Rs."<<totalAmount<<endl;
    }
};
int main()
{
    queue<Ticket>q;
    int choice;
    int maxBookings=5;
    while(true)
    {
        cout<<" BOOK YOUR SHOW "<<endl;
        cout<<"1. Book Ticket"<<endl;
        cout<<"2. Cancel Ticket"<<endl;
        cout<<"3. Show First Booking"<<endl;
        cout<<"4. Total Bookings"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            if(q.size()==maxBookings)
            {
                cout<<"HOUSEFULL!"<<endl;
            }
            else
            {
                Ticket t;
                t.book();
                q.push(t);
                cout<<"Ticket Booked Successfully!"<<endl;
            }
            break;
        }
        case 2:
        {
            if(q.empty())
            {
                cout<<"\nNo Bookings Found!"<<endl;
            }
            else
            {
                cout<<"Booking Cancelled!"<<endl;
                q.pop();
            }
            break;
        }
        case 3:
        {
            if(q.empty())
            {
                cout<<"No Bookings Found!"<<endl;
            }
            else
            {
                q.front().show();
            }
            break;
        }
        case 4:
        {
            cout<<"Total Bookings: "<<q.size()<<endl;

            if(!q.empty())
            {
                cout<<"Latest Booking:"<<endl;

                q.back().show();
            }
            break;
        }
        case 5:
        {
            cout<<"Thank You!"<<endl;
            return 0;
        }
        default:
            cout<<"Invalid Choice!"<<endl;
        }
    }
    return 0;
}
