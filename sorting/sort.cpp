#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int>& arr) {
	for (auto items : arr) cout << items << ", ";
	cout << endl;
}

void bubbleSort(vector<int>& deck) {
	for (int i = 0; i < deck.size(); i++) {
		for (int j = i + 1; j < deck.size(); j++) {
			if (deck[i] > deck[j]) {
				int temp = deck[i];
				deck[i] = deck[j];
				deck[j] = temp;
			}
		}
	}
}

void insertionSort(vector<int>& deck) {
	for (int i = 0; i < deck.size(); i++) {
		if (i == 0) continue;

		display(deck);
	}
}

int main()
{
	vector<int> deck = {5, 7, 1, 9, 2, 8, 12, 11, 4, 3, 10, 6};

	bubbleSort(deck);
	// insertionSort(deck);

	display(deck);
}
