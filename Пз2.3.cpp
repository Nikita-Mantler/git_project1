#include <iostream>
#include <string>

using namespace std;

/// Строка с рандом значениями
/// длина строчк
// ретëрн строка
string generateRandomString(int length)
{
    string result = "";
    // цикл для каждого символа, который хотим вставить
    for (int i = 0; i < length; i++)
    {
        int random = rand() % 36;
        if (random < 10)
            result += (char)(random + 48);
        else
            result += (char)(random + 87);
    }
    return result;
}

/// возвращаем Хэш методом Горнера
int getHashCodeHorner(string str)
{
    int hashCode = 0;                     
    for (int i = 0; i < str.length(); i++)
    {
        hashCode = hashCode * 37 + (int)str[i]; // Умножить результат на 37 и добавить аски значение текущей буквы
    }
    return hashCode;
}

int main()
{
    srand(time(NULL));

    for (int length = 3; length <= 6; length++)
    {
        int collisionsByHash = 0;   // храним значение коллизии
        int collisionsByString = 0;
        int hashCodes[2000];        // int array to store the hashCodes of the 2000 random strings
        string strings[2000];       // string array to store the 2000 random strings

        // generate 2000 random strings
        for (int i = 0; i < 2000; i++)
        {
            string str = generateRandomString(length);
            hashCodes[i] = getHashCodeHorner(str);     // получаем хэш случ строчк
            strings[i] = str;                          // сохранить случ строчк в список
        }

        clock_t start = clock(); // времечко

        for (int i = 0; i < 2000; i++) // проходим по первым 2000 строчек
        {
            for (int j = i + 1; j < 2000; j++) // проходим по остальным
            {
                if (strings[i] == strings[j]) // сравниваем
                    collisionsByString++;     // +1 счётчику коллизии
            }
        }
        clock_t end = clock();                                        // стоп времечк
        double timeByString = (double)(end - start) / CLOCKS_PER_SEC;

        // count collisions by hash
        start = clock();
        for (int i = 0; i < 2000; i++)
        {
            for (int j = i + 1; j < 2000; j++)
            {
                if (hashCodes[i] == hashCodes[j])
                    collisionsByHash++;
            }
        }
        end = clock();
        double timeByHash = (double)(end - start) / CLOCKS_PER_SEC;

        // print results
        cout << "Length: " << length << endl;
        cout << "Collisions by hash: " << collisionsByHash << " ";
        cout << "Collisions by string: " << collisionsByString << endl;
        cout << "Time by hash: " << timeByHash << " ";
        cout << "Time by string: " << timeByString << endl;
        cout << "Time by hash is " << timeByString / timeByHash << " times faster" << endl;
        cout << endl;
    }

    return 0;
}
