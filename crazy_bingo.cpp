#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>>

using namespace std;

//function to fill array with random numbers
void fill_array(char arr[]){
	srand(time(0));
	int n;
	for(int i = 0; i < 25; i++){
		n = rand() % 10;
		arr[i] = '0' + n;
	}

}

//function to print bingo card with hidden integers
void print_hidden(char arr[]){
	cout << "    B    I    N    G    O\n";
	cout << "--+--------------------------+\n";
	cout << "C | ";
	int i;
	for(i = 0; i < 5; i++){
		if(i % 2 == 0){
			cout << "*    ";
		}else{
			cout << arr[i] << "    ";
		}
	}
	cout << "|\n";
	cout << "R | ";
	for(i = 5; i < 10; i++){
		if(i % 2 == 0){
			cout << "*    ";
		}else{
			cout << arr[i] << "    ";
		}
	}
	cout << "|\n";
	cout << "A | ";
	for(i = 10; i < 15; i++){
		if(i % 2 == 0){
			cout << "*    ";
		}else{
			cout << arr[i] << "    ";
		}
	}
	cout << "|\n";
	cout << "Z | ";
	for(i = 15; i < 20; i++){
		if(i % 2 == 0){
			cout << "*    ";
		}else{
			cout << arr[i] << "    ";
		}
	}
	cout << "|\n";
	cout << "Y | ";
	for(i = 20; i < 25; i++){
		if(i % 2 == 0){
			cout << "*    ";
		}else{
			cout << arr[i] << "    ";
		}
	}
	cout << "|\n";
	cout << "--+--------------------------+\n\n\n";
	
}

//function to print bingo card with no hidden integers
void print_full(char arr[]){
	cout << "    B    I    N    G    O\n";
	cout << "--+--------------------------+\n";
	cout << "C | ";
	int i;
	for(i = 0; i < 5; i++){
		cout << arr[i] << "    ";
	}
	cout << "|\n";
	cout << "R | ";
	for(i = 5; i < 10; i++){
		cout << arr[i] << "    ";
	}
	cout << "|\n";
	cout << "A | ";
	for(i = 10; i < 15; i++){
		cout << arr[i] << "    ";
	}
	cout << "|\n";
	cout << "Z | ";
	for(i = 15; i < 20; i++){
		cout << arr[i] << "    ";
	}
	cout << "|\n";
	cout << "Y | ";
	for(i = 20; i < 25; i++){
		cout << arr[i] << "    ";
	}
	cout << "|\n";
	cout << "--+--------------------------+\n\n\n";
	

}

//function to check if user input matches integers in array
void check(char arr[], char entry[]){
	for(int i = 0; i < 3; i++){
		int j = 0;
		while(j < 3 && entry[j] == arr[i+j]){
			j = j + 1;
		}
		if(j == 3){
			cout << "Entry " << entry[0] << entry[1] << entry[2] << " Found!\nYOU WIN!!\n";
		}
	}
}

int main(){
	
	char answer = 'y';
	char arr[25];
	char first[3];
	char second[3];

	do{
		fill_array(arr);
		print_hidden(arr);
		
		cout << "Enter your first pick: ";
		cin >> first;
		cout << "Enter your second pick: ";
		cin >> second;
		cout << "\n\n";

		print_full(arr);
		
		char temp[5];
		int i = 0;
		while(i < 25){
			for(int j = 0; j < 5; j++){
				temp[j] = arr[i + j];
			}
			i = i + 5;

			check(temp, first);
			check(temp, second);
		}

		int x=0;
		
		while(x < 5){
			int y = 0;
			int count = 0;
			while(y < 21 + x){
				temp[count] = arr[x+y];
				count++;
				y = y + 5;
			}
			x++;
			check(temp, first);
			check(temp, second);	
		}
		


		bool pass = false;
		while(pass == false){
			cout << "Would you like to play again? ";
			cin >> answer;
			if(answer == 'y' || answer == 'n'){
				pass = true;
			}
		}

	}while(answer == 'y');


	return 0;
}
