#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

#include "sources/Board.hpp"
#include "sources/City.hpp"
#include "sources/Color.hpp"

#include "sources/Player.hpp"
#include "sources/Dispatcher.hpp"
#include "sources/FieldDoctor.hpp"
#include "sources/OperationsExpert.hpp"
#include "sources/Medic.hpp"
#include "sources/Researcher.hpp"
#include "sources/Scientist.hpp"
#include "sources/Virologist.hpp"




#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define MAGENTA "\033[35m"      /* Magenta */

using namespace pandemic;
using namespace std;

int main()
{
    pandemic::Board b1;

        b1[City::Algiers] = 5;
    // b1[City::Atlanta] = 4;
    // b1[City::Bangkok] = 3;
    // b1[City::BuenosAires] = 2;
    // b1[City::Delhi] = 1;

    Researcher david(b1,City::Washington);

    try {
        david.treat(City::Atlanta);
    } catch (const exception& e) {
        cout << e.what() << endl;
   }


            david.take_card(City::Tokyo) 
            .take_card(City::Washington) 
            .take_card(City::Istanbul)
            .take_card(City::Karachi)
            .take_card(City::Kolkata)
            .take_card(City::Kolkata) // Will do nothing
            .take_card(City::Moscow);


             david.take_card(City::Algiers);

            
            david.discover_cure(Color::Black);
            cout << boolalpha << b1.getCure(Color::Black) << endl;
            cout << b1.getCure(Color::Red) << endl;
            cout<< b1.getCure(Color::Blue) << endl;
            cout << b1.getCure(Color::Yellow) << endl;

        cout << b1[City::Algiers] << endl;

        david.take_card(City::Algiers);
       david.fly_direct(City::Algiers);
        david.treat(City::Algiers);

                cout << b1[City::Algiers] << endl;
    

        david.take_card(City::Atlanta)
            .take_card(City::London)
            .take_card(City::Milan)
            .take_card(City::Madrid)
            .take_card(City::Delhi)
            .take_card(City::Bangkok)
            .take_card(City::BuenosAires);

    cout << boolalpha << b1.is_clean() << endl;
    cout << b1 << endl;

    return 0;
}
