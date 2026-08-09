#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
#include <sstream>

using namespace std;

struct Color {
    int r;
    int g;
    int b;
};

int limitColor(int value) {
    if (value < 0)
        return 0;

    if (value > 255)
        return 255;

    return value;
}

string toHex(const Color& color) {
    stringstream ss;

    ss << "#"
       << uppercase
       << hex
       << setw(2) << setfill('0') << color.r
       << setw(2) << setfill('0') << color.g
       << setw(2) << setfill('0') << color.b;

    return ss.str();
}

Color randomColor(mt19937& generator) {
    uniform_int_distribution<int> distribution(0, 255);

    Color color;

    color.r = distribution(generator);
    color.g = distribution(generator);
    color.b = distribution(generator);

    return color;
}

Color adjustColor(const Color& base, int amount) {
    Color color;

    color.r = limitColor(base.r + amount);
    color.g = limitColor(base.g + amount);
    color.b = limitColor(base.b + amount);

    return color;
}

void generatePalette(const Color& base) {
    cout << "\n========== COLOR PALETTE ==========\n";

    for (int i = -2; i <= 2; i++) {

        Color color =
            adjustColor(base, i * 30);

        cout << "Color "
             << i + 3
             << " : "
             << toHex(color)
             << "  RGB("
             << color.r
             << ", "
             << color.g
             << ", "
             << color.b
             << ")\n";
    }

    cout << "===================================\n";
}

void showColor(const Color& color) {
    cout << "\n========== CURRENT COLOR ==========\n";

    cout << "HEX : "
         << toHex(color)
         << '\n';

    cout << "RGB : "
         << color.r
         << ", "
         << color.g
         << ", "
         << color.b
         << '\n';

    cout << "===================================\n";
}

int main() {

    random_device rd;
    mt19937 generator(rd());

    Color currentColor =
        randomColor(generator);

    int choice;

    while (true) {

        cout << "\n";
        cout << "=================================\n";
        cout << "        COLOR PALETTE LAB\n";
        cout << "=================================\n";
        cout << "1. Generate Random Color\n";
        cout << "2. Generate Palette\n";
        cout << "3. Show Current Color\n";
        cout << "4. Generate New Palette\n";
        cout << "5. Exit\n";
        cout << "=================================\n";

        cout << "Choose: ";

        if (!(cin >> choice)) {

            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid input.\n";

            continue;
        }

        switch (choice) {

            case 1:

                currentColor =
                    randomColor(generator);

                cout << "\nNew color: "
                     << toHex(currentColor)
                     << '\n';

                break;

            case 2:

                generatePalette(currentColor);

                break;

            case 3:

                showColor(currentColor);

                break;

            case 4:

                currentColor =
                    randomColor(generator);

                generatePalette(currentColor);

                break;

            case 5:

                cout << "\nGoodbye!\n";

                return 0;

            default:

                cout << "\nInvalid choice.\n";
        }
    }

    return 0;
}