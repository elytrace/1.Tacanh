#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class DepthFirstSearch : public SearchingAlgorithm {
    private:
        stack<vvt> open;
       
        void checkChild(int, int, int, int);

    public:
        DepthFirstSearch(vvt);
        bool execute();
};

DepthFirstSearch::DepthFirstSearch(vvt current_state) {
    this->current_state = current_state;
    n = current_state.size();
}

void DepthFirstSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state)) {
        open.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool DepthFirstSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;

    bool found = true;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }
        current_state = open.top();
        open.pop();

        if(checkCurrentState()) break;
        
        else generateChild();
        
    }
    return found;
}

#endif