def prob1(str,n)
    puts str*n
end 

def prob2(str)
    if str.start_with?("if") 
        puts "true"
    else 
        puts "false"
    end
end

def prob3(str)
    print str[-1] << str[1...-1]  << str [0]
end 

def prob4(str)
    last_ch= str.length() -1 
    # print str.split('')[last_ch]
    print  str.split('')[last_ch] + str + str.split('')[last_ch];
end     

def prob6(nums)
   print rotated = nums[1], nums[2], nums[0];
end

def bouns1(nums,target)
    for i in 0..nums.length() -1
        j=i+1
        for j in j..nums.length() -1 
            if nums[j]==target - nums[i] 
                puts i,j 
            end
        end
    end
end


def prob7(nums)
    sum = 0
    i = 0
    while i < nums.length
            if(nums[i] == 17)
             i= i + 1
         else
                sum = sum + nums[i]
         end
         i += 1
     end
        return sum
 end


# prob1('a',1)
# prob1('a',2)
# prob1('a',3)
# prob1('a',4)
# prob1('a',5)
#  prob2("ifghhb")
#  prob2("mmm")
# prob3 ("python")
# prob3 ("java")
# prob4("abc")
# prob4("abcd")
# prob4("java")

# problem 5
# year = [2012, 1500, 1600, 2020]
# year.each do |y|
#     if y % 400 == 0
#   	 puts y.to_s + ' is leap year'
#     elsif y % 4==0 && y % 100 != 0 
#       puts y.to_s + ' is leap year'
#     else  puts y.to_s + ' is not leap year'
#   end
# end

# arr=[1,2,5]
#  print arr.rotate!

# prob6([1, 2, 5])
# prob6([1, 2, 3])
# prob6([1, 2, 4])

# bouns1([3,2,4],6)
# bouns1([2,7,11,15],9)

print prob7([3, 5, 17, 6])