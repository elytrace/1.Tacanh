#ifndef DEPTHDEEPENINGSEARCH_H_INCLUDED
#define DEPTHDEEPENINGSEARCH_H_INCLUDED

#include "DepthLimitedSearch.h"
#define ll long long

class DepthDeepeningSearch {
    private:
        ll current_depth;
        ll max_depth;
        vvt current_state;
    public:
        DepthDeepeningSearch(vvt);
        void execute();
};

ll factorial(int n) {
    if(n == 0) return 1;
    return factorial(n-1) * n;
}

DepthDeepeningSearch::DepthDeepeningSearch(vvt table) {
    current_state = table;
    current_depth = 0;
    max_depth = factorial(table.size() * table.size());
}

void DepthDeepeningSearch::execute() {
    bool found = false;
    for(ll i = 0; i <= max_depth && !found; i++) {
        cout << "Đang duyệt tầng " << setw(2) << setfill(' ') << i << "...";
        DepthLimitedSearch dls(current_state, i);
        current_depth = i;
        found = dls.execute();
        if(found) {
            cout << " Đã tìm thấy cách giải!" << endl;
            system("pause");
            system("cls");
            cout << "Chi tiết từng bước: " << endl;
            dls.print(current_state);
            dls.answer();
            cout << endl;
            return;
        }
        else {
            cout << " Không có kết quả!" << endl;
        }
    }
    cout << "Không có cách giải!" << endl;
}

#endif