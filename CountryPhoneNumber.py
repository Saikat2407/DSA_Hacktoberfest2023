import phonenumbers
from test import *
number1 = "+918082833860"
number2 = "+380636125414"
number3 = "+966556542269"
number4 = "+918374174194"
number5 = "+917655246238"
number6 = "+918082196367"

from phonenumbers import geocoder
ch_number1 = phonenumbers.parse(number1, "CH")
ch_number2 = phonenumbers.parse(number2, "CH")
ch_number3 = phonenumbers.parse(number3, "CH")
ch_number4 = phonenumbers.parse(number4, "CH")
ch_number5 = phonenumbers.parse(number5, "CH")
ch_number6 = phonenumbers.parse(number6, "CH")

from phonenumbers import carrier
service_number1 = phonenumbers.parse(number1, "RO")
service_number2 = phonenumbers.parse(number2, "RO")
service_number3 = phonenumbers.parse(number3, "RO")
service_number4 = phonenumbers.parse(number4, "RO")
service_number5 = phonenumbers.parse(number5, "RO")
service_number6 = phonenumbers.parse(number6, "RO")

print(geocoder.description_for_number(ch_number1, "en"))
print(carrier.name_for_number(service_number1, "en"))
print()

print(geocoder.description_for_number(ch_number2, "en"))
print(carrier.name_for_number(service_number2, "en"))
print()

print(geocoder.description_for_number(ch_number3, "en"))
print(carrier.name_for_number(service_number3, "en"))
print()

print(geocoder.description_for_number(ch_number4, "en"))
print(carrier.name_for_number(service_number4, "en"))
print()

print(geocoder.description_for_number(ch_number5, "en"))
print(carrier.name_for_number(service_number5, "en"))
print()

print(geocoder.description_for_number(ch_number6, "en"))
print(carrier.name_for_number(service_number6, "en"))
print()
