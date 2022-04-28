#include "Header.h"
#include <chrono>
using namespace std::chrono;

// Khởi tạo ngẫu nhiên bảng Ta Canh
void generate_table(vvt &table, int n) {
    srand(time(0));
    map<int, int> map;
    for(int i = 0; i < n * n; i++) {
        int pos;
        do {
            pos = rand() % (n * n);
        }
        while(map.count(pos));
        map[pos] = i;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            table[i][j] = map[i * n + j];
        }
    }
}

void print(vvt table) {
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

void menu() {
    cout << "       ..Ta canh..\n";
    cout << "Nhập kích thước bảng chơi: ";
    int n;
    cin >> n;
    vvt table(n, vt(n));
    generate_table(table, n);

    while(true) {
        system("cls");
        cout << "--------------------" << endl;
        cout << "Bảng chơi hiện tại: " << endl;
        print(table);
        cout << "--------------------" << endl;
        
        cout << "Nhập lựa chọn: \n";
        cout << "1. Reset bảng hiện tại\n";
        cout << "2. Chơi bằng tay\n";
        cout << "3. Cheatcode = Depth-First-Search\n";
        cout << "4. Cheatcode = Breadth-First-Search\n";
        cout << "5. Cheatcode = Depth-Limited-Search\n";
        cout << "6. Cheatcode = Depth-Deepening-Search\n";
        cout << "7. Cheatcode = Best-First-Search\n";
        cout << "8. Cheatcode = Hill-Climbing-Search\n";
        cout << "9. Cheatcode = Beam-Search\n";
        cout << "10. Thoát\n"; 

        int choice;
        cin >> choice;
        system("cls");
        auto start = high_resolution_clock::now();
        switch(choice) {
            case 1: {
                generate_table(table, n);
                cout << "Đã reset bảng chơi!" << endl;
                break;
            }
            case 2: {
                Play play(table);
                play.print();
                play.execute();
                break;
            }
            case 3: {
                DepthFirstSearch dfs(table);
                dfs.print(table);
                cout << "OK đợi tẹo..." << endl;
                dfs.answer();
                break;
            }
            case 4: {
                BreadthFirstSearch bfs(table);
                bfs.print(table);
                cout << "OK đợi tẹo..." << endl;
                bfs.answer();
                break;
            }
            case 5: {
                int d;
                cout << "Nhập số bước tối đa cần giải xong: ";
                cin >> d;
                DepthLimitedSearch dls(table, d);
                dls.print(table);
                cout << "OK đợi tẹo..." << endl;
                dls.answer();
                break;
            }
            case 6: {
                cout << "OK đợi tẹo..." << endl;
                DepthDeepeningSearch dds(table);
                dds.execute();
                break;
            }
            case 7: {
                GreedyBestFirstSearch bfs(table);
                bfs.print(table);
                cout << "Ok đợi tẹo..." << endl;
                bfs.answer();
                break;
            }
            case 8: {
                HillClimbingSearch hcs(table);
                hcs.print(table);
                cout << "Ok đợi tẹo..." << endl;
                hcs.answer();
                break;
            }
            case 9: {
                int k = 2;
                BeamSearch bs(table, k);
                bs.print(table);
                cout << "Ok đợi tẹo..." << endl;
                bs.answer();
                break;
            }
            case 10:
                system("cls");
                cout << "Bye." << endl;
                return;
            default: {
                system("cls");
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Thời gian chạy: " << duration.count() << " microseconds" << endl;
        system("pause");
    }
    
}

int main() {
    
    menu();

    return 0;
}