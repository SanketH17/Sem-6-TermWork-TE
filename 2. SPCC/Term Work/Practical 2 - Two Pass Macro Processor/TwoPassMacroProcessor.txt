"""
MACRO
INCR
mover areg one
mover breg two
add areg breg
MEND
MACRO
DNL
mover creg one
mover dreg two
div creg dreg
MEND
MACRO
INCR1
mover areg one
mover breg two
mult areg breg
MEND
START 200
MOVER AREG FIRST
ADD AREG SECOND
MOVEM AREG RESULT
INCR
PRINT RESULT
RESULT DS 1
FIRST DC 5
INCR1
SECOND DC 7
INCR
DNL
END
"""

fp = open('program3.txt', 'r')
program = fp.read().split('\n')

print('\nGiven Assembly Code\n')
for line in program:
    print(line)
    
fp.close()

fp = open('program3.txt', 'r')
program = fp.read().split('MEND\n')
fp.close()

mnt = [] #empty list
mdt = {} # empty dict

for line in program:
    line.strip() # remove begining and trailing white spaces
    a = line.split('\n')
    if a[0] == 'MACRO':
        #print ('Macro name is - ', a[1])
        mnt.append(a[1])
        #print('Macro Instructions are - ', a[2:])
        mdt[a[1]] = a[2:len(a)-1]
    else:
        prog = a 
        
print('\nContent of MNT\n-')
for each_mn in mnt:
    print(each_mn)
    
print('\nContent of MDT-\n')
for k, v in mdt.items():
    for command in v:
        print(command)
        
print('\nAfter Macro Expansion\n')


for line in prog:
    identify_mc = line.split()
    for word in identify_mc:
        if word in mnt:
            value = mdt[word]
            for i in value:
                print(i)
        else:
            print(word, '', end = '')
            

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        


























