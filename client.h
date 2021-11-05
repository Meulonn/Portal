#ifndef CLIENT_H
#define CLIENT_H

class date
{ public: int d,m,y;};

class Client
{private:
    long client_cin;
    char* name;
    long phone_num;
    date birthday;
    int gender;
    char* email;
  public:
    Client();
    Client(long ,char*,long,date,int,char*);
    long get_cin();void set_cin(long);
    char* get_name();void set_name(char*);
    long get_num();void set_num(long);
    date get_birthday();void set_birthday(date);
    int get_gender();void set_gender(int);
    char* get_email();void set_email(char*);

   void view_client(Client);
   void update_client(Client*);
   void delete_client(Client*);
   void view_purchaseHistory(Client);
   void classify_client(Client);
   Client research_client(Client);
   void notify_about_delivery(Client);


};

#endif // CLIENT_H
