#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define N_ 251000 
using namespace std; 

int n, Y[N_], X[N_], pL[N_];  
vector<int> E[N_], L[N_], Ch[N_]; // Adjacency list and Child pointers
int Right[N_], Left[N_];  
long long D[N_];  
map<int, int> Map[N_];  

// Step 1: DFS to build the tree structure from undirected edges
void DFS(int a, int pp) { 
    for (int i = 0; i < E[a].size(); i++) { 
        int x = E[a][i]; 
        if (x == pp) continue; 
        pL[x] = L[a][i]; 
        Ch[a].push_back(x); 
        DFS(x, a); 
    } 
} 

// Step 2: Update Function to manage state and costs at each node
void UDT(int a) {  
    int d = X[a] - Y[a];  
    map<int, int> T; 
    int c = pL[a]; 
    Right[a] += d, Left[a] += d; 
    
    for (auto &t : Map[a]) { 
        int x = t.first + d; 
        int f = t.second; 
        if (x >= 0) T[x] = f + c;  
        else T[x] = f - c; 
    } 
    
    if (Left[a] > 0) { 
        for (int i = 0; i < Left[a]; i++) { 
            T[i] = c; 
        } 
        Left[a] = 0; 
    } 
    
    if (Left[a] < 0) { 
        long long z = D[a] - 1ll * Left[a] * c; 
        while (!T.empty()) {  
            auto it = T.begin(); 
            if (it->second > 0) break; 
            z += it->second; 
            Left[a]++; 
            T.erase(it); 
        } 
        D[a] = z; 
    } 
    Map[a] = T; 
} 

// Step 3: Main processing function to traverse and merge child states
void Do(int a) { 
    if (Ch[a].empty()) { 
        Right[a] = Left[a] = 0; 
        D[a] = 0; 
        return; 
    } 
    for (auto &x : Ch[a]) { 
        Do(x); 
    } 
    vector<int> Z; 
    int ls = 0, rs = 0; 
    D[a] = 0; 
    for (auto &x : Ch[a]) { 
        UDT(x); 
        ls += Left[x]; 
        rs += Right[x]; 
        D[a] += D[x]; 
        for (auto &t : Map[x]) { 
            Z.push_back(t.second); 
        } 
    } 
    sort(Z.begin(), Z.end());  
    for (int i = 0; i < rs - ls; i++) { 
        Map[a][ls + i] = Z[i]; 
    } 
    Left[a] = ls, Right[a] = rs; 
} 

int main() { 
    // Input Handling
    if (scanf("%d", &n) == EOF) return 0; 
    for (int i = 1; i < n; i++) { 
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); 
        E[a].push_back(b); 
        E[b].push_back(a); 
        L[a].push_back(c); 
        L[b].push_back(c); 
    } 
    for (int i = 1; i <= n; i++) 
        scanf("%d %d", &X[i], &Y[i]); 
   
    // Processing
    DFS(1, 0); 
    Do(1); 
    UDT(1); 
    
    // Result Calculation
    long long final_result = D[1]; 
    for (int i = Left[1]; i < 0; i++) 
        final_result += Map[1][i]; 
    
    printf("%lld\n", final_result); 
    return 0; 
}
