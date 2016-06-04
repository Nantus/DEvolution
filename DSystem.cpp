#include <string>
#include <stdlib.h>
#include "DSystem.h"
#include "Multiplex.h"

namespace DSystem {

	main_elem_base::main_elem_base(sUInt arg_num_of_elems) {
		Head = new elem_base_cell;
		Tail = new elem_base_cell;
		Head->priv = NULL;
		Head->next = Tail;
		Head->ID   = 0;
		Tail->priv = Head;
		Tail->next = NULL;
		Tail->ID   = 1;
		num_of_elems = 2;
		while (num_of_elems < arg_num_of_elems)
			add_elem_toTail(NULL);
	}

	phase_space::phase_space(sUInt argNDim): space(argNDim,machine_infinity) {
	}

	main_ds::main_ds(std::string name_arg = "Default", sUInt ph_DimSpase_arg = 2, sUInt meb_num_of_elems = 0) : main_ps(ph_DimSpase_arg),MEB(meb_num_of_elems) {
		name = name_arg;
	}

	void main_elem_base::correct_ElemsID() {
		elem_base_cell* temp = Head;
		for (int i(0);i < num_of_elems;i++)
		{
			if (temp->ID != i)
				temp->ID = i;
			temp = temp->next;
		}
	}

	sUInt main_elem_base::get_NumOfElems() {
		return num_of_elems;
	}

	elem_base_cell* main_elem_base::get_ElemByID(UInt arg_ID) {
		if (arg_ID >= Tail->ID)
			return Tail;
		elem_base_cell* temp(Head);
		while (temp->ID != arg_ID) 
			temp = temp->next;
		return temp;
	}

	void main_elem_base::add_elem(UInt arg_ID,int arg_Elem) {
		elem_base_cell* privAddElem;
		elem_base_cell* temp;
		elem_base_cell* new_pElem = new elem_base_cell;
		new_pElem->element = arg_Elem;
		privAddElem = get_ElemByID(arg_ID);
		temp = privAddElem->next;
		new_pElem->priv = privAddElem;
		new_pElem->next = temp;
		privAddElem->next = new_pElem;
		num_of_elems += 1;
		correct_ElemsID();
	}

	void main_elem_base::add_elem_toTail(int arg_Elem) {
		elem_base_cell* temp;
		elem_base_cell* new_pElem = new elem_base_cell;
		new_pElem->element = arg_Elem;
		temp = Tail;
		Tail = new_pElem;
		temp->next = Tail;
		Tail->next = NULL;
		Tail->priv = temp;
		Tail->ID = temp->ID + 1;
		num_of_elems += 1;
	}

	void main_elem_base::del_elem_FromTail() {
		elem_base_cell* temp;
		temp = Tail;
		Tail = Tail->priv;
		Tail->next = NULL;
		delete temp;
		num_of_elems -= 1;
		correct_ElemsID();
	}

	void main_elem_base::del_elem(UInt arg_ID) {
		elem_base_cell* temp;
		if (arg_ID != 0) 
		{
			temp = get_ElemByID(arg_ID);
			temp->priv->next = temp->next;
			delete temp;
		}
		else
		{
			temp = Head;
			Head = Head->next;
			delete temp;
			Head->priv = NULL;
		}
		num_of_elems -= 1;
		correct_ElemsID();
	}
};