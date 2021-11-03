#include <iostream>
class Fibbonacci {
private:
	int x, y, z;
public:
	Fibbonacci() { x = 0; y = 1; z = x + y; }
    void generate(int n) {
        x= 0; y = 1;
        std::cout << x << " " << y;
        for (int i = 1; i <= n - 2; i++) {
            z = x + y;
            std::cout << " " << z;
            x= y;
            y = z;
        }
    }
};

int main() {
    std::cout << "Enter number of items you need in the series: ";
    int n;
    std::cin >> n;
    Fibbonacci obj;
  obj.generate(n);
}