#ifndef ADDRESSBOOK_OPERATIONS_H
#define ADDRESSBOOK_OPERATIONS_H

#include "utils.h"
#include "../headers/student.h"

int addData(const Student *student);

int deleteData(const char *name);

int isDataExist(const char *name);

int isBlankFile();

#endif //ADDRESSBOOK_OPERATIONS_H
