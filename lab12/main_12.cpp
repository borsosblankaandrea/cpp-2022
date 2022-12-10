#include <iostream>
#include "GraduationDao.h"
#include "GraduationDaoImpl.h"
#include "GraduationService.h"
#include "GraduationDaoImpl.h"
#include "GraduationServiceImpl.h"
#include "SettlementStatistics.h"
#include "SettlementStatisticImpl.h"

string subjects[]{"maths", "romanian", "hungarian"};
int numSubjects = sizeof(subjects) / sizeof(subjects[0]);

int main() {
//    // ADMIN
//    GraduationDao *dao = new GraduationDaoImpl();
//    dao->enrollStudents("names.txt");
//    cout << "Number of enrolled students: " << dao->numEnrolled() << endl;
//
//    for (int i = 0; i < numSubjects; ++i) {
//        dao->saveGradesForSubject(subjects[i], subjects[i] + ".txt");
//    }
//    dao->computeAverage();
//
////    cout << "Subject's averages: " << endl;
////    try {
////        for (int i = 0; i < numSubjects; ++i) {
////            cout << "\taverage(" << subjects[i] << "): " << dao->getAverageBySubject(subjects[i]) << endl;
////        }
////    }catch( domain_error& e){
////        cerr << e.what() << endl;
////    }
//
//
//    GraduationService *service = new GraduationServiceImpl(dao);
//    cout << "Individual results: " << endl;
//    int id = 0;
//    while (id != -1) {
//        cout << "Enter ID (-1 for EXIT): ";
//        cin >> id;
//        if (id == -1) {
//            break;
//        }
//        cout << "Student id=" << id << " results: " << endl;
//        try {
//            auto results = service->findById(id);
//            for_each(results.getGrades().begin(), results.getGrades().end(), [](const pair<string, double> &e) {
//                cout << "\t" << e.first << " : " << e.second << endl;
//            });
//        } catch (out_of_range &e) {
//            cerr << "Nem letezo ID: " << e.what() << endl;
//        }
//    }
//
//    delete service;
//    delete dao;

    SettlementStatistics *statistics = new SettlementStatisticImpl("telepulesek.csv");

    cout << "Num Settlements: " << statistics->numSettlements() << endl;
    cout << "Num County: " << statistics->numCounties() << endl;
    cout << "Num settlements by county: " << statistics->numSettlementsByCounty("MS") << endl;
    cout << "Find settlements by county: " << endl;
    vector<Settlement> vector1 = statistics->findSettlementsByCounty("MS") ;
    for( auto &item: vector1){
        cout <<"\t" << item << endl;
    }

    cout << "Find settlements by name: " << endl;
    vector<Settlement> vector2 = statistics->findSettlementsByName("Dobra") ;
    for( auto &item: vector2){
        cout <<"\t" << item << endl;
    }

    cout << "Find settlement by name and county: \n\t" << statistics->findSettlementsByNameAndCounty("Dobra","MS")<<endl;

    cout << "Max population: \n\t" << statistics->maxPopulationDensity() << endl;
    cout << "Min population: \n\t" << statistics->minPopulationDensity() << endl;
    return 0;
}