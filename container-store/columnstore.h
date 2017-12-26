#include <stdlib.h>
#include <string.h>

class cs_storage {
private:
	void *_data;
	cs_storage *_next;
public:
	cs_storage(void *i_data, int size);
	~cs_storage(void);
	cs_storage *next(void);
	cs_storage *last(void);
	int setNext(cs_storage *i_next);
};

class cs_element {
private:
	char *_name;
	cs_element *_next;
public:
	// Constructor and destructor
	cs_element(const char *i_name);
	~cs_element(void);
	// Members
	char* name(void);
	cs_element *next(void);
	cs_element *last(void);
	int setNext(cs_element *i_next);
};

class cs_container {
private:
	char *_name;
	cs_element *_element, *_curelement;
public:
	// Constructor and destructor
	cs_container(const char *i_name);
	~cs_container(void);
	// Members
	char* name(void); 
	int addElement(const char *i_name);
	int deleteElement(const char *i_name);
	cs_element *curElement(void);
	cs_element *firstElement(void);
	cs_element *nextElement(void);
};
