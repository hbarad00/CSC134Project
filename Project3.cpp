#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayTitle(){ 
     string comp = "Computer Hardware Graphics Quality Recommendation Tool"; 
     cout<<"\n\n"<<comp<<"\n\n"; 
} 

string getResolutionString(int choice){
      string Monitor_Re;
      if (choice == 1) {
          Monitor_Re = "1280X720"; 
	   }else if (choice == 2) { 
         Monitor_Re = "1920x1080"; 
       }else if (choice == 3) {
         Monitor_Re = "2560x1440"; 
       }else if (choice == 4) {
          Monitor_Re = "3840x2160"; 
	   }
    return Monitor_Re; 
}
 
float getMultiplierValue(int choice){
     float Multiplier = 0; 
     if (choice == 1) { 
         Multiplier = 1; 
} else if (choice == 2) {
       Multiplier = 0.75;  
} else if (choice == 3) {
       Multiplier = 0.55; 
} else if (choice == 4) {
        Multiplier = 0.35; 
} 
return Multiplier;
 } 
 
double calculatePerformanceScore(double GPU,double CPU,double Multiplier,double CORES){ 
    return ((5 * GPU) + (CORES * CPU)) * Multiplier; 
} 

string getRecommendedQuality(double Performance){ 
     if (Performance > 17000) { 
        return "Ultra"; 
      } else if (Performance > 15000 && Performance <= 17000) { 
        return "High"; 
      } else if (Performance > 13000 && Performance <= 15000) { 
        return "Medium";
      } else if (Performance > 11000 && Performance <= 13000) { 
        return "Low"; 
      } else if (Performance <= 11000){
        return "Unable to Play";
      }
      return "";
 }

void displayInformation(double GPU, double CPU,double CORES,string Monitor_Re, 
       double Performance,string Graphics_Q) {
       	
    cout << "Computer Hardware Graphics Quality Tool \n\n"; 
    cout << "GPU clock speed: " << GPU << "MHz" << endl; 
    cout << "CPU clock speed: " << CPU << "MHz" << endl;
    cout << "Number of cores:" << CORES << endl; 
    
    cout << "Monitor Resolution:" << Monitor_Re << endl;
    cout << "Performance Score:" << Performance << endl; 
    cout << "Recommended Graphics Quality: " << Graphics_Q << endl; 
    
}
 int main() { 
// Step 1 Add code that prompts the user for the number of computers. //
    int Computers = 0;
    float highPerf = 0; 
    float lowPerf = 99999;
    int counter;
    counter++; 
    do { 
        cout << "Enter the number of computers you wish to enter information for: ";
        cin >> Computers; 
        if (Computers < 1) { 
            cout << "Value should not be less than 1. Please try again.\n"; 
        } 
    } while (Computers < 1); 

// Enter information for each computer//
   while (Computers > 0) { 
        //Display the Computer String//
        displayTitle();
        float choice, GPU, CPU, CORES, Multiplier; 

//Step 1 clock speed of graphics card// 
do { 
    cout << "Please enter the clock speed (in Megahertz) of your graphics card: " ; 
    cin >> GPU; 
    cout << endl;
    if (GPU < 800 || GPU > 2000) {
        cout << "GPU clock speed should lie between 800 and 2000 MHz. Please try again. \n"; 
   } 
} while (GPU < 800 || GPU > 2000); 

//Step 2 clock speed of processor// 
    do { 
         cout << "Please enter the clock speed (in Megahertz) of your processor: ";
         cin >> CPU;
         cout << endl; 
         if (CPU < 1000 || CPU > 5500){ 
             cout << "CPU clock speed should lie between 1000 and 5500 MHz. "
                     "Please try again. \n"; 
        } 
    } while (CPU < 1000 || CPU > 5500);

//Step 3 number of Cores// 
    do { 
          cout << "Please enter the number of cores of your processor:";
          cin >> CORES;
          cout << endl;
          if (CORES < 1 || CORES > 16) { 
              cout << "Number of cores should lie between 1 and 16. Please try again. \n";
       } 
    } while (CORES < 1 || CORES > 16); 

// Step 4 monitor resolution// 
    do { 
          cout << "What is the resolution of your monitor?\n"; 
          cout << "1. 1280 x 720 \n" 
               << "2. 1920 x 1080 \n"
               << "3. 2560 x 1440 \n" 
               << "4. 3840 x 2160 \n" 
               << "Please select from the option above: "; 
          cin >> choice;
          cout << endl;
          if (choice < 1 || choice > 4) { 
              cout << "Select a value between 1 and 4. Please try again.\n"; 
       } 
   } while (choice < 1 || choice > 4);
   string Monitor_Re = getResolutionString(choice);
   Multiplier = getMultiplierValue(choice);
 
    //Step 6 calculate a Performance Score//
    double Performance = calculatePerformanceScore(GPU,CPU,Multiplier,CORES);
    //make object of string for store Quality of Computer Graphics/ 
    // Step 7 check Performance score and find a Quality of Graphics/ 
    string Graphics_Q = getRecommendedQuality(Performance);



//The highest and lowest performance variables// 

        if (Performance > highPerf || highPerf == 0) 
            highPerf = Performance; 
        if (Performance < lowPerf || lowPerf == 0) 
            lowPerf = Performance; 
        displayInformation(GPU,CPU,CORES,Monitor_Re,Performance,Graphics_Q);
           Computers--;
       }
 
 // Displaying the highest and lowest performance score 
    cout << endl;
    cout << "Highest Performance Score = " << highPerf << endl; 
    cout << "Lowest Performance Score = " << lowPerf << endl; 

    return 0; 
}
