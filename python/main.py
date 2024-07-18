import datetime
import json


print(datetime.date(2024, 2, 1))

# string methods practice

name = "Nathan"

# get given number of string
print(name[1:2])
print(name[:2])
print(name[0:-1])
print(name[::])
print(name[::2])

#using json in python

my_dic = {}
my_dic["Nathan"] = {
    "location": "Nairobi Ke",
    "Age": 40
}

json_dic = json.dumps(my_dic)

print(json_dic)