#include <iostream>
#include <vector>
#include <string.h>
#include <utility>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <random>

using namespace std;

int main() {
    /// 1. feladat
    cout << "1. feladat: " << endl;

    vector <string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    string what = "berry";

    auto result1 = find_if(fruits.begin(), fruits.end(), [&what](const string& e){
       return e.contains(what);
    });

    cout << "\tResult1: " << *result1 << endl;

    /// 2. feladat
    cout << "2. feladat: " << endl;

    vector<int> v = {1,2,3,4,5};
//    for_each(v.begin(), v.end(), [](const int& e){
//        cout << e << ' ';
//    });
//    cout << endl;

    cout << "\t";
    generate(v.begin(), v.end(), [n = 0] () mutable { return n+=2; });
    for_each(v.begin(), v.end(), [](const int& e){
        cout << e << ' ';
    });
    cout << endl;

    auto result2 = all_of(v.begin(), v.end(), [](const int& e){
        return e%2 == 0;
    });

    cout << "\t" << (result2 ? "Mind paros" : "Nem mind paros") << endl;


    /// 3. feladat
    cout << "3. feladat: " << endl << "\t";

    for_each(v.begin(), v.end(), [](int& e){
        e+=e;
    });

    for_each(v.begin(), v.end(), [](const int& e){
        cout << e << ' ';
    });
    cout << endl;

    /// 4. feladat
    cout << "4.feladat: " << endl ;

    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    auto result4 = count_if(months.begin(), months.end(), [](const string& e){
        return e.length() == 5;
    });

    cout << "\tResult4: " << result4 << endl;

    /// 5. feladat
    cout << "5. feladat: " << endl;
    vector <double> v2 = {1, 2.5, 4.1, 6};

    // lambda kifejezessel
    sort(v2.begin(), v2.end(), [](double a, double b){
        return a > b;
    });

    cout << "\tLambda: ";
    for_each(v2.begin(), v2.end(), [](const double& e){
        cout << e << ' ';
    });

    // greater<>
    sort(v2.begin(), v2.end(), greater<double>());
    cout << "\n\tGreater: ";
    for_each(v2.begin(), v2.end(), [](const double& e){
        cout << e << ' ';
    });

    /// 6. feladat
    cout << endl << "6. feladat: " << endl;

    vector<pair<string, double>>temperature{
        {"January", 9}, {"February", -4}, {"March", 10}, {"April", 16}, {"May", 18},
        {"June", 23}, {"July", 31}, {"August", 28}, {"September", 17}, {"October", 11}, {"November", 7}, {"December", 1}
    };

//    for_each(temperature.begin(), temperature.end(), [](const pair<string,double>& e){
//        cout << "\t" << e.first << ' ' << e.second << endl;
//    });
//    cout << endl;

    sort(temperature.begin(), temperature.end(), [](pair<string,double> a, pair<string,double> b){
        return a.second < b.second;
    });

    cout <<"\tRendezve homerseklet szerint novekvo sorrendbe: " << endl;
    for_each(temperature.begin(), temperature.end(), [](const pair<string,double>& e){
        cout << "\t" << e.first << ' ' << e.second << endl;
    });

    /// 7. feladat
    cout << "7. feladat: \n\t";
    vector <double> v7 = {-4.2 ,1, 2.5, 4.1, 6};

    sort(v7.begin(), v7.end(), [](double a, double b){
        return abs(a) < abs(b);
    });

    cout << "Abszolut ertek szerint rendezve: ";
    for_each(v7.begin(), v7.end(), [](const double& e){
        cout << e << ' ';
    });

    /// 8. feladat
    cout << "\n8. feladat: \n";

//    for_each(months.begin(), months.end(), [](const string e){
//        cout << "\t" << e << endl;
//    });

    cout << "\tA honapok atirva kisbetusre: \n";
//    for_each(months.begin(), months.end(), [](string e){
//        transform(e.cbegin(), e.cend(), e.begin(), [](unsigned char c){
//            return tolower(c);
//        });
//        cout << "\t" << e << endl; /// ha kulon iratom ki, nem marad kisbetusen
//    });

    for_each(months.begin(), months.end(), [](string &e){
                 e[0] = tolower(e[0]);
             });

    for_each(months.begin(), months.end(), []( string e){
        cout << "\t" << e << endl;
    });

    /// 9. feladat
    cout << "9. feladat: \n\t";

    vector<char> alphabet{
            'a','b','c','d','e','f',
            'g','h','i','j','k','l','m','n','o','p',
            'q','r','s','t','u','v','w','x','y','z'
    };

    shuffle(alphabet.begin(), alphabet.end(), mt19937(random_device()()));

    cout << "Az abc megkeverve: ";
    for_each(alphabet.begin(),alphabet.end(), [](const char e){
       cout << e << ' ';
    });

    sort(months.begin(),months.end(),[alphabet](const auto &month1, const auto &month2){
        return distance(alphabet.begin(), find(alphabet.begin(),alphabet.end(), month1[0])) < distance(alphabet.begin(), find(alphabet.begin(),alphabet.end(), month2[0]));
    });

    cout << "\n\tA honapok a kevert abc szerint rendezve:\n";
    for_each(months.begin(), months.end(), []( string e){
        cout << "\t" << e << endl;
    });
}