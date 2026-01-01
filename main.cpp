#include <iostream>
#include <string>

#include "need.h"
#include "algorithm_analysis.h"
#include "show_problems_h.h"
#include "test_algorithms.h"
#include "competition_results.h"
#include "about_us.h"

using namespace std;

int main() {
    int choice;
    
    do {
        clearScreen();
        displayHeader(); // need.h
        displayMenu();
        
        cout << "\nEnter your choice (1-8): ";
        cin >> choice;
        cin.ignore();  // Clear newline from buffer
        
        switch(choice) {
            case 1:
                showContestants();
                break;
            case 2:
                showJudgesRules();
                break;
            case 3:
                testAlgorithms();
                break;
            case 4:
                runCompetition();
                break;
            case 5:
                showAlgorithmDetails();
                break;
            case 6:
                showProblem();
                break;
            case 7:
                showWinner();
                break;
            case 8:
                showAboutUs();
                break;
            
            default:

            
                cout << "\nInvalid choice! Please enter 1-7.\n";
                waitForEnter();
                break;
        }
        
    } while (choice != 7);
    
    return 0;
}