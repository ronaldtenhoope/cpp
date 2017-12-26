#include <stdlib.h>
#include <string.h>
#include "columnstore.h"

// ################################################
// #
// # The storage class contains one stored element 
// # It's part of an element
// #
// ################################################

cs_storage::cs_storage(void *i_data, int size) {
	_data=(void*) malloc(size);
	memcpy(_data, i_data, size);
	_next=NULL;
};

cs_storage::~cs_storage(void) {
	free(_data);
};

cs_storage *cs_storage::next(void) {
	return _next;
};

cs_storage *cs_storage::last(void) {
	cs_storage *nextElement=_next, *curElement=this;
	while (nextElement!=NULL) {
		curElement=nextElement;
		nextElement=nextElement->_next;
	}
	return curElement;
	
};

int cs_storage::setNext(cs_storage *i_next) {
	if (_next==NULL) {
		_next=i_next;
		return 0; 
	} else {
		return 1;
	}
};
		
// ################################################
// #
// # The element class contains an element with
// # a list of elements.
// # It's part of a container
// #
// ################################################

cs_element::cs_element(const char *i_name) {
	_name=(char*) malloc(strlen(i_name)+1);
	strcpy(_name, i_name);
	_next=NULL;
}

cs_element::~cs_element(void) {
	free(_name);
}

char *cs_element::name(void) {
	return _name;
}

int cs_element::setNext(cs_element *i_next) {
	if (_next==NULL) {
		_next=i_next;
		return 0; 
	} else {
		return 1;
	}
}

cs_element *cs_element::next(void) {
	return _next;
}

cs_element *cs_element::last(void) {
	cs_element *nextElement=_next, *curElement=this;
	while (nextElement!=NULL) {
		curElement=nextElement;
		nextElement=nextElement->_next;
	}
	return curElement;
}

// ################################################
// #
// # The container class contains elements 
// #
// ################################################

cs_container::cs_container(const char *i_name) {
	_name=(char*) malloc(strlen(i_name)+1);
	strcpy(_name, i_name);
	_element, _curelement=NULL;
}

cs_container::~cs_container(void) {
	cs_element *curElement, *nextElement = _element;
	while (nextElement!=NULL) {
		curElement=nextElement;
		nextElement=nextElement->next();
		free(curElement);
	}
	free(_name);
}

char *cs_container::name(void) {
	return _name;
}

int cs_container::addElement(const char *i_name) {
	cs_element *newElement, *curElement;
	newElement = new cs_element(i_name);
	if (_element!=NULL) {
		curElement=_element->last();
		curElement->setNext(newElement); 
	} else {
		_element=newElement;
	};
	return 1;
}

int cs_container::deleteElement(const char *i_name) {
}

cs_element *cs_container::curElement(void) {
	return _curelement;
}

cs_element *cs_container::firstElement(void) {
	_curelement=_element;
	return _curelement;
}

cs_element *cs_container::nextElement(void) {
	if (_curelement!=NULL) {
		_curelement=_curelement->next();
	}
	return _curelement;
}

