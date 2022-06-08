# -*- coding: utf-8 -*-
"""
Created on Mon Mar 21 04:44:50 2022

@author: COMPUTER
"""

import re
ep = list()
fp = open("3.txt","r")
cfg = dict()
global non_terminal
def find_first(key):
    value = cfg[key]
    if('#'in value):
        value.remove('#')
    for item in value:
        if item[0] in ep:
            epsilon(item)
        else:
            if(item[0].islower()):
                if item[0] not in temp:
                    temp.append(item[0])
            else:
                find_first(item[0])
                
def epsilon(item):
    find_first(item[0])
    length = len(item)
    i=1
    while(i<=length-1):
        if item[i] in ep:
            find_first(item[i])
            i=i+1
            if(i==length):
                if '#' not in temp:
                    temp.append('#')
                break
        else:
            if(item[i].islower()):
                if item[i] not in temp:
                    temp.append('#')
                break
            else:
                find_first(item[i])
                break
def find_follow(key):
    for k,v in cfg.items():
        for item in v:
            if re.search(key,item):
                index = item.find(key)
                length = len(item)-1
                
                if (index==length):
                    temp1=follow[k]
                    for i in temp1:
                        temp.append(i)
                        
                index = index+1
                for i in range(index,len(item)):
                    if(item[i].islower()):
                        temp.append(item[i])
                        break
                    else:
                        temp1=first[item[i]]
                        for j in temp1:
                            if (j!='#'):
                                temp.append(j)
                                if('#' in temp1):
                                    i=i+1
                                else:
                                    break
                            if(i==len(item)):
                                temp1=follow[k]
                                for j in temp1:
                                    temp.append(j)
                                    
for line in fp:
    line.strip()
    if re.search('\n',line):
        line=line[:line.find('\n')]
    split=line.split('->')
    split=split[1].split('|')
    i=0
    for item in split:
        split[i]=item.strip()
        i=i+1
    cfg[line[0]]=split
print("\n Given Context Free Grammar is = ")

for key,value in cfg.items():
    print(key,"->",value)
    if('#'in value):
        ep.append(key)
        
temp=list()
first=dict()
for key,value in cfg.items():
    first[key]=[]
    non_terminal=key
    find_first(key)
    if key in ep:
        if'#' not in temp:
            temp.append('#')
    for item in temp:
        first[non_terminal].append(item)
    temp.clear()
            
follow=dict()
flag=0
temp=list()

for key,value in cfg.items():
    follow[key]=[]
    if flag==0:
        temp.append('$')
        flag=1
    find_follow(key)
    for k in temp:
        if(k not in follow[key]):
            follow[key].append(k)
    temp.clear()
            
            
print("Non Terminal     First()                   follow()")
print("-----------------------------------------------------")
        
for key,value in follow.items():
    print("    ",key,"          ",first[key],"    ",value)
    print("\n")
        
        
        
        