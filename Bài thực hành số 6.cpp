#include <iostream>
using namespace std;
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Di chuyển từ  " << from << " đến " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Di chuyển đĩa " << n << " từ " << from << " đến " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    cout << "Nhập sl đĩa n: ";
    cin >> n;
    cout << "Các bước di chuyển của " << n << endl;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
