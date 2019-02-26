#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

ifstream fin_test("../dataset/meta/test.txt"); // Test Set
ifstream fin_train("../dataset/meta/train.txt"); // Training Set

string str;

int main() {
    while (!fin_test.eof()) {
        fin_test >> str;
        string before = "../dataset/images/" + str + ".jpg";
        string after = "../DATA/test/" + str + ".jpg";
        char old_name[before.length() + 1];
        char new_name[after.length() + 1];
        int i = 0;
        for (; i < before.length(); i++) {
            old_name[i] = before[i];
        }
        old_name[i] = '\0';
        for (i = 0; i < after.length(); i++) {
            new_name[i] = after[i];
        }
        new_name[i] = '\0';
        rename(old_name, new_name);
    }
    fin_test.close();
    while (!fin_train.eof()) {
        fin_train >> str;
        string before = "../dataset/images/" + str + ".jpg";
        string after = "../DATA/train/" + str + ".jpg";
        char old_name[before.length() + 1];
        char new_name[after.length() + 1];
        int i = 0;
        for (; i < before.length(); i++) {
            old_name[i] = before[i];
        }
        old_name[i] = '\0';
        for (i = 0; i < after.length(); i++) {
            new_name[i] = after[i];
        }
        new_name[i] = '\0';
        rename(old_name, new_name);
    }
    fin_train.close();
    return 0;
}
