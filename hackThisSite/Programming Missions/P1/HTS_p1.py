import os
import re
import copy



fp_dict = open("/home/fury/py_code/HTS_p1/data/wordlist.txt","r")
fp_ana = open("/home/fury/py_code/HTS_p1/data/anagrams.txt","r")
solutions=''
#get anagrams into a buffer
anagrams_default=[]
for line in fp_ana:
	line=re.sub(r'[\t\n ]*','',line)
	if len(line)!=0:
		anagrams_default.append(line)
anagrams=copy.copy(anagrams_default)

#iterate anagrams
for i,ana in enumerate(anagrams):
	for word in fp_dict:
		ana=copy.copy(anagrams_default[i])
		ana=re.sub(r'[\t\n ]*','',ana)
		word=re.sub(r'[\t\n ]*','',word)
		length=len(ana)
		for c in word:
			if c in ana:
				ana=ana.replace(c,'',1)
				length-=1
		if length==0 and len(anagrams_default[i])==len(word):
			solutions+=word+','
			break;				
	fp_dict.seek(0)
		
	
solutions=re.sub(r'\n','',solutions)
print("\n\n" + solutions[:-1])
		
fp_dict.close()			
fp_ana.close()


