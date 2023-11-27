#include "GameManager.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");

    GameManager race;
    race.begin();

    return 0;
}