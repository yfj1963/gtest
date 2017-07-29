import os,re
tt = []
imsilist = []
imsiDict = {}
f = open ('e:\\up1','r') 
txt = f.readlines()
flen = len(txt)
print(flen)
#print(txt)
for i in range(flen):
    matchObj1 = re.match('tIMSI', str(txt[i]), flags = 0)
    if matchObj1 != None:
        tt.append(txt[i])

print (len(tt))

for imsi in range(460119990021000,460119990021999):
    for j in range(len(tt)):
        matchObj2= re.search(str(imsi),str(tt[j]),re.M|re.I)
        if matchObj2 !=None:
            imsilist.append(imsi)

print (len(imsilist))
#print (imsilist)

for imsi in imsilist:
    if imsi in imsiDict:
        imsiDict[imsi] += 1
    else:
        imsiDict[imsi] = 1

print (len(imsiDict))
#print (imsiDict)
