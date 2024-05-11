#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
class Bus
{
private:
    vector<bool> seats; // Represents seat availability, true means booked
public:
    Bus() : seats(47, false) {} // Initializes 47 seats as unbooked

    void displaySeats()
    {
        cout << "Available seats:\n";
        for (int i = 0; i < 47; ++i)
        {
            cout << setw(3) << i + 1 << (seats[i] ? "  Booked " : " Available ");
            if ((i + 1) % 5 == 0) // Print 5 seats per row
                cout << endl;
        }
    }

    void bookSeat(int seatNumber)
    {
        if (seatNumber < 1 || seatNumber > 47)
        {
            cout << "Invalid seat number.\n";
            return;
        }

        if (seats[seatNumber - 1])
        {
            cout << "Seat " << seatNumber << " is already booked.\n";
        }
        else
        {
            seats[seatNumber - 1] = true;
            cout << "Seat " << seatNumber << " booked successfully.\n";
        }
    }

    void cancelSeat(int seatNumber)
    {
        if (seatNumber < 1 || seatNumber > 47)
        {
            cout << "Invalid seat number.\n";
            return;
        }

        if (!seats[seatNumber - 1])
        {
            cout << "Seat " << seatNumber << " is already available.\n";
        }
        else
        {
            seats[seatNumber - 1] = false;
            cout << "Seat " << seatNumber << " cancelled successfully.\n";
        }
    }
    string departure_city[100] = {"Lahore", "Rawalpindi", "Multan", "Peshawar", "Karachi", "Faisalabad", "Abbottabad", "Hyderabad", "Gujranwala", "Murree", "Quetta"};
    string arrival_city[100] = {"Lahore", "Rawalpindi", "Multan", "Peshawar", "Karachi", "Faisalabad", "Abbottabad", "Hyderabad", "Gujranwala", "Murree", "Quetta"};
    int amount = 0, option, option2, arrival_time, departure_time, total_passengers, departure_date, arrival_date;
    string gender;
    long cnicno, contactno;
    char choice;
   
    void Calculation()
    {
        cout << "Welcome to Bookme Bus services!!" << endl;
        cout << "Enter your CNIC number: ";
        cin >> cnicno;
        cout << "Enter your gender: ";
        cin >> gender;
        cout << "Enter your contact number: ";
        cin >> contactno;
        cout << "Press a for Oneway." << endl;
        cout << "Press b for Roundtrip." << endl;
        cin >> choice;
        if (choice == 'a' || choice == 'A')
        {
            cout << "Enter Departure Date: ";
            cin >> departure_date;
            cout << "Enter Departure Time: ";
            cin >> departure_time;
            cout << "Enter the total number of passengers: ";
            cin >> total_passengers;
            cout << "Select Departure City: " << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "Press " << i + 1 << " for " << departure_city[i] << endl;
            }
            cin >> option;
            cout << "==========================================" << endl;
            cout << "Select Arrival City: " << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "Press " << i + 1 << " for " << arrival_city[i] << endl;
            }
            cin >> option2;
            cout << "==========================================" << endl;
            if (option == option2)
            {
                cout << "Invalid Route." << endl;
            }
            else if (option == 1 && option2 == 2 || option2 == 1 && option == 2)
            {
                amount = amount + 1900;
            }
            else if (option == 1 && option2 == 3 || option == 3 && option2 == 1)
            {
                amount = amount + 1800;
            }
            else if (option == 1 && option2 == 4 || option == 4 && option2 == 1)
            {
                amount = amount + 2100;
            }
            else if (option == 1 && option2 == 5 || option == 5 && option2 == 1)
            {
                amount = amount + 5500;
            }
            else if (option == 1 && option2 == 6 || option == 6 && option2 == 1)
            {
                amount = amount + 750;
            }
            else if (option == 1 && option2 == 7 || option == 1 && option2 == 3)
            {
                amount = amount + 2300;
            }
            else if (option == 1 && option2 == 8 || option == 8 && option2 == 1)
            {
                amount = amount + 5000;
            }
            else if (option == 1 && option2 == 9 || option == 9 && option2 == 1)
            {
                amount = amount + 400;
            }
            else if (option == 1 && option2 == 10 || option == 10 && option2 == 1)
            {
                amount = amount + 2350;
            }
            else if (option == 1 && option2 == 11 || option == 11 && option2 == 1)
            {
                amount = amount + 4000;
            }
            else if (option == 2 && option2 == 3 || option == 3 && option2 == 2)
            {
                amount = amount + 2200;
            }
            else if (option == 2 && option2 == 4 || option == 4 && option2 == 2)
            {
                amount = amount + 820;
            }
            else if (option == 2 && option2 == 5 || option == 5 && option2 == 2)
            {
                amount = amount + 6000;
            }
            else if (option == 2 && option2 == 6 || option == 6 && option2 == 2)
            {
                amount = amount + 1750;
            }
            else if (option == 2 && option2 == 7 || option == 7 && option2 == 2)
            {
                amount = amount + 840;
            }
            else if (option == 2 && option2 == 8 || option == 8 && option2 == 2)
            {
                amount = amount + 5300;
            }
            else if (option == 2 && option2 == 9 || option == 9 && option2 == 2)
            {
                amount = amount + 1460;
            }
            else if (option == 2 && option2 == 10 || option == 10 && option2 == 2)
            {
                amount = amount + 720;
            }
            else if (option == 2 && option2 == 11 || option == 11 && option2 == 2)
            {
                amount = amount + 3500;
            }

            else if (option == 3 && option2 == 4 || option == 4 && option2 == 3)
            {
                amount = amount + 2600;
            }
            else if (option == 3 && option2 == 5 || option == 3 && option2 == 5)
            {
                amount = amount + 3200;
            }
            else if (option == 3 && option2 == 6 || option == 6 && option2 == 3)
            {
                amount = amount + 800;
            }
            else if (option == 3 && option2 == 7 || option == 7 && option2 == 3)
            {
                amount = amount + 3500;
            }
            else if (option == 3 && option2 == 8 || option == 8 && option2 == 3)
            {
                amount = amount + 5100;
            }
            else if (option == 3 && option2 == 9 || option == 9 && option2 == 3)
            {
                amount = amount + 2100;
            }
            else if (option == 3 && option2 == 10 || option == 10 && option2 == 3)
            {
                amount = amount + 4000;
            }
            else if (option == 3 && option2 == 11 || option == 11 && option2 == 3)
            {
                amount = amount + 2700;
            }
            else if (option == 4 && option2 == 5 || option == 5 && option2 == 4)
            {
                amount = amount + 5500;
            }
            else if (option == 4 && option2 == 6 || option == 6 && option2 == 4)
            {
                amount = amount + 3000;
            }
            else if (option == 4 && option2 == 7 || option == 7 && option2 == 4)
            {
                amount = amount + 960;
            }
            else if (option == 4 && option2 == 8 || option == 8 && option2 == 4)
            {
                amount = amount + 8000;
            }
            else if (option == 4 && option2 == 9 || option == 9 && option2 == 4)
            {
                amount = amount + 2100;
            }
            else if (option == 4 && option2 == 10 || option == 10 && option2 == 4)
            {
                amount = amount + 1200;
            }
            else if (option == 4 && option2 == 11 || option == 11 && option2 == 4)
            {
                amount = amount + 4200;
            }
            else if (option == 5 && option2 == 6 || option == 6 && option2 == 5)
            {
                amount = amount + 5000;
            }
            else if (option == 5 && option2 == 7 || option == 7 && option2 == 5)
            {
                amount = amount + 8200;
            }
            else if (option == 5 && option2 == 8 || option == 8 && option2 == 5)
            {
                amount = amount + 720;
            }
            else if (option == 5 && option2 == 9 || option == 9 && option2 == 5)
            {
                amount = amount + 6500;
            }
            else if (option == 5 && option2 == 10 || option == 10 && option2 == 5)
            {
                amount = amount + 7850;
            }
            else if (option == 5 && option2 == 11 || option == 11 && option2 == 5)
            {
                amount = amount + 1500;
            }
            else if (option == 6 && option2 == 7 || option == 7 && option2 == 6)
            {
                amount = amount + 5000;
            }
            else if (option == 6 && option2 == 8 || option == 8 && option2 == 6)
            {
                amount = amount + 5150;
            }
            else if (option == 6 && option2 == 9 || option == 9 && option2 == 6)
            {
                amount = amount + 880;
            }
            else if (option == 6 && option2 == 10 || option == 10 && option2 == 6)
            {
                amount = amount + 2000;
            }
            else if (option == 6 && option2 == 11 || option == 11 && option2 == 6)
            {
                amount = amount + 4500;
            }
            else if (option == 7 && option2 == 8 || option == 8 && option2 == 7)
            {
                amount = amount + 8250;
            }
            else if (option == 7 && option2 == 9 || option == 9 && option2 == 7)
            {
                amount = amount + 2000;
            }
            else if (option == 7 && option2 == 10 || option == 10 && option2 == 7)
            {
                amount = amount + 1450;
            }
            else if (option == 7 && option2 == 11 || option == 11 && option2 == 7)
            {
                amount = amount + 6800;
            }
            else if (option == 8 && option2 == 9 || option == 9 && option2 == 8)
            {
                amount = amount + 7600;
            }
            else if (option == 8 && option2 == 10 || option == 10 && option2 == 8)
            {
                amount = amount + 9700;
            }
            else if (option == 8 && option2 == 11 || option == 11 && option2 == 8)
            {
                amount = amount + 20500;
            }
            else if (option == 9 && option2 == 10 || option == 10 && option2 == 9)
            {
                amount = amount + 2000;
            }
            else if (option == 9 && option2 == 11 || option == 11 && option2 == 9)
            {
                amount = amount + 4400;
            }
            else if (option == 10 && option2 == 11 || option == 11 && option2 == 10)
            {
                amount = amount + 6400;
            }
            else
            {
                cout << "Invalid option chosen!!" << endl;
            }
        }
        else if (choice == 'b' || choice == 'B')
        {

            cout << "Enter Departure Date: ";
            cin >> departure_date;
            cout << "Enter Departure Time: ";
            cin >> departure_time;
            cout << "Enter Arrival Date: ";
            cin >> arrival_time;
            cout << "Enter the total number of passengers: ";
            cin >> total_passengers;
            cout << "Select Departure City: " << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "Press " << i + 1 << " for " << departure_city[i] << endl;
            }
            cin >> option;
            cout << "=================================================" << endl;
            cout << "Select Arrival City: " << endl;
            for (int i = 0; i < 11; i++)
            {
                cout << "Press " << i + 1 << " for " << arrival_city[i] << endl;
            }
            cin >> option2;
            cout << "===================================================" << endl;
            if (option == option2)
            {
                cout << "Invalid Route." << endl;
            }
            else if (option == 1 && option2 == 2 || option2 == 1 && option == 2)
            {
                amount = amount + 1900;
            }
            else if (option == 1 && option2 == 3 || option == 3 && option2 == 1)
            {
                amount = amount + 1800;
            }
            else if (option == 1 && option2 == 4 || option == 4 && option2 == 1)
            {
                amount = amount + 2100;
            }
            else if (option == 1 && option2 == 5 || option == 5 && option2 == 1)
            {
                amount = amount + 5500;
            }
            else if (option == 1 && option2 == 6 || option == 6 && option2 == 1)
            {
                amount = amount + 750;
            }
            else if (option == 1 && option2 == 7 || option == 1 && option2 == 3)
            {
                amount = amount + 2300;
            }
            else if (option == 1 && option2 == 8 || option == 8 && option2 == 1)
            {
                amount = amount + 5000;
            }
            else if (option == 1 && option2 == 9 || option == 9 && option2 == 1)
            {
                amount = amount + 400;
            }
            else if (option == 1 && option2 == 10 || option == 10 && option2 == 1)
            {
                amount = amount + 2350;
            }
            else if (option == 1 && option2 == 11 || option == 11 && option2 == 1)
            {
                amount = amount + 4000;
            }
            else if (option == 2 && option2 == 3 || option == 3 && option2 == 2)
            {
                amount = amount + 2200;
            }
            else if (option == 2 && option2 == 4 || option == 4 && option2 == 2)
            {
                amount = amount + 820;
            }
            else if (option == 2 && option2 == 5 || option == 5 && option2 == 2)
            {
                amount = amount + 6000;
            }
            else if (option == 2 && option2 == 6 || option == 6 && option2 == 2)
            {
                amount = amount + 1750;
            }
            else if (option == 2 && option2 == 7 || option == 7 && option2 == 2)
            {
                amount = amount + 840;
            }
            else if (option == 2 && option2 == 8 || option == 8 && option2 == 2)
            {
                amount = amount + 5300;
            }
            else if (option == 2 && option2 == 9 || option == 9 && option2 == 2)
            {
                amount = amount + 1460;
            }
            else if (option == 2 && option2 == 10 || option == 10 && option2 == 2)
            {
                amount = amount + 720;
            }
            else if (option == 2 && option2 == 11 || option == 11 && option2 == 2)
            {
                amount = amount + 3500;
            }

            else if (option == 3 && option2 == 4 || option == 4 && option2 == 3)
            {
                amount = amount + 2600;
            }
            else if (option == 3 && option2 == 5 || option == 3 && option2 == 5)
            {
                amount = amount + 3200;
            }
            else if (option == 3 && option2 == 6 || option == 6 && option2 == 3)
            {
                amount = amount + 800;
            }
            else if (option == 3 && option2 == 7 || option == 7 && option2 == 3)
            {
                amount = amount + 3500;
            }
            else if (option == 3 && option2 == 8 || option == 8 && option2 == 3)
            {
                amount = amount + 5100;
            }
            else if (option == 3 && option2 == 9 || option == 9 && option2 == 3)
            {
                amount = amount + 2100;
            }
            else if (option == 3 && option2 == 10 || option == 10 && option2 == 3)
            {
                amount = amount + 4000;
            }
            else if (option == 3 && option2 == 11 || option == 11 && option2 == 3)
            {
                amount = amount + 2700;
            }
            else if (option == 4 && option2 == 5 || option == 5 && option2 == 4)
            {
                amount = amount + 5500;
            }
            else if (option == 4 && option2 == 6 || option == 6 && option2 == 4)
            {
                amount = amount + 3000;
            }
            else if (option == 4 && option2 == 7 || option == 7 && option2 == 4)
            {
                amount = amount + 960;
            }
            else if (option == 4 && option2 == 8 || option == 8 && option2 == 4)
            {
                amount = amount + 8000;
            }
            else if (option == 4 && option2 == 9 || option == 9 && option2 == 4)
            {
                amount = amount + 2100;
            }
            else if (option == 4 && option2 == 10 || option == 10 && option2 == 4)
            {
                amount = amount + 1200;
            }
            else if (option == 4 && option2 == 11 || option == 11 && option2 == 4)
            {
                amount = amount + 4200;
            }
            else if (option == 5 && option2 == 6 || option == 6 && option2 == 5)
            {
                amount = amount + 5000;
            }
            else if (option == 5 && option2 == 7 || option == 7 && option2 == 5)
            {
                amount = amount + 8200;
            }
            else if (option == 5 && option2 == 8 || option == 8 && option2 == 5)
            {
                amount = amount + 720;
            }
            else if (option == 5 && option2 == 9 || option == 9 && option2 == 5)
            {
                amount = amount + 6500;
            }
            else if (option == 5 && option2 == 10 || option == 10 && option2 == 5)
            {
                amount = amount + 7850;
            }
            else if (option == 5 && option2 == 11 || option == 11 && option2 == 5)
            {
                amount = amount + 1500;
            }
            else if (option == 6 && option2 == 7 || option == 7 && option2 == 6)
            {
                amount = amount + 5000;
            }
            else if (option == 6 && option2 == 8 || option == 8 && option2 == 6)
            {
                amount = amount + 5150;
            }
            else if (option == 6 && option2 == 9 || option == 9 && option2 == 6)
            {
                amount = amount + 880;
            }
            else if (option == 6 && option2 == 10 || option == 10 && option2 == 6)
            {
                amount = amount + 2000;
            }
            else if (option == 6 && option2 == 11 || option == 11 && option2 == 6)
            {
                amount = amount + 4500;
            }
            else if (option == 7 && option2 == 8 || option == 8 && option2 == 7)
            {
                amount = amount + 8250;
            }
            else if (option == 7 && option2 == 9 || option == 9 && option2 == 7)
            {
                amount = amount + 2000;
            }
            else if (option == 7 && option2 == 10 || option == 10 && option2 == 7)
            {
                amount = amount + 1450;
            }
            else if (option == 7 && option2 == 11 || option == 11 && option2 == 7)
            {
                amount = amount + 6800;
            }
            else if (option == 8 && option2 == 9 || option == 9 && option2 == 8)
            {
                amount = amount + 7600;
            }
            else if (option == 8 && option2 == 10 || option == 10 && option2 == 8)
            {
                amount = amount + 9700;
            }
            else if (option == 8 && option2 == 11 || option == 11 && option2 == 8)
            {
                amount = amount + 20500;
            }
            else if (option == 9 && option2 == 10 || option == 10 && option2 == 9)
            {
                amount = amount + 2000;
            }
            else if (option == 9 && option2 == 11 || option == 11 && option2 == 9)
            {
                amount = amount + 4400;
            }
            else if (option == 10 && option2 == 11 || option == 11 && option2 == 10)
            {
                amount = amount + 6400;
            }
            else
            {
                cout << "Invalid option chosen!!" << endl;
            }
            amount = amount * 2;
            amount = total_passengers * amount;
        }
    }

    cout << "=================================" << endl;
    if (b.departure_time > 6)
    {
        b.amount = b.amount + b.amount * 0.1;
    }
    else if (b.total_passengers > 3)
    {
        cout << "You have availed 20% discount!!!" << endl;
        b.amount = b.amount - b.amount * 0.2;
    }
    else if (b.amount > 5000)
    {
        cout << "You have availed 20% discount!!!" << endl;
        b.amount = b.amount - b.amount * 0.2;
        cout << "Rs";
    }
    else
    {
        b.amount;
    }
    b.amount = b.total_passengers * b.amount;

    cout << "The net amount is: " << b.amount << "Rs" << endl;
    cout << "Thank You for choosing Bookme:)" << endl;
}
    void bookseat1()
    {
      Bus b;
        while (true)
        {
            cout << "\nMenu:\n1. Display Available Seats\n2. Book a Seat\n3. Exit and display\n";
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                displaySeats();
                break;
            case 2:
                int seatNumber;
                cout << "Enter seat number to book: ";
                cin >> seatNumber;
                bookSeat(seatNumber);
                break;
            case 3:
                cout << "Exiting program.\n";
               displayInfo( b);
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main()
{
    Bus b;
  
    b.Calculation();
    b.bookseat1();
    b.displayInfo(b);
}
