#ifndef HILLCLIMBINGSEARCH_H_INCLUDED
#define HILLCLIMBINGSEARCH_H_INCLUDED

#include "Extended/SearchingAlgorithm.h"

class HillClimbingSearch : public SearchingAlgorithm {
    private:
        queue<vvt> open;
        priority_queue<vvt, vector<vvt>, cmp> temp;  

        void checkChild(int, int, int, int);

    public:
        HillClimbingSearch(vvt);
        bool execute();
};

HillClimbingSearch::HillClimbingSearch(vvt current_state) {
    this->current_state = current_state;
    n = current_state.size();
}


void HillClimbingSearch::checkChild(int i, int j, int x, int y) {
    const vvt dad = current_state;
    swap(current_state[i][j], current_state[i+x][j+y]);
    if(!appear.count(current_state)) {
        temp.push(current_state);
        father[current_state] = dad;
        appear[current_state] = 1;
        evaluate(current_state);
    }
    swap(current_state[i][j], current_state[i+x][j+y]);   
}

bool HillClimbingSearch::execute() {
    open.push(current_state);
    appear[current_state] = 1;
    evaluate(current_state);

    bool found = true;
    while(found) {
        if(open.empty()) {
            found = false;
            break;
        }
        current_state = open.front();
        open.pop();

        if(checkCurrentState()) break;
        
        else {
            generateChild();
            while(!temp.empty()) {
                open.push(temp.top());
                temp.pop();
            }
        }
        
    }
    return found;
}

#endif