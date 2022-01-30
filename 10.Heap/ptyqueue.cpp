// --------------------------------------------------------------------
//
// 2020112377 ±è¹Î¼ö
//  Laboratory B, In-lab Exercise 1                       ptyqueue.cpp
//
//  (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

#include "ptyqueue.h"

template <class DT>
PtyQueue<DT>::PtyQueue(int maxNumber)
	:Heap<DT>(maxNumber)
{
	Heap<DT>::Heap(maxNumber);
}

template<class DT>
void PtyQueue<DT>::enqueue(const DT& newDataItem)
{
	Heap<DT>::insert(newDataItem);
}

template<class DT>
DT PtyQueue<DT>::dequeue()
{
	return Heap<DT>::removeMax();
}