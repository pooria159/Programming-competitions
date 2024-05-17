#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> genders;
        int aviaries = 0;
        
        for (int i = 0; i < n; i++) {
            int action;
            cin >> action;
            
            if (action == 1) {
                int gender;
                cin >> gender;
                genders.push_back(gender);
            } else {
                if (genders.size() > 1 && count(genders.begin(), genders.end(), genders[0]) != genders.size()) {
                    aviaries++;
                }
                genders.erase(unique(genders.begin(), genders.end()), genders.end());
            }
        }
        
        if (genders.size() > 1 && count(genders.begin(), genders.end(), genders[0]) != genders.size()) {
            aviaries++;
        }
        
        cout << aviaries << endl;
    }
    
    return 0;
}
