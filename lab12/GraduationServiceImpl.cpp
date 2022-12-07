//
// Created by ASUS on 2022. 12. 07..
//

#include "GraduationServiceImpl.h"

Student GraduationServiceImpl::findById(int id) const {
    return dao->findById(id);
}

double GraduationServiceImpl::getResultByIdAndSubject(int id, const string &subject) const {
    auto student = dao->findById(id);
    return student.getGrades().at(subject);
}

GraduationServiceImpl::GraduationServiceImpl(GraduationDao *dao): dao(dao) {}
