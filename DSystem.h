#pragma once
#include "Multiplex.h"

#define machine_infinity 100

namespace DSystem {
	typedef unsigned short int sUInt;
	typedef unsigned int UInt;

	struct elem_base_cell {
		int element;
		UInt ID;
		elem_base_cell* next;
		elem_base_cell* priv;
	};

	class main_elem_base {
	public:
		main_elem_base(sUInt);
		~main_elem_base();
		void add_elem_toTail(int);
		void add_elem(UInt,int);
		elem_base_cell* get_ElemByID(UInt);
		sUInt get_NumOfElems();
		void del_elem_FromTail();
		void del_elem(UInt);
	private:
		void correct_ElemsID();
		sUInt num_of_elems;
		elem_base_cell* Head;
		elem_base_cell* Tail;
	};

	class phase_space: public multiplex {
	public:
		phase_space(sUInt);

	private:
	};

	class main_ds {
	public:	
		main_ds(std::string,sUInt,sUInt);
		main_elem_base MEB;
	private:
		std::string name;
		phase_space main_ps;
		sUInt state;
	};


};