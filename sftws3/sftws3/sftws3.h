#ifndef SFTWS3_H
#define SFTWS3_H


struct Customer {
    char firstName[15];
    char lastName[15];
    char streetAddress[20];
    char city[15];
    char province[15];
    char postalCode[10];
};

void setData(struct Customer* customer);
int checkString(char* string);
int postIsValid(char* tempPostal);
int stringIsValid(char* tempString);
#endif 