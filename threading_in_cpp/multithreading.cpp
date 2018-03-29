#include <thread>
#include <iostream>
#include <chrono> // time constants
// 1. Thread creation
// 2. Mutual exclusion
// 3. Futures
// 4. Conditional variables
// 5. Execution policy
//


//template < class Function , class... Args >
// explicit thread( Function&& f, Args&&... args );


void join(); // Removes thread
void detach(); // Can detach threads to continue?
bool joinable(); // Can a thread join?
//get_id() // Gets ID of thread
//hardware_concurrency(); // ?
//

// Exemple på receptionist och besökare. Ska utföras i en speciell ordning

using namespace std;
using namespace std::chrono_literals;

void receptionist()
{
    cout << "R: Welcome , how can I help you?" << endl;
    cout << "R: Please enter , he's expecting you." << endl;
}
class Visitor
{
public:
    void operator()() const
    {
        cout << "V: Hi, I'm here to meet Mr X" << endl;
        cout << "V: Thank you" << endl;
    }
};

int main()
{
    thread r(receptionist); // free function
    thread v(Visitor{}); // function object
    thread f([](){ cout << "Friend: Hi!" << endl; }); // lambda function
    v.join(); // will wait for thread v to complete
    r.detach(); // makes you responsible ...
    // terminate due to f not join'ed or detach'ed
    cout << "Main sleep" << endl;
    this_thread::sleep_for(2s); // pause main thread for 2 seconds
    cout << "Main done" << endl;
    }


// Needs -lpthread as compiler flag


// 2. std::mutex


// std::yield(), vad händer om två trådar väntar på ett lås och yield() används i en tredje?
// Är båda trådarna som väntar garanterade att exekvera innan den tredje återupptar?
// Vad skulle hända om exemplet var i en while(true)? Anledning till yield()? 




// 3, Future
// std::promise




