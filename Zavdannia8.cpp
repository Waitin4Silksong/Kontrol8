#include <iostream>
#include <cstring>
#include "Tasks.h"


int main() {
	Tasks tasks;

	tasks.addProd();
	tasks.deleteProd("Milk");
	tasks.sortBy();
	tasks.searchImpDate("10.12.2023");
}

