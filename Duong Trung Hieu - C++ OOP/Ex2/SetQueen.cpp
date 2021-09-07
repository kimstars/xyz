//Bai toan N con hau
#include <iostream>
#define N 8
using namespace std;


void showResult(int b[][N]) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			cout << b[i][j] << " " ;
		}
		cout << endl;
	}
}

bool isOk(int b[][N], int row, int col) {
	int i,j;
	for (i = 0; i < col; i++) {
		if (b[row][i] == 1) {
			return false;
		}
	}
	
	//cheo trai tren
	i = row; j = col;
	while (i >= 0 && j >= 0) {
		if(b[i][j] == 1) { //khong dat duoc hau
			return false;
		}
		i--;
		j--;
	}
	
	//cheo trai duoi
	i = row; j = col;
	while (i < N && j >= 0) {
		if(b[i][j] == 1) { //khong dat duoc hau
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool setQueen(int b[][N], int col) {
	if (col >= N) {
		return true;
	}
	
	for (size_t i = 0; i < N; i++) {
		if (isOk(b, i, col)) {
			b[i][col] = 1; //dat hau
			if(setQueen(b, col + 1)) {
				return true;
			}
			b[i][col] = 0; //lui lai
		}
	}
	return false;
}

int main() {
    // NQueen backtracking
    int b[N][N];
    
	for (size_t i = 0; i < N; i++) {
    	for (size_t j = 0; j < N; j++) {
    		b[i][j] = 0;
		}
	}
	
	if (setQueen(b, 0)) {
		showResult(b);
	} else {
		cout << "No solution!" << endl;
	}
	return 0;
}
