#ifndef ADDRESSBOOK_OPERATIONS_H
#define ADDRESSBOOK_OPERATIONS_H

#include "utils.h"

int addData(const char *name, const char *number);

void deleteData(const char *name);

int checkData(const char *name);

#endif //ADDRESSBOOK_OPERATIONS_H
