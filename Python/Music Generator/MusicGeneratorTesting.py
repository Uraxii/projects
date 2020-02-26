import random


ThirtySecond = {'Name': "ThirtySecond", 'Seconds': 32, 'Value': 0.125}
Sixteenth = {'Name': "Sixteenth", 'Seconds': 16, 'Value': 0.25}
Eighth = {'Name': "Eighth", 'Seconds': 8, 'Value': 0.5}
Fourth = {'Name': "Fourth", 'Seconds': 4, 'Value': 1}
Half = {'Name': "Half", 'Seconds': 2, 'Value': 2}
Whole = {'Name': "Whole", 'Seconds': 1, 'Value': 4}

Notes = [ThirtySecond,Sixteenth,Eighth,Fourth,Half,Whole]

SubDiv,Beats = map(int,input("Enter a time signature (ex. 4:4): ").split(":"))
BPM = int(input("Enter a BPM: "))
print ("Subdivision:",SubDiv,"Beats:",Beats, "BPM:",BPM)
BPS = (60/BPM)

i = 0
while i < len(Notes):
    if 'Seconds' in Notes[i]:
        Notes[i]['Seconds'] = BPS*(Beats/Notes[i]['Seconds'])
        Notes[i]['Value'] = (Beats*Notes[i]['Value'])
        print(Notes[i].get('Name'),",",Notes[i]['Seconds'],"Seconds,","Value:",Notes[i]['Value'])
    i+=1


Total = Whole['Value']
Bar = []
KillSwitch = 0
Dead = False
print("Total:",Total)
while Total > 0:
    RandNote = random.choice(Notes)
    #print("Total:",Total,"RandNote:", RandNote['Name'])

    if 'Value' in RandNote:
        if RandNote['Value'] <= Total:
            Bar.append(RandNote)
            Total=Total-RandNote['Value']
            #print("NoteTotal:",Total)
        else:
            KillSwitch+=1

    if KillSwitch > 4:
        print ("DEAD")
        Dead = True
        break
    LastNote = RandNote

print("Bar:",Bar)
print (Total)