#include <iostream>
using namespace std;
int main()
{
    int gc_clock_speed = 0;   //clock speed of graphics card
    int proc_clock_speed = 0; //clock speed of processor
    int num_cores = 0;        //number of cores on the processor
    double multiplier = 1;    //multiplier based on resolution
    int option = 0;           //option of the resolution

    for(int run=1; run <7;run++)
    {
        //Scanning input from user
        cout << "Please enter the clock speed (in Megahertz) of your graphics card: ";
        cin >> gc_clock_speed;

        if (gc_clock_speed < 0)
        {
            cout << "Invalid graphics card speed entered. program will terminate.\n";
            continue;
        }

        cout << "Please enter the clock speed (in Megahertz) of your processor: ";
        cin >> proc_clock_speed;

        if (proc_clock_speed < 0)
        {
            cout << "Invalid processor speed entered. program will terminate.\n";
            continue;
        }

        cout << "Please enter the number of cores on your processor: ";
        cin >> num_cores;

        if (num_cores < 0)
        {
            cout << "Invalid number of cores entered. program will terminate.\n";
            continue;
        }

        cout << "What is the resolution of your monitor? \n";
        cout << "\t\t1. 1280 x 720\n";
        cout << "\t\t2. 1920 x 1080\n";
        cout << "\t\t3. 2560 x 1440\n";
        cout << "\t\t4. 3840 x 2160\n";
        cout << "Please select from the options above: ";
        cin >> option;

        if (option < 1 || option > 4)
        {
            cout << "Invalid Resolution menu choice. program will terminate.\n";
            continue;
        }

        cout << "\n\nComputer Hardware Graphics Quality Recommendation Tool\n";
        cout << "\nGPU Clock Speed: " << gc_clock_speed  << " MHz" << endl;
        cout << "CPU Clock Speed: " << proc_clock_speed << " MHz"  <<endl;
        cout << "Number of cores: " << num_cores << endl;
        cout << "Monitor Resolution: ";
        switch (option)
        {
        case 1:
            cout << "1280 x 720";
            multiplier = 1;
            break;
        case 2:
            cout << "1920 x 1080";
            multiplier = 0.75;
            break;
        case 3:
            cout << "2560 x 1440";
            multiplier = 0.55;
            break;
        case 4:
            cout << "3840 x 2160";
            multiplier = 0.35;
            break;
        }
        double score = ((5 * gc_clock_speed) + (num_cores * proc_clock_speed)) * multiplier;
        cout << "\nPerformance Score: " << score;
        cout << "\nRecommended Graphics Quality: ";
        if (score <= 11000)
        {
            cout << "Unable to Play\n";
        }
        else if (score <= 13000)
        {
            cout << "Low\n";
        }
        else if (score <= 15000)
        {
            cout << "Medium\n";
        }
        else if (score <= 17000)
        {
            cout << "High\n";
        }
        else if (score > 17000)
        {
            cout << "Ultra\n";
        }
    }

    cout << endl;
    return 0;
} //end of main() method
