#ifndef DLS_H_INCLUDED
#define DLS_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class DepthLimitedSearch : public SearchingAlgorithm {
    private:
        int d; // depth limited
        stack<vvt> open;
        map<vvt, int> depth;

        void checkChild(int, int, int, int);        

    public:
        DepthLimitedSearch(vvt, int);
        bool execute();
};

DepthLimitedSearch::DepthLimitedSearch(vvt current_state, int d) {
    this->current_state = current_state;
    this->d = d;
    n = current_state.size();
}

void DepthLimitedSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state) || (appear.count(current_state) && depth[current_state] > depth[dad] + 1)) {
        open.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
        depth[current_state] = depth[dad] + 1;
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool DepthLimitedSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;
    depth[current_state] = 0;    

    bool found = true;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }

        current_state = open.top();
        open.pop();
        if(checkCurrentState()) break;
        if(!checkCurrentState() && depth[current_state] <= d)
            generateChild();
        
    }
    return found;
}

#endif