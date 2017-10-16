import pyscreenshot as ImageGrab
from PIL import Image
import PIL
import os
#BUG: Some puzzles are yielding distances greater then 256 which 
#causes chr() to throw an exception. Works on most puzzles
if os.path.exists("screenshot.png"):
	os.remove('screenshot.png')
ASCII_DICT = {'A': '.-',     'B': '-...',   'C': '-.-.', 
	'D': '-..',    'E': '.',      'F': '..-.',
	'G': '--.',    'H': '....',   'I': '..',
	'J': '.---',   'K': '-.-',    'L': '.-..',
	'M': '--',     'N': '-.',     'O': '---',
	'P': '.--.',   'Q': '--.-',   'R': '.-.',
	'S': '...',    'T': '-',      'U': '..-',
	'V': '...-',   'W': '.--',    'X': '-..-',
	'Y': '-.--',   'Z': '--..',
	'0': '-----',  '1': '.----',  '2': '..---',
	'3': '...--',  '4': '....-',  '5': '.....',
	'6': '-....',  '7': '--...',  '8': '---..',
	'9': '----.' 
	}
MORSE_DICT=dict((v,k) for (k,v) in ASCII_DICT.items())
#screencap image,store, and load
box=(1672,511,1772,541) #these numbers are system specific
im=ImageGrab.grab(box)
im.save('screenshot.png')
im=Image.open('screenshot.png')
px=im.load()
#################LOCKED, IF CHANGE, TEST MORE#####################
k=0
#parse image into a flat array, squish tuples into binary flags
flat_flags=[0 for x in range(3000)]
for j in range(0,30):
	for i in range(0,100):
		if px[i,j] == (255,255,255):
			flat_flags[k]=1
		else:
			flat_flags[k]=0
		k+=1
#########################################################################
#42 WHITE PIXELS

current=0
morse=["" for x in range(50)]
dist_index=0
for i,flag in enumerate(flat_flags):
	if flag is 1 and current is 0:
		current=i
		morse[dist_index]=chr(current)
		dist_index+=1			
	elif flag is 1:
		last=current
		current=i
		morse[dist_index]=chr(current-last)
		dist_index+=1

morse_letter=""
i=0
output=""
for j,code in enumerate(morse):
	if code is ' ':
		output+=MORSE_DICT[morse_letter]
		i+=1
		morse_letter=""
	else:
		morse_letter+=code
		
print(output)

