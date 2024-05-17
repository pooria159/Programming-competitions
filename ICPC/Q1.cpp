#include <bits/stdc++.h> 
using namespace std;

struct Point {
    int x, y;
};

// Returns true if the point p lies inside the polygon 
bool isInside(Point p, Point polygon[], int n) 
{ 
    int i, j; 
    bool inside = false; 
  
    for (i = 0, j = n - 1; i < n; j = i++) { 
        if ((polygon[i].y > p.y) != (polygon[j].y > p.y)) {
            if (p.x <= polygon[i].x || p.x <= polygon[j].x)
                if ((polygon[i].x - p.x) * (polygon[j].y - polygon[i].y) ==  
                           (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y))  
                    inside ^= true; 
        } 
    } 
  
    return inside; 
} 

// Returns minimum number of additional police required 
int minPolice(Point police[], int n, Point thieves[],  
                int m, Point addPolice[]) 
{ 
    // Create a polygon with initial police officers 
    Point polygon[n]; 
    for (int i = 0; i < n; i++) 
        polygon[i] = police[i]; 
  
    // Check if any thief is inside the polygon 
    int ans = 0; 
    for (int i = 0; i < m; i++) { 
        if (!isInside(thieves[i], polygon, n)) { 
            polygon[n++] = addPolice[ans++]; 
  
            // Add new police and check again 
            i--; 
        } 
    } 
    return ans; 
} 

int main() 
{ 
    int t; cin >> t;
    while (t--) { 
        int n, m; 
        cin >> n >> m; 
        Point police[n], thieves[m], addPolice[m]; 
        for (int i = 0; i < n; i++) 
            cin >> police[i].x >> police[i].y; 
  
        for (int i = 0; i < m; i++) 
            cin >> thieves[i].x >> thieves[i].y; 
  
        cout << minPolice(police, n, thieves, m, addPolice) << endl; 
    } 
}