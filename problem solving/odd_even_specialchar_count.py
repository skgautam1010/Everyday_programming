
'''You are given a string containing at least 1 special character, 1 odd digit, and 1 even digit. We need to count the number of special characters in the string. Based on the parity of count ( ODD/EVEN ) we need to generate the output string.
–> If count is odd, we need to arrange odd and even digits alternatively starting with odd digit first.
–> If count is even, we need to arrange even and odd digits alternatively starting with even digit first.
–> Append the remaining odd/even digits the end

Keep in mind the relative order of odd and even digit should remain the same.




For example – for input string “@2$1347%”, there are 3 special characters, 2 even digits, and 3 odd digit.
so the output string will be – “12347” (Beginning with odd as count is odd).'''


str=input()
l=len(str)
even=""
odd=""
result=""
count=0
for i in range(0,l):
	if str[i].isnumeric():
		if(int(str[i])%2==0):
			even +=str[i]
		else:
			odd +=str[i]
	else:
		count +=1

sorted(even)
sorted(odd)
m=len(even)
n=len(odd)
if count%2==0:
	i=0
	while(m>0 and n>0):
		result +=even[i]
		result +=odd[i]
		i +=1
		m -=1
		n -=1
	while m>0:
		result +=even[i]
		m -=1
		i +=1
	while n>0:
		result +=odd[i]
		n -=1
		i +=1
else:
	i=0
	while m>0 and n>0:
		result +=odd[i]
		result +=even[i]
		i +=1
		m -=1
		n -=1
	while m>0:
		result +=even[i]
		i +=1
		m -=1
	while n>0:
		result +=odd[i]
		i +=1
		n -=1
print(result)
