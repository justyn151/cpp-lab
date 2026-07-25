#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<string, vector<int>> series; 
    map<string, size_t> s_idx;
    string cmd;

    // a, train name
    // x, a capacity
    // y, for sambung, y as for capacity
    // dir, left or right
    string a; int x; int y; string dir; 
    int n; cin >> n;

    while (n > 0) {
        cin >> cmd;
        if (cmd == "MASUK") {
            cin >> a >> x;
            series[a] = vector<int>{x};
            s_idx[a] = 0;
        }
        if (cmd == "SAMBUNG") {
            cin >> a >> y;
            series[a].push_back(y);
            s_idx[a] = series[a].size()-1;
        }
        if (cmd == "PINDAH") {
            cin >> a >> dir;
            if (dir == "L") {
                if (s_idx[a] == 0) { cout << "TIDAK PINDAH\n"; continue; }
                s_idx[a]--;
                if (s_idx[a] == 0) { cout << "LOKOMOTIF\n"; continue; }
                cout << series[a][s_idx[a]] << '\n';
            } 
            if (dir == "R") {
                if (s_idx[a] == series[a].size()-1){cout << "TIDAK PINDAH\n"; continue;}
                s_idx[a]++;
                cout << series[a].at(s_idx[a]) << '\n';
            }
        }
        if (cmd == "LEPAS") {
            cin >> a;
            if (s_idx[a] == 0) {cout << "GAGAL LEPAS\n"; continue;}  
            int sum = 0;
            int sum2 = 0;
            for (int i = 0; i < series[a].size(); i++) {
                // cout << "i = " << i << endl;
                if (i == 0) {continue;}
                if (i >= s_idx[a]) {sum2 += series[a].at(i);} // cout << "idx(i>):" << s_idx[a] << " sum (i>): " << sum2 << endl;}
                else {sum += series[a].at(i);} // cout << "idx(else): " << s_idx[a] << " sum(else): "  << sum << endl;}
            }
            series[a].erase(series[a].begin() + s_idx[a], series[a].end());
            s_idx[a] = series[a].size() - 1;
            cout << sum << " " << sum2 << '\n';
        }
        if (cmd == "JALAN") {
            cin >> a;
            int sum = 0;
            int sum2 = 0;
            for (int i = 0; i < series[a].size(); i++) {
                if (i == 0) {continue;}
                if (sum+series[a].at(i) < series[a].at(0)) sum += series[a].at(i);
                else sum2 += series[a].at(i);
            }
            cout << a << " " << sum << " " << sum2 << '\n';
            break;
        }
        n--;
    }
    return 0;
}