#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
class Bus
{
private:
    vector<bool> seats;

public:
    Bus() : seats(47, false) {}

    void displaySeats()
    {
        cout << "Available seats:\n";
        for (int i = 0; i < 47; ++i)
        {
            cout << setw(3) << i + 1 << (seats[i] ? "  Booked " : " Available ");
            if ((i + 1) % 5 == 0)
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

   void cancelSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > 47) {
        cout << "Invalid seat number.\n";
        return;
    }

    if (!seats[seatNumber - 1]) {
        cout << "Seat " << seatNumber << " is already available.\n";
    }
    else {
        seats[seatNumber - 1] = false;
        cout << "Seat " << seatNumber << " cancelled successfully.\n";
        
        // Remove ticket information from file
        ifstream inFile("seat_bookings.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file for reading!" << endl;
            exit(EXIT_FAILURE);
        }

        ofstream outFile("temp.txt");
        if (!outFile) {
            cerr << "Error: Unable to open file for writing!" << endl;
            exit(EXIT_FAILURE);
        }

        int ticket;
        bool removed = false;
        while (inFile >> ticket) {
            if (ticket != seatNumber) {
                outFile << ticket << endl;
            } else {
                removed = true;
            }
        }

        inFile.close();
        outFile.close();

        if (!removed) {
            cout << "Ticket for seat " << seatNumber << " not found in the file.\n";
            remove("temp.txt");
        } else {
            remove("seat_bookings.txt");
            rename("temp.txt", "seat_bookings.txt");
        }
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
        cout << "Welcome to Swift Away Bus services!!" << endl;
        cout << "Enter your CNIC number: ";
        cin >> cnicno;
        cout << "Enter your gender: ";
        cin >> gender;
        cout << "Enter your contact number: ";
        cin >> contactno;
        cout << "Press a for Oneway." << endl;
        cout << "Press b for Roundtrip." << endl;
        cin >> choice;
        ofstream outFile("C:\\Users\\ASPIRE\\Documents\\BUSDetails.txt");
        if (outFile.is_open())
        {
            outFile << "CNIC Number: " << cnicno << endl;
            outFile << "Gender: " << gender << endl;
            outFile << "Contact Number: " << contactno << endl;

            if (choice == 'a' || choice == 'A')
            {
                cout << "Enter Departure Date: ";
                cin >> departure_date;
                cout << "Enter Departure Time: ";
                cin >> departure_time;
                cout << "Enter the total number of passengers: ";
                cin >> total_passengers;
                outFile << "Departure Date: " << departure_date << endl;
                outFile << "Departure Time: " << departure_time << endl;
                outFile << "Total Passengers: " << total_passengers << endl;
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
                    outFile << "Invalid Route" << endl;
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
                outFile << "Amount: " << amount << endl;
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
                    outFile << "Invalid choice" << endl;
                }
                amount = amount * 2;
                amount = total_passengers * amount;
            }
            outFile.close();
        }
        else
        {
            cout << "Error: Unable to open file!" << endl;
        }
    }
    void displayInfo()
    {
        ifstream inFile("C:\\Users\\ASPIRE\\Documents\\BUSDetails.txt");
        if (!inFile)
        {
            cerr << "Error: Unable to open file for reading!" << endl;
            return;
        }

        inFile >> cnicno >> gender >> contactno >> choice;
        if (choice == 'b' || choice == 'B')
        {
            inFile >> departure_date >> departure_time >> arrival_date >> total_passengers;
        }
        else
        {
            inFile >> departure_date >> departure_time >> total_passengers;
        }

        for (int i = 0; i < 11; i++)
        {
            inFile >> departure_city[i];
        }
        for (int i = 0; i < 11; i++)
        {
            inFile >> arrival_city[i];
        }

        inFile.close();

        // Display the read data
        cout << "=================================" << endl;
        cout << "Showing all details......" << endl;
        cout << "Your CNIC no is: " << cnicno << endl;
        cout << "Your Gender is: " << gender << endl;
        cout << "Your Contact no is: " << contactno << endl;
        if (choice == 'b' || choice == 'B')
        {
            cout << "The departure date is: " << departure_date << endl;
            cout << "The departure time is: " << departure_time << endl;
            cout << "Total no of Passengers are: " << total_passengers << endl;
            cout << "The departure city is: " << departure_city[option - 1] << endl;
            cout << "The arrival city is: " << arrival_city[option2 - 1] << endl;
            cout << "The arrival date is: " << arrival_date << endl;
        }
        else
        {
            cout << "The departure date is: " << departure_date << endl;
            cout << "The departure time is: " << departure_time << endl;
            cout << "Total no of Passengers are: " << total_passengers << endl;
            cout << "The departure city is: " << departure_city[option - 1] << endl;
            cout << "The arrival city is: " << arrival_city[option2 - 1] << endl;
        }
        cout << "=================================" << endl;
        if (departure_time > 6)
        {
            amount = amount + amount * 0.1;
        }
        else if (total_passengers > 3)
        {
            cout << "You have availed 20% discount!!!" << endl;
            amount = amount - amount * 0.2;
        }
        else if (amount > 5000)
        {
            cout << "You have availed 20% discount!!!" << endl;
            amount = amount - amount * 0.2;
            cout << "Rs";
        }
        else
        {
            amount;
        }
        amount = total_passengers * amount;

        cout << "The net amount is: " << amount << "Rs" << endl;
        cout << "Thank You for choosing Swift Away:)" << endl;
    }
      void writeSeatBooking(int sn)
            {
                ofstream outFile("seat_bookings.txt", ios::app);
                if (!outFile)
                {
                    cerr << "Error: Unable to open file for writing!" << endl;
                    exit(EXIT_FAILURE);
                }
                outFile << "Seat booked: " << sn << endl;
                outFile.close();
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
                writeSeatBooking(seatNumber);
                break;
            case 3:
                cout << "Exiting program.\n";
                displayInfo();
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

class App_login : public Bus
{
private:
    string name, paddres[25], pname[25], email, gender[25], pass, log_pass, new_pass, temp_pass, from_city, to_city, date;
    int cnic[25], pcnic[25], rdate, age[25], pph_no[25], cancel_booking, ph_no, choice, new_pin, city_select, op = 0, Attempt = 0;
    int class_, no_of_tickets, Fare, num_of_passengers, ddate;
    char fp, p_choice;

public:
    int generatePin()
    {
        srand(time(nullptr));
        return rand() % 9000 + 1000;
    }

    void changePassword(string newName, string newPassword)
    {
        ifstream readfile("C:\\Users\\ASPIRE\\Documents\\PlaneAccoutDetails.txt");
        ofstream tempfile("C:\\Users\\ASPIRE\\Documents\\tempfile.txt");

        string username, password, email, phone, temp_pass;
        bool found = false;

        while (readfile >> username >> password >> email >> phone >> temp_pass)
        {
            if (username == newName)
            {
                password = newPassword;
                found = true;
            }
            tempfile << username << " " << password << " " << email << " " << phone << " " << temp_pass << endl;
        }

        readfile.close();
        tempfile.close();

        if (found)
        {
            remove("C:\\Users\\ASPIRE\\Documents\\PlaneAccoutDetails.txt");
            rename("C:\\Users\\ASPIRE\\Documents\\tempfile.txt", "C:\\Users\\ASPIRE\\Documents\\PlaneAccoutDetails.txt");
        }
        else
        {
            remove("C:\\Users\\ASPIRE\\Documents\\tempfile.txt");
        }
    }
    bool login()
    {
        cout << "\t\t Login \t\t\n";

        cout << "Enter your username : \n";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your password: \n";
        cin >> log_pass;

        ifstream readfile("C:\\Users\\ASPIRE\\Documents\\PlaneAccoutDetails.txt");
        string cname, cpass, ctemp_pass;
        bool found = false;

        while (readfile >> cname >> cpass >> email >> ph_no >> ctemp_pass)
        {
            if (cname == name && cpass == log_pass)
            {
                found = true;
                break;
            }
        }

        readfile.close();

        if (found)
        {
            cout << "Login Successful!\n";
            return true;
        }
        else
        {
            cout << "Invalid password!\n";
            cout << "Click 'f' if you forgot your password: ";
            cin >> fp;
            fp = tolower(fp);
            if (fp == 'f')
            {
                do
                {
                    cout << "Enter your recovery pin: ";
                    cin >> new_pin;
                    ifstream readfile("C:\\Users\\ASPIRE\\Documents\\PlaneAccoutDetails.txt");
                    bool found = false;

                    while (readfile >> cname >> cpass >> email >> ph_no >> ctemp_pass)
                    {
                        if (cname == name && stoi(ctemp_pass) == new_pin)
                        {
                            found = true;
                            break;
                        }
                    }

                    readfile.close();

                    if (found)
                    {
                        cout << "Enter new password: ";
                        cin >> new_pass;
                        changePassword(name, new_pass);
                        cout << "Your password has been changed!\n";
                        return login();
                    }
                    else
                    {
                        cout << "Invalid recovery pin! Try Again !\n";
                        Attempt++;
                    }
                } while (Attempt < 3);
            }
            else
            {
                cout << "Invalid Entry\n";
                return false;
            }
            readfile.close();
        }
        return false;
    }

    void signup()
    {
        cout << "\t\t SignUp \t\t\n";
        cout << "Enter your username : \n";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your password: \n";
        cin >> pass;
        cout << "Enter your email: \n";
        cin >> email;
        cout << "Enter your phone number: \n";
        cin >> ph_no;

        temp_pass = to_string(generatePin());
        cout << "Your temporary pin is : " << temp_pass << endl;

    }
    void booking_confirm()
    {
        for (int i = 0; i < num_of_passengers; i++)
        {
            cout << "Enter data of " << i + 1 << "person : ";
            cout << "\nEnter the passenger name: \n";
            cin >> pname[i];
            cout << "Enter the passenger age: \n";
            cin >> age[i];
            cout << "Enter the passenger gender: \n";
            cin >> gender[i];
            cout << "Enter the passenger phone number: \n";
            cin >> pph_no[i];
            cout << "Enter the passenger cnic: \n";
            cin >> pcnic[i];
            cout << "Enter the passenger address: \n";
            cin >> paddres[i];
        }

        cout << "\nBooked succesfully !";
    }
    void cancelBooking()
    {
        char choice;
        do
        {
            cout << "Enter the flight number of the booking you want to cancel: ";
            cin >> cancel_booking;

            if (cancel_booking == city_select)
            {
                cout << "Your booking for flight number " << cancel_booking << " has been cancelled!" << endl;
            }
            else
            {
                cout << "Invalid flight number! Please try again." << endl;
            }

            cout << "Do you want to cancel another booking? (Y/N): ";
            cin >> choice;
        } while (toupper(choice) == 'Y');
    }

void planebooking() {
 


    cout << "Welcome to Swift Away Air services!!" << endl;
    cout << "Click 'a' for ROUND TRIP" << endl;
    cout << "Click 'b' for ONE WAY" << endl;
    cin >> p_choice;
         cout << "....AVAILABLE FLIGHTS....";
        cout << "\n1.Multan to Lahore     6.Lahore to Multan\n"
             << "2.Multan to Islamabad         7.Lahore to Karachi\n"
             << "3.Multan to Peshawar          8.Lahore to Islamabad\n"
             << "4.Multan to Karachi           9.Lahore to Peshawar\n"
             << "5.Multan to Faislabad         10.Lahore to Faislabad\n"
             << "-----------------------------------------------------\n"
             << "11.Islamabad to Multan        16.Karachi to Faislabad\n"
             << "12.Islamabad to Karachi       17.Karachi to Multan\n"
             << "13.Islamabad to Lahore        18.Karachi to Islamabad\n"
             << "14.Islamabad to Peshawar      19.Karachi to Lahore\n"
             << "15.Islamabad to Faislabad     20.Karachi to Peshawar\n"
             << "------------------------------------------------------\n"
             << "21.Faislabad to Karachi       26.Peshawar to Faislabad\n"
             << "22.Faislabad to Multan        27.Peshawar to Multan\n"
             << "23.Faislabad to Islamabad     28.Peshawar to Islamabad\n"
             << "24.Faislabad to Lahore        29.Peshawar to Lahore\n"
             << "25.Faislabad to Peshawar      30.Peshawar to Peshawar\n";
   
    

    cout << "\nEnter your desired flight no: ";
    cin >> city_select;

    if (p_choice == 'a') {
        do {
            cout << "\nDeparture Date : ";
            cin >> ddate;
            cout << "Returning Date : ";
            cin >> rdate;

            if (ddate > 31 || rdate > 31 || ddate <= 0 || rdate <= 0) {
                cout << "Invalid date! Please enter a date between 1 and 31." << endl;
            }
        } while (ddate > 31 || rdate > 31 || ddate <= 0 || rdate <= 0);
    } else if (p_choice == 'b') {
        cout << "\nDeparture Date : ";
        cin >> ddate;
    } else {
        cout << "Invalid option!";
    }

    cout << "Enter the number of Passengers: ";
    cin >> num_of_passengers;
    cout << "Enter the number of tickets: ";
    cin >> no_of_tickets;
    cout << "Select the class:\n";
    cout << "1. Economy\n";
    cout << "2. Business\n";
    cout << "3. Premium\n";
    cin >> class_;

    cout << "\n---------------------------";
    showplanbooking();
    booking_confirm();

    if (num_of_passengers > no_of_tickets) {
        cout << "Kindly enter number of tickets according to your passengers!";
    }

    
}
    void discount()
    {
        if (no_of_tickets >= 2 && no_of_tickets < 3)
        {
            cout << "You are eligible for 5% discount" << endl;
            Fare *= 0.95;
        }
        else if (no_of_tickets >= 3)
        {
            cout << "You are eligible for 10% discount" << endl;
            Fare *= 0.9;
        }
    }
    void showplanbooking()
    {
        if (city_select == 1 || city_select == 6)
        {
            if (class_ == 1)
            {
                Fare = 9000;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 12000;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 15000;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 2 || city_select == 11)
        {
            if (class_ == 1)
            {
                Fare = 16820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 25850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 35400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 3 || city_select == 27)
        {
            if (class_ == 1)
            {
                Fare = 13870;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 16850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 22400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 4 || city_select == 17)
        {
            if (class_ == 1)
            {
                Fare = 17820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 20850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 25400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 5 || city_select == 22)
        {
            if (class_ == 1)
            {
                Fare = 19520;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 20650;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 22250;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 7 || city_select == 19)
        {
            if (class_ == 1)
            {
                Fare = 24820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 26850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 39400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 8 || city_select == 13)
        {
            if (class_ == 1)
            {
                Fare = 18250;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 22850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 25350;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 9 || city_select == 29)
        {
            if (class_ == 1)
            {
                Fare = 13920;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 16850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 19400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 10 || city_select == 24)
        {
            if (class_ == 1)
            {
                Fare = 14250;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 16850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 19400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 12 || city_select == 18)
        {
            if (class_ == 1)
            {
                Fare = 20850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 25850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 30400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 14 || city_select == 28)
        {
            if (class_ == 1)
            {
                Fare = 9450;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 11450;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 14500;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 15 || city_select == 23)
        {
            if (class_ == 1)
            {
                Fare = 10820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 12850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 14400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 16 || city_select == 21)
        {
            if (class_ == 1)
            {
                Fare = 16820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 18850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 20400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 20 || city_select == 30)
        {
            if (class_ == 1)
            {
                Fare = 17820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 19850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 21400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else if (city_select == 25 || city_select == 26)
        {
            if (class_ == 1)
            {
                Fare = 15820;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 2)
            {
                Fare = 18850;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
            else if (class_ == 3)
            {
                Fare = 20400;
                discount();
                cout << " Flight Total Fare : " << Fare << endl;
            }
        }
        else
        {
            cout << "Invalid Flight no !!";
        }
    }
    void displayTicket()
    {
        for (int i = 0; i < num_of_passengers; i++)
        {

            cout << "\n---------- Ticket Details ----------\n";
            cout << "Route :                 " << city_select << endl;
            cout << "Departure Date:         " << ddate << endl;
            cout << "Return Date:            " << rdate << endl;
            cout << "Number of Passengers:   " << num_of_passengers << endl;
            cout << "Number of Tickets:      " << no_of_tickets << endl;
            if (class_ == 1)
            {
                cout << " Flight Type : Ecconomy" << endl;
            }
            else if (class_ == 2)
            {
                cout << " Flight Type : Buisness" << endl;
            }
            else if (class_ == 3)
            {
                cout << " Flight Type : Premium" << endl;
            }
            else
            {
                cout << "Invalid input" << endl;
            }
            Fare = Fare * no_of_tickets;
            cout << "\nTotal Fare: " << Fare << endl;
            cout << "------------------------------------\n";
        }
    }
    void display()
    {
        do
        {
            cout << "Press 1 for Login\n";
            cout << "Press 2 for SignUp\n";
            cout << "Press 3 for exit\n";
            cin >> choice;

            switch (choice)
            {
            case 1:
                if (login())
                {
                    cout << "click 1 for travel by air \n";
                    cout << "click 2 for travel by bus \n";
                    cin >> op;
                    switch (op)
                    {
                    case 1:
                        planebooking();
                        displayTicket();
                        break;
                    case 2:
                        Calculation();
                        bookseat1();
                        displayInfo();
                        break;
                    default:
                        cout << "Invalid option." << endl;
                        break;
                    }
                }
                break;
            case 2:
                signup();
                break;
            case 3:
                cout << "You have exited successfully!";
                exit(0);
                break;
            default:
                cout << "INVALID ENTRY\n";
                break;
            }
            cout << "Press any key to return to the main menu or c to cancel the ticket , 'E' to exit: ";
            char continueOption;
            cin >> continueOption;
            if (continueOption == 'E' || continueOption == 'e')
                exit(0);
            if (continueOption == 'C' || continueOption == 'c')
                cancelBooking();
            if (continueOption == 'd' || continueOption == 'D')
                display();

        } while (true);
    }
};

int main()
{
    App_login a1;
    a1.display();

    return 0;
}