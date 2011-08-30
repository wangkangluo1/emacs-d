class YourClass  
  def initialize(var = 0)  
    @var = var  
  end  
  def yourFunction(yourParameter)  
    print "#{@var}: #{yourParameter}"  
    @var += 1  
  end  
end  
obj = YourClass.new(2)  
obj.yourFunction "hello\n"  
obj.yourFunction "ruby class\n"  

