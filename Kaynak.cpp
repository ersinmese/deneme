#include<iostream>
#include<ctime>
using namespace std;
const int rows = 10;
const int colomns = 10;
int matris[rows][colomns];
int maxships = 20;

void clear() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colomns; j++) {
			matris[i][j] = 0;
		}
	}
}

void draw() {
	int s = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colomns; j++) {

				cout << matris[i][j] << " ";

			}

			cout << endl;
		}
	}

	void spawn() {
		int	s = 0;
		while (s < maxships) {

				srand(time(NULL));
				int x = rand() % rows;
				int y = rand() % colomns;
				if (matris[x][y] != 1) {
					s++;
					matris[x][y] = 1;
				}

				
			

		}
	}

	bool attack(int x,int y) {

		if (matris[x][y] == 1) {
			matris[x][y] = 2;
			return true;
		}
		return false;
	}
	int numberofships() {
		int c = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colomns; j++) {
				if (matris[i][j] == 1) {
					c++;

				}
			}
		}
		return c;
	}


int main() {
	int pos1;
	int pos2;
	clear();
	spawn();
	draw();
	
	
	while (1) {
		cout << endl;
		cout << "saldirilacak kordinatlarý giriniz (x,y)=" << endl;
		cout << "x="; cin >> pos2;
		cout << "y="; cin >> pos1;
		
		if (attack(pos1, pos2)) {
			cout << "dogru tahmin" << endl;
		}
		else {
			cout << "iskaladin" << endl;
		}
		draw();
		cout << endl;
		cout << "kalan gemi sayisi=";  cout << numberofships();
	}
	system("pause");
	return 0;
}