#ifndef ADDRESSBOOK_OPERATIONS_H
#define ADDRESSBOOK_OPERATIONS_H

#include "utils.h"
#include "../headers/student.h"

int addData(const Student *student);

int deleteData(const char *name);

int checkData(const char *name);

#endif //ADDRESSBOOK_OPERATIONS_H
