# 99Z-KH5-OEM-240-1.1
# QGG-V33-OEM-0B1-1.1
# Z93-Z29-OEM-BNX-1.1
# IQ0-PZI-OEM-PK0-1.1
# UM4-VDL-OEM-B9O-1.1
# L0S-4R2-OEM-UQL-1.1
# JBL-EYQ-OEM-ABB-1.1
# NL1-3V3-OEM-L4C-1.1
# 7CQ-1ZR-OEM-U3I-1.1
# XX0-IHL-OEM-5XK-1.1
# KJQ-RXG-OEM-TW8-1.1
# OZR-LW1-OEM-5EM-1.1
# 0B8-6K5-OEM-EFN-1.1
# OE2-20L-OEM-SSI-1.1
# 0ME-HAE-OEM-9XB-1.1

import string
import hashlib

def main():
    chars=list(string.ascii_uppercase + string.digits)
    hex=list(string.digits + 'A' + 'B' + 'C' + 'D' + 'E' + 'F')

    input=raw_input("Enter hash:\n>>")
    input_list=input.split(' ')

def get_md5_hash(str_in):
    hash_engine=hashlib.md5()
    hash_engine.update(str(str_in))
    digest = hash_engine.hexdigest()
    return digest

#assuming sample serial numbers are a represenative sample...
#we can narrow unknown space
# "???-???-OEM-???-1.1\n"
def known_chars(index):
    i=index%20

    if i is 3 or i is 7 or i is 11 or i is 15:
        return "-"
    elif i is 16 or i is 18:
        return "1"
    elif i is 8:
        return "O"
    elif i is 9:
        return "E"
    elif i is 10:
        return "M"
    elif i is 17:
        return "."
    elif i is 19:
        return "\n"
    else:
        return "0"

def base16_sum(input):
    input_list=list(input)
    sum = 0
    for item in input_list:
        sum+=int(item,16) #compute in base 16
    return sum

def total(msg,pass,prev,iter):
    if iter==0:
        intTotal=ord(str(msg)[0:1]-int(input_list[iter])+int(pass,16)
        return intTotal
    else:
        return Sum(str(MD5_Hash(msg[:(iter+1)]))[0:16]+str(MD5_Hash(prev))[0:16]

def find():
    for j in range(len(hex)):
        for i in range(len(chars)):
            if(((ord(chars[i])+int(hex[j],16)-Total(characters[i], hex[j],0,0)== int(input_list[0]))):
                total= Total(chars[i],hex[j],Total(chars[i],hex[j],0,0),1)
                if getHash(chars[i],1,str(hex[j]),total) != "0"):
                    return 1
    return 0


if __name__ == "__main__":
    main()