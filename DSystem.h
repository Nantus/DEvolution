#pragma once

namespace DSystem {
	typedef unsigned short int sUInt;
	typedef unsigned int UInt;

	struct elem_base_cell {
		void* element;
		UInt ID;
		elem_base_cell* next;
		elem_base_cell* priv;
	};

	class main_elem_base {
	public:
		main_elem_base(sUInt);
		void add_elem_toTail(void*);
		void add_elem(UInt,void*);
		void del_elem_FromTail();
		void del_elem(UInt);
	private:
		void correct_ElemsID();
		elem_base_cell* get_ElemByID(UInt);
		sUInt num_of_elems;
		elem_base_cell* Head;
		elem_base_cell* Tail;
	};

	class phase_space {
	public:
		phase_space(sUInt);
	private:
		sUInt dimentionsN;
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