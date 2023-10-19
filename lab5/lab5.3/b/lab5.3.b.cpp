#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// функция для считывания  языков для одного школьника
set<string> ReadLanguagesForStudent() {
    int k; 
    cin >> k;

    set<string> languages; 

    for (int j = 0; j < k; j++) {
        string language;
        cin >> language;
        languages.insert(language); 
    }

    return languages;
}

// нахождение общих языков
set<string> FindCommonLanguages(const set<string>& languages1, const set<string>& languages2) {
    set<string> intersection;
    set_intersection(languages1.begin(), languages1.end(),
                        languages2.begin(), languages2.end(),
                        inserter(intersection, intersection.begin()));
    return intersection;
}

class Application
{
public:
    void run(){
        int n; // количество школьников
        cin >> n;

        set<string> allLanguages; //  для всех языков
        set<string> commonLanguages; //  для общих языков

        // для каждого школьника
        for (int i = 0; i < n; i++) {
            set<string> languages = ReadLanguagesForStudent();

            if (i == 0) {
                commonLanguages = languages;
            } else {
                commonLanguages = FindCommonLanguages(commonLanguages, languages);
            }

            allLanguages.insert(languages.begin(), languages.end());
        }

        // количество и список общих языков
        cout << commonLanguages.size() << endl;
        for (const string& language : commonLanguages) {
            cout << language << endl;
        }

        //  количество и список всех языков
        cout << allLanguages.size() << endl;
        for (const string& language : allLanguages) {
            cout << language << endl;
        }

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}