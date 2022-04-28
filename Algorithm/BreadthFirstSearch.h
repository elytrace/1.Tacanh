#ifndef BREADTHFIRSTSEARCH_H_INCLUDED
#define BREADTHFIRSTSEARCH_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class BreadthFirstSearch : public SearchingAlgorithm {
    private:
        queue<vvt> open;
       
        void checkChild(int, int, int, int);

    public:
        BreadthFirstSearch(vvt);
        bool execute();
};

BreadthFirstSearch::BreadthFirstSearch(vvt current_state) {
    this->current_state = current_state;
    n = current_state.size();
}

void BreadthFirstSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state)) {
        open.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool BreadthFirstSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;

    bool found = true;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }
        current_state = open.front();
        open.pop();

        if(checkCurrentState()) break;
        
        else generateChild();
        
    }
    return found;
}

#endif