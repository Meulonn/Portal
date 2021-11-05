#include "client.h"

Client::Client()
{
client_cin=0;
phone_num=0;
gender=0;
}

Client:: Client(long client_cin,char* name,long phone_num,date birthday,int gender,char* email)
{
    this->client_cin=client_cin;
    this->name=name;
    this->phone_num=phone_num;
    this->birthday=birthday;
    this->gender=gender;
    this->email=email;
}
long Client:: get_cin(){return client_cin;}
void Client::set_cin(long client_cin){this->client_cin=client_cin;}
char* Client::get_name(){return name;}
void Client::set_name(char* name){this->name=name;}
long Client::get_num(){return phone_num;}
void Client::set_num(long phone_num){this->phone_num=phone_num;}
date Client::get_birthday(){return birthday;}
void Client::set_birthday(date birthday){this->birthday=birthday;}
int Client::get_gender(){return gender;}
void Client::set_gender(int gender){this->gender=gender;}
char* Client::get_email(){return email;}
void Client::set_email(char* email){this->email=email;}

void Client::view_client(Client);
void Client:: update_client(Client*);
void Client::delete_client(Client*);
void Client::view_purchaseHistory(Client);
void Client::classify_client(Client);
Client Client:research_client(Client);
void Client::notify_about_delivery(Client);
