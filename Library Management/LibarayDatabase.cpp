#include "LibarayDatabase.h"
#include <type_traits>
using namespace std;

void LibarayDatabase::addLibrarian(Librarian data)
{
	librarians.push_back(data);
}

void LibarayDatabase::addMembers(Member data)
{
	members.push_back(data);
}
