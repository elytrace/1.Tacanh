#ifndef SEARCHING_ALGORITHM_H_INCLUDED
#define SEARCHING_ALGORITHM_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

#define vt vector<int>
#define vvt vector<vt>

map<vvt, int> value1;
map<vvt, int> value2;

struct cmp {
    bool operator()(vvt const& state1, vvt const& state2) {
        return value1[state1] > value1[state2];
        // return value2[state1] < value2[state2];
    }
};

class SearchingAlgorithm {
    protected:
        vvt current_state;
        int n;
        map<vvt, vvt> father;
        map<vvt, bool> appear;

        bool checkCurrentState();         
        void generateChild();
        virtual void checkChild(int, int, int, int) = 0;
        void evaluate(vvt);

    public:
        void print(vvt); 
        virtual bool execute() = 0;
        void answer();
};

bool SearchingAlgorithm::checkCurrentState() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(current_state[i][j] != n * i + j) return false;
        }
    }
    return true;
}

void SearchingAlgorithm::generateChild() {
    bool found = false;
    for(int i = 0; i < n && !found; i++) {
        for(int j = 0; j < n && !found; j++) {  
            if(current_state[i][j] == 0) {
                if(i > 0)
                    checkChild(i, j, -1, 0);
                if(i < n-1)
                    checkChild(i, j, 1, 0);
                if(j > 0)
                    checkChild(i, j, 0, -1);
                if(j < n-1)
                    checkChild(i, j, 0, 1);
                found = true;
            }
        }
        if(found) break;
    }
}

void SearchingAlgorithm::evaluate(vvt current_state) {
    int value = 0, n = current_state.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(current_state[i][j] != n * i + j) value++;
        }
    }
    value1[current_state] = value;

    value = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            value += abs(i + j - n * i - j);
        }
    }
    value2[current_state] = value;
}

void SearchingAlgorithm::print(vvt current_state) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(current_state[i][j])
                cout << setw(2) << setfill(' ') << current_state[i][j] << " ";
            else cout << "   ";
        }
        cout << endl;
    }
}

void SearchingAlgorithm::answer() {
    if(execute()) {
        stack<vvt> ans;
        ans.push(current_state);
        while(father.count(current_state)) {
            ans.push(father[current_state]);
            current_state = father[current_state];
        }
        ans.pop();
        int step = ans.size();
        while(!ans.empty()) {
            for(int i = 0; i < n; i++) cout << "---"; cout << endl;
            print(ans.top());
            ans.pop();
        }
        cout << "Tìm được trạng thái cuối cùng sau " << step - 1 << " bước" << endl;
    }
    else cout << "Không tìm thấy kết quả!" << endl;
}

#endif