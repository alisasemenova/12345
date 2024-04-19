#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
/**
 * @brief функция выполняет сравнение символов в строке s с первыми символами строк в векторе words
 * 
 * @param s строка c аббревитурой
 * @param words вектор из строк
 * @return результат проверки (0 - false, 1 - true)
*/
bool acronym(const std::string &s, const std::vector<std::string> &words){ 
    int size1 = s.length(); //длина аббревиатуры
    int size2 = words.size(); //количество слов 
    if (size1 != size2) 
    {
        return false;
    }

    for (int i = 0; i < size1; i++)
    { 
        if (words[i][0] != s[i]) //берём символ с 0 индексом каждой строки вектора
        {
             return false;
        }
    }

    return true;
} 

/**
 * @brief функция проверяет является ли строка палиндромом
 * @param s2 - исходная строка
 * @return результат проверки (0 - false, 1 - true)
 */
bool palindrome(std::string s2)
{
    for (int i = 0; i < s2.size(); i++) // удаление пробелов
    {
        if(s2[i] == ' ')
        {
            s2.erase(i, 1);
        }
    }

    for (int i = 0; i < s2.length(); i++) //проверка на палиндром
    {
        if (s2[i] != s2[s2.size() - 1 - i]) 
        {
            return false;
        }
    }
    return true;
}

/** 
* @brief Функция, возвращающая максимальный счёт int1 среди множества слов str1, сформированных из вектора char1
* создаём пустой вектор букв char2, добавляем в место букв их количество. Таким же образом создаем вектор str2.
* сравниваем char2 и str2, и если char2 меньше чем str2, то тогда не хватает букв для составления слов, или их вообще нет.
* прекращаем работу.
* @param str1 Вектор строк, определяющий множество строк
* @param char1 Вектор символов, определяющий множество символов
* @param int1 Вектор подсчёта с целочисленными значениями, определяющий счёт за каждый символ в слове
* 
* @return Возвращает максимальный счёт среди множества слов
*/

int countscore(std::vector<std::string> words, std::vector <char> letters, std::vector<int> score){
    int char2[26] = {0};
    int maxi = 0;

    for (int i = 0; i < (int)letters.size(); i++) //проходимся по массивы букв 
    {
        char2[letters[i] - 'a']++; //считаем количество букв (с помощью UNIT code определяем их индекс-место)
    }

    for (size_t i = 0; i < words.size(); i++)
    {
        bool flag = true;
        std::string word = words[i]; //берем слово стоящее на i-том месте в векторе слов
        int str2[26] = {0};

        for (int j = 0; j < (int)word.size(); j++)
        {
            str2[word[j] - 'a']++;
        }

        for (int k = 0; k < 26; k++) //проверка на возможность составить слова (есть ли нужные буквы)
        {
            if (char2[k] < str2[k])
            {
                flag = false;
                break;
            }
        }

        if (!flag) //если flag=0, то переходим на следующий i-ый + 1 шаг
        {
            continue;
        }

        int a = 0;

        for (int j = 0; j < (int)word.size(); j++) //считаем score слова
        {
            a += score[word[j] - 'a'];
        }
        if (maxi < a) 
        maxi = a;
    }
    return maxi;
}


int main()
{   //1 блок 1 задача
    setlocale(LC_ALL, "RUS");
    std::string s  = "tpu";
    std::vector<std::string> words = {"tomsk", "polytechnic", "university"};
    std::cout << "Результат первой программы: " << std::endl;
    std::cout << acronym(s, words) << std::endl;

    //2 блок 1 задача

    std::string s2;
    std::cout << "Введите строку: ";
    getline(std::cin, s2);
    std::cout << palindrome(s2) << std::endl;;

    //3 блок 1 задача

    std::vector<std::string> words3 = {"cat", "pig", "app", "bed"};
    std::vector<char> letters = {'a', 'c', 't', 'i', 'p', 'g', 'o', 'r', 's', 'd', 'e', 'b'};
    std::vector<int> score = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    std::cout << "Самое большое количество очков: " << countscore(words3, letters, score);

    return 0;
}