t = input()
flag = 0
if 'P' in t:
    if '12' in t:
        flag = 0
    else:
        flag = 1
elif 'A'  in t:
    if '12' in t:
        flag = 1
    else:
        flag = 0
else:
    pass

hh = int(t[:2])
mm = int(t[3:5])
ss = int(t[6:8])
if flag == 1:
    hh += 12
elif flag == 0:
    pass
else:
    pass


if hh < 10:
    hh = '0'+str(hh)
elif hh == 24:
    hh = '00'
else:
    hh = str(hh)

if mm < 10:
    mm = '0'+str(mm)
else:
    mm = str(mm)

if ss < 10:
    ss = '0'+str(ss)
else:
    ss = str(ss)

time = hh+':'+mm+':'+ss

print(time)
