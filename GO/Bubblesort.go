
func BubbleSort( items []int) {  
  
	L:=len(items)  
	 
	for i:=0;i<L;i++{  
	 
	for j:=0;j< (L-1-i);j++{  
	if items[j] > items[j+1]{  
	items[j], items[j+1] = items[j+1], items[j]  
	}  
	}  
	}  
	 
   } 
   