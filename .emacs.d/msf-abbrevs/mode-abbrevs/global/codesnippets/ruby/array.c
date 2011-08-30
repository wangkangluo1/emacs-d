arr1 = ["ele1", 2, "ele3"]  
arr2 = ["ele4", arr1]  
arr3 = arr1 + arr2  
print "#{arr1.size} #{arr1[-1]}\n"  
print "#{arr2.size} #{arr2[arr2.size - 1][-1]}\n"  
print "#{arr3.size} #{arr3[4][2]}\n"  

