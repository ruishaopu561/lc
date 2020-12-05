#ifndef _RESUME_
#define _RESUME_

#include <iostream>
#include <string>

class ProtoResume
{
public:
    ProtoResume(){};
    ~ProtoResume(){};
    virtual ProtoResume *clone() = 0;
};

class WorkExperience
{
public:
    WorkExperience(){};
    ~WorkExperience(){};
    std::string getWorkDate();
    std::string getCompany();
    void setWorkDate(std::string _workDate);
    void setCompany(std::string _company);
private:
    std::string workDate;
    std::string company;
};

std::string WorkExperience::getWorkDate(){
    return workDate;
}

std::string WorkExperience::getCompany(){
    return company;
}

void WorkExperience::setWorkDate(std::string _workDate){
    workDate = _workDate;
}

void WorkExperience::setCompany(std::string _company){
    company = _company;
}

class Resume : public ProtoResume
{
private:
    std::string name;
    std::string sex;
    std::string age;

    WorkExperience work;
public:
    Resume(std::string _name);
    ~Resume(){};
    void setPersonalInfo(std::string _sex, std::string _age);
    void setWorkExperience(std::string timeArea, std::string _company);
    void display();
    virtual ProtoResume *clone();
};

Resume::Resume(std::string _name)
{
    name = _name;
}

void Resume::setPersonalInfo(std::string _sex, std::string _age)
{
    sex = _sex;
    age = _age;
}

void Resume::setWorkExperience(std::string _timeArea, std::string _company)
{
    work.setWorkDate(_timeArea);
    work.setCompany(_company);
}

void Resume::display()
{
    std::cout << "Basic Info: " << std::endl;
    std::cout << "{0} " << name << std::endl;
    std::cout << "{1} " << sex << std::endl;
    std::cout << "{2} " << age << std::endl;
    std::cout << "work Experience: " << std::endl;
    std::cout << "{0} " << work.getWorkDate() << std::endl;
    std::cout << "{1} " << work.getCompany() << std::endl;
}

ProtoResume *Resume::clone()
{
    return new Resume(*this);
}

#endif /*_RESUME_*/
