#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Application
{
public:
    void run(){
        int n;
        cin >> n;

        map<string, set<string>> latinToEnglish;

        for (int i = 0; i < n; i++) {
            string englishWord, description;
            cin >> englishWord;
            cin.ignore();
            getline(cin, description);
            
            // извлечение переводов и отделение их на отдельные слова
            string translation = description.substr(2); // пропуск символов не относящихся к словам
            vector<string> translations;
            size_t pos = translation.find(", ");
            while (pos != string::npos) {
                translations.push_back(translation.substr(0, pos));
                translation = translation.substr(pos + 2);
                pos = translation.find(", ");
            }
            translations.push_back(translation);
            
            
            for (const string& word : translations) {
                latinToEnglish[word].insert(englishWord);
            }
        }

        // вывод  словаря
        cout << latinToEnglish.size() << endl;
        for (const auto& entry : latinToEnglish) {
            cout << entry.first << " - ";
            vector<string> englishWords(entry.second.begin(), entry.second.end());
            sort(englishWords.begin(), englishWords.end());
            for (size_t i = 0; i < englishWords.size(); i++) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << englishWords[i];
            }
            cout << endl;
        }

    }
};

int main()
{
    Application application;
    application.run();
    return 0;
}