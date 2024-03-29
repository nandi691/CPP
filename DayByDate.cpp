#include<iostream>

using namespace std;

int day_of_week(int y, int m, int d)
{
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
    int y,m,d;
    cout<<"Enter the date(1-31): ";
    cin>>d;
    cout<<"Enter the month(1-12): ";
    cin>>m;
    cout<<"Enter the year(yyyy): ";
    cin>>y;
    switch(day_of_week(y,m,d)){
        case 0: cout<<"\nSunday\n";
        break;
        case 1: cout<<"\nMonday\n";
        break;
        case 2: cout<<"\nTuesday\n";
        break;
        case 3: cout<<"\nWednesday\n";
        break;
        case 4: cout<<"\nThursday\n";
        break;
        case 5: cout<<"\nFriday\n";
        break;
        case 6: cout<<"\nSaturday\n";
        break;
    }
    return 0;
}
