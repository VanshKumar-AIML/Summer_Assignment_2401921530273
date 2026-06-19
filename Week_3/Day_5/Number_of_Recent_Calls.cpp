#include<iostream>
#include<queue>
using namespace std;

class RecentCounter {
private:
    queue<int> q;   // store timestamps
public:
    RecentCounter() {
        // Default constructor
    }
    
    int ping(int t) {
        // Add current ping
        q.push(t);

        // Remove all pings older than t - 3000
        while (!q.empty() && q.front() < t - 3000) 
            q.pop();

        // Return number of valid pings
        return q.size();
    }
};

int main() {
    RecentCounter rc ;      // object created
    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;

    return 0;
}