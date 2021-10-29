#ifndef AGENT_H
#define AGENT_H
#include<QString>

class agent
{
public:
    void setname(QString n);
    void setsurname(QString n);
    void setcin(QString n);
    void setadmissiondate(QString n);
    void setnumberofabsences(QString n);
    void setadress(QString n);
    void setposition(QString n);
    void setsalary(QString n);
    void setemail(QString n);
    QString get_name();
    QString get_surname();
    QString get_cin();
    QString get_admissiondate();
    QString get_numberofabsences();
    QString get_adress();
    QString get_position();
    QString get_salary();
    QString get_email();


    agent();
private:
     QString name,surname,cin,admission_date,number_of_absences,adress,position,salary,email;


};

#endif // AGENT_H
