#include<bits/stdc++.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector < pair < pair < int, int >, vector < double > > > info_age = {
        {{0, 1}, {0.2, 1.0, 0.0, 0.4, 0.1}},
        {{1, 3}, {1.0, 1.0, 0.0, 0.2, 0.26}},
        {{3, 14}, {0.2, 1.0, 0.0, 0.2, 0.68}},
        {{14, 25}, {0.2, 0.11, 0.0, 1.0, 0.81}},
        {{25, 40}, {0.2, 0.11, 0.0, 1.0, 0.84}},
        {{40, 60}, {0.2, 0.01, 0.0, 1.0, 0.9}},
        {{60, 200}, {0.3, 0.0, 1.0, 1.0, 1.0}}
    };

    vector < vector < double > > info_symptoms = {
        {0.0, 0.96, 0.0, 0.0, 0.0},
        {1.0, 1.0, 0.0, 0.2, 0.67},
        {0.0, 0.0, 0.93, 0.2, 0.33},
        {0.35, 1.0, 0.89, 1.0, 0.0},
        {0.0, 0.68, 0.39, 0.2, 0.0},
        {0.53, 0.71, 1.0, 1.0, 1.0}
    };

    vector < vector < double > > info_cause = {
        {1.0, 1.0, 1.0, 1.0, 0.34},
        {0.0, 0.0, 0.71, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.35},
        {0.0, 0.35, 0.0, 0.5, 1.0},
    };

    vector < string > diagnosis = {"Гордеолум и халазион", "Воспаление век", "Болезни век", "Болезни слезного аппарата", "Болезни глазницы"};

    vector < double > uT(diagnosis.size(), 0.0);
    vector < double > uS(diagnosis.size(), 0.0);
    vector < double > uP(diagnosis.size(), 0.0);


    cout << "Введите Ваш возраст:" << endl;
    int age;
    cin >> age;
    int age_c = 0;
    for (int i = 0; i < info_age.size(); i++) {
        if (info_age[i].first.first <= age && age < info_age[i].first.second) {
            age_c = i;
        }
    }
    uT = info_age[age_c].second;

    vector < string > symptoms = {"Температура", "Отек в области глаз", "Снижение остроты зрения", "Слезотечение", "Сухость в глазу", "Косметический дефект"};
    cout << "Давайте узнаем, какие у вас есть симптомы:" << endl;
    for (int i = 0; i < symptoms.size(); i++) {
        cout << "Есть ли у вас " << symptoms[i] << "? Введите Y, если да, и N иначе." << endl;
        string res;
        cin >> res;
        if (res == "Y") {
            for (int j = 0; j < diagnosis.size(); j++) {
                if (info_symptoms[i][j] > 0.0) {
                    if (uS[j] == 0 || info_symptoms[i][j] < uS[j]) uS[j] = info_symptoms[i][j];
                }
            }
        }
    }

    vector < string > cause = {"Инфекционное заболевание", "Травма глаза", "Врожденное заболевание", "Заболевания других органов"};
    cout << "Давайте узнаем возможные причины возникновения:" << endl;
    for (int i = 0; i < cause.size(); i++) {
        cout << "Может быть " << cause[i] << "? Введите Y, если да, и N иначе." << endl;
        string res;
        cin >> res;
        if (res == "Y") {
            for (int j = 0; j < diagnosis.size(); j++) {
                if (info_cause[i][j] > 0.0) {
                    if (uP[j] == 0 || info_cause[i][j] < uP[j]) uP[j] = info_cause[i][j];
                }
            }
        }
    }

    vector < double > umin;

    for (int i = 0; i < uT.size(); i++) {
        double res = 1.0;
        if (uT[i] > 0.0) res = min(res, uT[i]);
        if (uS[i] > 0.0) res = min(res, uS[i]);
        if (uP[i] > 0.0) res = min(res, uP[i]);
        umin.push_back(res);
    }

    double umax = 0;
    for (auto key : umin) umax = max(umax, key);

    for (int i = 0; i < umin.size(); i++) {
        if (umin[i] == umax) {
            cout << "Ваш предполагаемый диагноз: " << diagnosis[i] << endl;
            exit(0);
        }
    }
    return 0;
}
