#include <iostream>
#include <ctime>
using namespace std;
void init(int ran[]) {
	for (int i = 0; i < 4; i++) {


		ran[i] = rand() % 10;
		cout << ran[i] << " ";

	}
}
void art() {
	cout << endl;
	cout << R"(   /                       \                                )" << endl;
	cout << R"( /X/                       \X\                              )" << endl;
	cout << R"(|XX\         _____         /XX|                             )" << endl;
	cout << R"(|XXX\     _/       \_     /XXX|___________                  )" << endl;
	cout << R"( \XXXXXXX             XXXXXXX/            \\\               )" << endl;
	cout << R"(   \XXXX    /     \    XXXXX/                \\\            )" << endl;
	cout << R"(        |   0     0   |                         \           )" << endl;
	cout << R"(         |           |                           \          )" << endl;
	cout << R"(          \         /                            |______//  )" << endl;
	cout << R"(           \       /                             |          )" << endl;
	cout << R"(            | O_O | \                            |          )" << endl;
	cout << R"(             \ _ /   \________________           |          )" << endl;
	cout << R"(                        | |  | |      \         /           )" << endl;
	cout << R"(                        / |  / |       \______/             )" << endl;
	cout << R"(     Else?              \ |  \ |        \ |  \ |            )" << endl;
	cout << R"(     1-yes 0 - no     __| |__| |      __| |__| |            )" << endl;
	cout << R"(                      |___||___|      |___||___|            )" << endl;

}
int game(int ran[]) {
	int num_user, b, num[4], bull, cow; // num_user - число вводим, b - цифра числа user, num - число, bull - кол-во быков, cow - кол-во коров
	bool flag = 0;

	while (true) {
		init(ran);
		int counter = 0; // кол-во ходов
		while (true) {
			bull = 0;
			cow = 0;
			cout << endl;//отступ от загаданного числа
			cout << counter + 1 << " - ";
			counter++;
			cin >> num_user;
			if (num_user == 0)
				break;
			for (int i = 3; i >= 0; i--) {
				b = num_user % 10;
				num[i] = b;
				num_user = (num_user - b) / 10;
			}
			for (int i = 0; i < 4; i++) {//быки
				if (num[i] == ran[i]) {
					bull++;
				}
			}
			for (int i = 0; i < 4; i++) {//коровы
				for (int j = 0; j < 4; j++) {
					if (num[i] == ran[j]) {
						cow++;
					}
				}
			}
			cout << bull << "b " << cow - bull << "c" << endl << "-------------------------" << endl;
			if (bull == 4) {
				cout << "You win ";
				break;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << ran[i];
		}

		art();
		cin >> flag;
		if (flag == 0) {
			return 0;
		}
		flag = 0;
	}
}

int main() {
	srand(time(NULL));
	cout << "Hello, 0 - exit" << endl << endl;
	int ran[4];

	game(ran);

}