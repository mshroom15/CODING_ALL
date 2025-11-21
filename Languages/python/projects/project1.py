strng = "this is a strig"
revstring =strng[::-1]
print(revstring)
part_revstring = strng[3::-1]
print(part_revstring)
upper_strng = strng.upper()
print(upper_strng)
lower_strng = upper_strng.lower()
print(lower_strng)
title_strng = strng.title()
print(title_strng)
split_strng = strng.split()
print(split_strng)
join_strng = ','.join(split_strng)
print(join_strng)
find_substr = strng.find("is")
print(find_substr)
replace_strng = strng.replace("strig", "string")        

print(replace_strng)