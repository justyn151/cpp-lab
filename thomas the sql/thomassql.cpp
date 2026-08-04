#include "./linkedlist.cpp"
#include <vector>

#define Node(x) Node<x, string>
#define pb(x) push_back(x)

// this piece of code is really vital to the operation
// of this program. At this point of writing only God and we know 
// how it works. Now, only God knows how this thing works.
// Good luck to future developer!!
template <typename T, typename N>
int loc_length(Node<T, N>* locomotiff) {
    int count{};
    do {
        count += locomotiff->value.size();
        locomotiff = locomotiff->next;
    } while (locomotiff!= nullptr);
    return count;
}

template <typename T, typename N>
Node<T, N>* search_loc(Node<T, N>* head, string s) {
    Node<T, N>* current_node = head;
    do {
        if (current_node->name == s) return current_node;
        current_node = current_node->next;
    } while (current_node != nullptr);
    return nullptr;
}

int main()
{
    // k, binary tree
    // n, lokomotif
    // q, query commands
    // idx_loc & idx_j, for tracking condector position
    int k, n, q;
    string idx_loc; int idx_j; Node(vector<int>)* node_loc = new Node(vector<int>);

    // this little piece of shit likes to overcomplicate stuff
    // FUCK -@greezed
    // rofl -@laffeyyfrederica
    // vector of KERETA-KERETA yang isinya node of LOKOMOTIF which contains vector of GERBONG

    /* if anybody forget how trains works, look at this:
    * vector<Node<..>> | Node<vector<int>>
    * k1, k2, k3       | k1 {10, 20, 30}, k2 ...
    * k1.next = k2
    * 
    * 
    * 
    */

    vector<Node(vector<int>)*> trains{};

    cin >> n;
    for (int i = 0; i < n; i++) {
        Node(vector<int>)* new_node = new Node(vector<int>);
        string x; int g; vector<int> p;
        
        cin >> x;
        
        cin >> g;
        for (int j = 0; j < g; j++) {
            int k; cin >> k;
            p.pb(k);
        }

        new_node->value = p; new_node->name = x; 
        trains.pb(new_node); // pb itu push_back ygy
    }

    cin >> idx_loc >> idx_j;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string cmd; cin >> cmd;
        if (cmd == "GABUNG") {
            string x, y; cin >> x >> y;
            int idx_x, idx_y, count{};
            for (int j = 0; j < trains.size(); j++) {
                if (trains.at(j)->name == x) { idx_x = j; }// count += trains.at(j)->value.size(); }
                if (trains.at(j)->name == y) { idx_y = j; }// count += trains.at(j)->value.size(); } 
            }
            
            mergeNode(trains.at(idx_y), trains.at(idx_x), true);
            trains.erase(trains.begin() + idx_y);

            Node(vector<int>)* new_loc = trains.at(idx_x);
            
            cout << loc_length(new_loc) << endl;
        }
        if (cmd == "PISAH") {
            string x; cin >> x;
            bool exit = false;
            for (int j = 0; j < trains.size(); j++) {
                Node(vector<int>)* current_node = trains.at(j);
                Node(vector<int>)* head = current_node;
                do {
                    if (current_node->name == x) {
                        /* welcome to the territory of segfaults !!!*/
                        //cout << 1 << endl;
                        current_node->prev->next = nullptr;
                        //cout << 2 << endl;
                        current_node->prev = nullptr;
                        //cout << 3 << endl;

                        //cout << "fuck off!!" << endl;
                        trains.push_back(current_node);
                        //cout << "fuck off!!2" << endl;
                        
                        int length_sep_front = loc_length(head);
                        int length_sep_back = loc_length(current_node);

                        cout << length_sep_front << " " << length_sep_back << endl;
                        exit = true;
                        break;
                    }
                    current_node = current_node->next;
                } while (current_node != nullptr);
                if (exit) break;
            }
        }
        if (cmd == "TELEPORT") {
            cin >> idx_loc;
            idx_j = 0;

            for (auto train : trains) {
                auto r = search_loc(train, std::string(idx_loc));
                if (r != nullptr) cout << r->value[idx_j] << '\n'; node_loc = r;
            }
        }
        if (cmd == "MOVE") {
            string direction; int j; 
            cin >> direction >> j;
            
            if (direction == "RIGHT") {
                idx_j += j;
                while (true) {
                    if (idx_j >= node_loc->value.size()-1 && node_loc->next == nullptr) { 
                        cout << node_loc->value[node_loc->value.size() - 1] << endl; break;
                    }
                    else if (idx_j < node_loc->value.size()-1) { 
                        cout << node_loc->value[idx_j] << endl; break;
                    }
                    else {
                        node_loc = node_loc->next;
                        idx_loc = node_loc->name;  
                        idx_j = node_loc->value.size() - 1 - idx_j; 
                    }
                }
            } else if (direction == "LEFT") {
                // [1, 2, 3] [1, 2, 3, 4]
                idx_j -= j;
                while (true) {
                    if (idx_j <= 0 && node_loc->prev == nullptr) { 
                        cout << node_loc->value[0] << endl; break;
                    }
                    else if (idx_j > 0) { 
                        cout << node_loc->value[idx_j] << endl; break;
                    }
                    else {
                        node_loc = node_loc->prev;
                        idx_loc = node_loc->name;
                        idx_j = node_loc->value.size() - 1 + idx_j; 
                    }
                }
            }

        }
    }

    // vector<int> dummy {1, 2, 3};
    // Node<vector<int>, string>* new_Node = new Node(vector<int>);
    // new_Node->value = dummy;
    // new_Node->name = "a";

    // addNode(dummy, new_Node, std::string("b"));

    // displayIterator(new_Node);

    // displayIterator(trains.at(0));
    // displayIterator(trains.at(1));
    // displayIterator(trains.at(2));
    // displayIterator(trains.at(3));
}