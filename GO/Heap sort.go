
  
func heapify(items []int, idx int, size int) {  
	l := 2*idx + 1 // left = 2*i + 1  
	r := 2*idx + 2 // right = 2*i + 2  
   
	var largest int;  
	if l <= size && items[l] > items[idx] {  
	   largest = l  
	} else {  
	   largest = idx  
	}  
   
	if r <= size && items[r] > items[largest] {  
	   largest = r  
	}  
   
	if largest != idx {  
	   t := items[idx]  
	   items[idx] = items[largest]  
	   items[largest] = t  
	   heapify(items, largest, size)  
	}  
   
 }  
   
 func HeapSort(items []int) {  
   
	L := len(items) //heap size  
	m := int(L / 2) //middle  
   
	for i := m; i >= 0; i-- {  
   
	   heapify(items, i, L-1)  
	}  
   
	F := L - 1  
	for j := F; j >= 0; j-- {  
	   t := items[0]  
	   items[0] = items[j]  
	   items[j] = t  
	   F -= 1  
	   heapify(items, 0, F)  
	}  
   
 }  
 
 
 