var = 100
if var < 60  
  print "failed\n"  
elsif var < 70  
  print "passed\n"  
elsif var < 80  
  print "good\n"  
elsif var < 90  
  print "great\n"  
else  
  print "excellent\n"  
end  
case var  
  when 0..59 then print "failed\n"  
  when 60..69 then print "passed\n"  
  when 70..79 then print "good\n"  
  when 80..89 then print "grea\n"  
  else print "excellen\n"  
end 
