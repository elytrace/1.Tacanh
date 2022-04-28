#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

#define vt vector<int>
#define vvt vector<vt>

class Play {
    private:
        vvt table;
        bool checkCurrentState();
    public:
        Play(vvt);
        void print(); 
        void execute();
};

Play::Play(vvt table) {
    this->table = table;
}

bool Play::checkCurrentState() {
    for(int i = 0; i < table.size(); i++) {
        for(int j = 0; j < table.size(); j++) {
            if(table[i][j] != table.size() * i + j) return false;
        }
    }
    return true;
}

void Play::print() {
    int n = table.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(table[i][j])
                cout << setw(2) << setfill(' ') << table[i][j] << " ";
            else cout << "   ";
        }
        cout << endl;
    }
}

void Play::execute() {
    cout << "Nhập w, a, s, d để di chuyển ô trống, q để thoát: " << endl;
    int n = table.size();
    char choice;
    while(!checkCurrentState()) {
        cin >> choice;
        bool found = false;
        if(choice == 'q') return;
        for(int i = 0; i < n  && !found; i++) {
            for(int j = 0; j < n && !found; j++) {
                if(table[i][j] == 0) {
                    if(choice == 'a' && j < n-1)
                        swap(table[i][j], table[i][j+1]);
                    if(choice == 'w' && i < n-1) 
                        swap(table[i][j], table[i+1][j]);
                    if(choice == 'd' && j > 0)
                        swap(table[i][j], table[i][j-1]);
                    if(choice == 's' && i > 0)
                        swap(table[i][j], table[i-1][j]);
                    found = true;
                    print();
                }
            }
        }
    }

}

#endif